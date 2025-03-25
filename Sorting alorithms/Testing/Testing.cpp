#include "Testing.hpp"
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <fstream>

#include <cstdio>
#include <string>

typedef void (*FuncPtr)(int*, int, int);

using namespace std::literals;

void Testing::save_to_csv(string saveFilePath, int keys[], float values[]){
    ofstream myFile(saveFilePath);
    for(int i = 0; i < this -> datasets_count; i++){
        myFile << saveFilePath;
        myFile << "\n";
        myFile << keys[i];
        myFile << ";";
        myFile << values[i];
        myFile << "\n";
    }
    myFile.close();
}
double Testing::test_time(int pointer_to_algorithm_index, int* pointer_to_datasets, int* pointer_to_dataset_size){
    // FuncPtr algorithm = (FuncPtr) pointer_to_algorithm;
    FuncPtr algorithm = (FuncPtr) pointers_to_algorithms[pointer_to_algorithm_index];

    auto start = std::chrono::high_resolution_clock::now();

    algorithm(pointer_to_datasets, 0, *pointer_to_dataset_size);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    double fp_seconds = duration / 1.01s;
    
    return fp_seconds;
}
void Testing::test_times(string saveFilePath){
    char fileSavedAs[50];
    float** time_elapsed = new float*[algorithm_count];
    for(int i = 0; i < algorithm_count; i++){
        time_elapsed[i] = new float[datasets_count]; 
    }
    for(int i = 0; i < algorithm_count; i++){
        for(int j = 0; j < datasets_count; j++){
        time_elapsed[i][j] = test_time(i, pointers_to_datasets[j], &pointers_to_dataset_sizes[j]);
        printf("time elapsed: %f\n", time_elapsed[i][j]);
        }
        // sprintf(fileSavedAs, "%s/algorithm%d.csv", saveFilePath, i);
        // save_to_csv(fileSavedAs, pointers_to_dataset_sizes, time_elapsed);
    }
}   