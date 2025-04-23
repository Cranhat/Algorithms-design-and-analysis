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

    myFile << key_name << ";" << value_name << "\n";

    for(int i = 0; i < values_count; i++){

        myFile << keys[i] << ";" << values[i]<< "\n" << std::setprecision(16);
        
    }

    myFile.close();

}

void Testing::test_sort_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, float fraction_already_sorted = 0, std::string key_name = "count", std::string value_name = "time"){
    double sum_of_time_elapsed = 0;
    double time_elapsed;
    int keys[number_of_measurements];
    double values[number_of_measurements];
    
    for(int j = 0; j < number_of_measurements; j++){

        sum_of_time_elapsed = 0;
        for(int i = 0; i < mean_of_operations ; i++){
            allocate_from_csv(object, dataFilePath, 1000 * (j + 1) * (j + 1));
            if (fraction_already_sorted){
                object.sort(0, fraction_already_sorted * object.getSize());
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

    save_to_csv(saveFilePath, key_name, value_name, keys, values, number_of_measurements);    
}

void Testing::test_sort_reversed_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int number_of_measurements, int mean_of_operations, float fraction_already_sorted = 0, std::string key_name = "count", std::string value_name = "time"){
    double sum_of_time_elapsed = 0;
    double time_elapsed;
    int keys[number_of_measurements];
    double values[number_of_measurements];
    
    for(int j = 0; j < number_of_measurements; j++){

        sum_of_time_elapsed = 0;
        for(int i = 0; i < mean_of_operations ; i++){
            allocate_from_csv(object, dataFilePath, 1000 * (j + 1) * (j + 1));
            object.sort(0, object.getSize());
            object.reverse();
            if (fraction_already_sorted){
                object.sort(0, fraction_already_sorted * object.getSize());
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

    save_to_csv(saveFilePath, key_name, value_name, keys, values, number_of_measurements);    
}
