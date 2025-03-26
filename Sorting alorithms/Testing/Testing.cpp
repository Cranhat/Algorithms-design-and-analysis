#include "Testing.hpp"
#include <stdlib.h>
#include <direct.h>
#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdio>
#include <string>
#include "../Utilities/utilities.cpp"
#include "../Quicksort/Quicksort.cpp"


typedef void (*FuncPtr)(int*, int, int);

using namespace std::literals;

void Testing::save_to_csv(string saveFilePath, int keys[], float values[]){
    ofstream myFile;
    myFile.open(saveFilePath.c_str(), std::ios::out | std::ios::trunc);

    myFile << saveFilePath << "\n";

    for(int i = 0; i < this -> datasets_count; i++){

        myFile << keys[i]<< ";"<< values[i]<< "\n";
    }
    myFile.close();
}

double Testing::test_time(int pointer_to_algorithm_index, int* pointer_to_datasets, int* pointer_to_dataset_size){
    FuncPtr algorithm = (FuncPtr) pointers_to_algorithms[pointer_to_algorithm_index];

    auto start = std::chrono::high_resolution_clock::now();

    algorithm(pointer_to_datasets, 0, *pointer_to_dataset_size);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    
    double fp_seconds = duration / 1.01s;
    
    return fp_seconds;
}

void Testing::test_times(string saveFilePath){
    string fileSavedAs;
    char cwd[1024];
    float** time_elapsed = new float*[algorithm_count];

    for(int i = 0; i < algorithm_count; i++){

        time_elapsed[i] = new float[datasets_count]; 

    }
    for(int i = 0; i < algorithm_count; i++){

        for(int j = 0; j < datasets_count; j++){

            time_elapsed[i][j] = test_time(i, pointers_to_datasets[j], &pointers_to_dataset_sizes[j]);

        }

        fileSavedAs = getcwd(cwd, sizeof(cwd)) + saveFilePath + "/algorithm" + std::to_string(i) + ".csv";
        save_to_csv(fileSavedAs, pointers_to_dataset_sizes, time_elapsed[i]);

    }
    for(int i = 0; i < algorithm_count; i++) {

        delete[] time_elapsed[i];

    }
    delete[] time_elapsed;
}   

void Testing::test_times_dynamically_allocated(string saveFilePath, int initial_size, int datasets_count){
    string fileSavedAs;
    char cwd[1024];
    float** time_elapsed = new float*[algorithm_count];
    int previous_size;
    int* pointers_to_dataset_sizes = new int[datasets_count];
    previous_size = initial_size;

    for(int i = 0; i < algorithm_count; i++){

        time_elapsed[i] = new float[datasets_count]; 

    }
    for(int j = 0; j < datasets_count; j++){

        for(int i = 0; i < algorithm_count; i++){
            
        int* pointer_to_dataset = new int[previous_size];

        pointer_to_dataset = create_randomized_list(previous_size, previous_size);

        time_elapsed[i][j] = test_time(i, pointer_to_dataset, &previous_size);

        free(pointer_to_dataset);

        }

        pointers_to_dataset_sizes[j] = previous_size;
        previous_size *=  2;

    }
    for(int i = 0; i < algorithm_count; i++){

        fileSavedAs = getcwd(cwd, sizeof(cwd)) + saveFilePath + "/algorithm" + std::to_string(i) + ".csv";
        save_to_csv(fileSavedAs, pointers_to_dataset_sizes, time_elapsed[i]);

    }
    for(int i = 0; i < algorithm_count; i++) {

        delete[] time_elapsed[i];

    }
    delete[] time_elapsed;
}

void Testing::test_times_dynamically_allocated_partially_sorted(string saveFilePath, int initial_size, int datasets_count, int percentage_sorted){
    string fileSavedAs;
    char cwd[1024];
    float** time_elapsed = new float*[algorithm_count];

    for(int i = 0; i < algorithm_count; i++){

        time_elapsed[i] = new float[datasets_count]; 

    }
    int previous_size;
    int* pointers_to_dataset_sizes = new int[datasets_count];
    previous_size = initial_size;

    for(int j = 0; j < datasets_count; j++){

        for(int i = 0; i < algorithm_count; i++){
            
            int* pointer_to_dataset = new int[previous_size];

            pointer_to_dataset = create_randomized_list(previous_size, previous_size);

            quicksort(pointer_to_dataset, 0, previous_size * percentage_sorted);

            time_elapsed[i][j] = test_time(i, pointer_to_dataset, &previous_size);

            free(pointer_to_dataset);
        }
        pointers_to_dataset_sizes[j] = previous_size;
        previous_size *=  2;
    }
    for(int i = 0; i < algorithm_count; i++){
        fileSavedAs = getcwd(cwd, sizeof(cwd)) + saveFilePath + "/algorithm" + std::to_string(i) + ".csv";
        save_to_csv(fileSavedAs, pointers_to_dataset_sizes, time_elapsed[i]);
    }
    for(int i = 0; i < algorithm_count; i++) {
        delete[] time_elapsed[i];
    }
    delete[] time_elapsed;
}

void Testing::test_times_dynamically_allocated_sorted_reversed(string saveFilePath, int initial_size, int datasets_count){
    string fileSavedAs;
    char cwd[1024];
    float** time_elapsed = new float*[algorithm_count];
    for(int i = 0; i < algorithm_count; i++){
        time_elapsed[i] = new float[datasets_count]; 
    }
    int previous_size;
    int* pointers_to_dataset_sizes = new int[datasets_count];
    previous_size = initial_size;

    for(int j = 0; j < datasets_count; j++){
        for(int i = 0; i < algorithm_count; i++){
            
        int* pointer_to_dataset = new int[previous_size];

        pointer_to_dataset = create_randomized_list(previous_size, previous_size);

        quicksort(pointer_to_dataset, 0, previous_size);
        reverse_sorted_list(pointer_to_dataset, previous_size);

        time_elapsed[i][j] = test_time(i, pointer_to_dataset, &previous_size);

        free(pointer_to_dataset);
        }
        pointers_to_dataset_sizes[j] = previous_size;
        previous_size *=  2;
    }
    for(int i = 0; i < algorithm_count; i++){
        fileSavedAs = getcwd(cwd, sizeof(cwd)) + saveFilePath + "/algorithm" + std::to_string(i) + ".csv";
        save_to_csv(fileSavedAs, pointers_to_dataset_sizes, time_elapsed[i]);
    }
    for(int i = 0; i < algorithm_count; i++) {
        delete[] time_elapsed[i];
    }
    delete[] time_elapsed;
}