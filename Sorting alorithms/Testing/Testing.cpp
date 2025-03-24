#include "Testing.hpp"
#include <stdlib.h>
#include <iostream>
#include <chrono>

typedef void (*FuncPtr)(int*, int, int);


using namespace std::literals;

double Testing::test_time(int algorithm_index, int dataset_index, int start_index, int end_index){
    FuncPtr algorithm = (FuncPtr) pointers_to_algorithms[algorithm_index];

    auto start = std::chrono::high_resolution_clock::now();

    algorithm(pointers_to_datasets[dataset_index], start_index, end_index);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    double fp_seconds = duration / 1.01s;
    
    return fp_seconds;
}

double Testing::test_times(int start_index, int end_index, string saveFilePath){
    float time;
    int algorithm_count = sizeof(sizeof(this->pointers_to_algorithms)/sizeof(this->pointers_to_algorithms[0]));
    for(int i = 0; i <= algorithm_count; i++){
        time = test_time(i, 0, start_index, end_index);
        printf("time elapsed: %f\n", time);
    }
    return 1.1;
}

double Testing::test_memory(){
    return 1.1;
}

double Testing::calculate_complexity(){
    return 1.1;
}

void Testing::compare_algorithms(){
}