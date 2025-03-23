#include "Testing.hpp"
#include <stdlib.h>
#include <chrono>

typedef void (*FuncPtr)(int*, int);

using namespace std::literals;

double Testing::test_time(int algorithm_index, int dataset_index){
    FuncPtr algorithm = (FuncPtr) pointers_to_algorithms[algorithm_index];

    auto start = std::chrono::high_resolution_clock::now();

    algorithm(pointers_to_datasets[dataset_index], each_object_size);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    double fp_seconds = duration / 1.01s;
    
    return fp_seconds;
}

double Testing::test_memory(){
    return 1.1;
}

double Testing::calculate_complexity(){
    return 1.1;
}

void Testing::compare_algorithms(){
}