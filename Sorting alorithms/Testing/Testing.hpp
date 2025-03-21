#pragma once

class Testing{
    public:
    void (** pointers_to_algorithms)(int*, int); 
    int** pointers_to_datasets; // tested sizes must be equal
    int each_object_size;

    Testing(void (**pointers_to_algorithms)(int*, int), int** pointers_to_datasets, int each_object_size){
        this -> pointers_to_algorithms = pointers_to_algorithms;
        this -> pointers_to_datasets = pointers_to_datasets;
        this -> each_object_size = each_object_size;
    }

    void test_everyrthing();

    double test_time(int algorithm_index, int dataset_index);

    double test_memory();

    double calculate_complexity();

    void compare_algorithms();
};