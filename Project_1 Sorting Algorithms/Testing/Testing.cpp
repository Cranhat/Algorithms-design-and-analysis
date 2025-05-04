#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <functional>
#include <iomanip>
#include <random>

#include "Testing.hpp"
#include "../DataStructure/DataStructure.hpp"
#include "../Utilities/Utilities.cpp"


double Testing::test_time(DataStructure& object, std::function<void()> func){

    auto start = std::chrono::high_resolution_clock::now();

    func();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::nano> duration = end - start;
    
    return duration.count(); 
}


void Testing::save_to_csv(std::string saveFilePath, std::string key_name, std::string value_name, int keys[], double values[], int values_count){

    std::ofstream myFile;

    myFile.open(saveFilePath.c_str(), std::ios::out | std::ios::trunc);

    if (!myFile.is_open()){

        printf("cannot open file!\n");

    }
    
    myFile << key_name << ";" << value_name << "\n";

    for(int i = 0; i < values_count; i++){

        myFile << keys[i] << ";" << values[i]<< "\n" << std::setprecision(16);
        
    }

    myFile.close();

}


void Testing::test_sort_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int sizes[], int sizes_size, int mean_of_operations, float fraction_already_sorted = 0, bool reversed = false, std::string key_name = "count", std::string value_name = "time"){
    
    double time_elapsed, sum_of_time_elapsed = 0;
    int keys[sizes_size]; double values[sizes_size];

    for(int j = 0; j < sizes_size; j++){

        sum_of_time_elapsed = 0;

        for(int i = 0; i < mean_of_operations ; i++){

            allocate_from_csv(object, dataFilePath + std::to_string(i) +  ".csv", sizes[j]);

            if (fraction_already_sorted){

                object.sort(0, fraction_already_sorted * object.getSize());

            }
            if (reversed) {

                object.reverse();

            }
            time_elapsed = test_time(object, [&object]() {

                object.sort(0, object.getSize());

            });
            sum_of_time_elapsed += time_elapsed;

        }
        sum_of_time_elapsed = sum_of_time_elapsed/mean_of_operations;
        keys[j] = object.getSize();
        values[j] = sum_of_time_elapsed;

    }
    save_to_csv(saveFilePath, key_name, value_name, keys, values, sizes_size);

}
