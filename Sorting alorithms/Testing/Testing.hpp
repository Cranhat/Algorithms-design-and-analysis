#pragma once
#include <string>
using namespace std;

class Testing{
    public:
    void (** pointers_to_algorithms)(int*, int, int); 
    int** pointers_to_datasets; // tested sizes must be equal
    int start_index, end_index;

    Testing(void (**pointers_to_algorithms)(int*, int, int), int** pointers_to_datasets, int start_index, int end_index){
        this -> pointers_to_algorithms = pointers_to_algorithms;
        this -> pointers_to_datasets = pointers_to_datasets;
        this -> start_index = start_index;
        this -> end_index = end_index;
    }

    void test_everyrthing();

    double test_time(int algorithm_index, int dataset_index, int start_index, int end_index);

    double test_times(int start_index, int end_index, string saveFilePath);

    double test_memory();

    double calculate_complexity();

    void compare_algorithms();
};