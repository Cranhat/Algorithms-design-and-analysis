// #pragma once
// #include <string>
// using namespace std;

// class Testing{
//     public:
//     void (** pointers_to_algorithms)(int*, int, int); 
//     int algorithm_count;
//     int** pointers_to_datasets;
//     int* pointers_to_dataset_sizes;
//     int datasets_count;

//     Testing(void (**pointers_to_algorithms)(int*, int, int), int algorithm_count, int** pointers_to_dataset_containers, int* pointers_to_dataset_sizes, int datasets_count){
        
//         this -> pointers_to_algorithms = pointers_to_algorithms;
//         this -> algorithm_count = algorithm_count;
//         this -> pointers_to_datasets = pointers_to_dataset_containers;
//         this -> pointers_to_dataset_sizes =  pointers_to_dataset_sizes;
//         this -> datasets_count = datasets_count;

//     }

//     void save_to_csv(string saveFilePath, int keys[], float values[]);

//     double test_time(int pointer_to_algorithm, int* pointer_to_dataset, int* pointer_to_dataset_size);

//     void test_times(string saveFilePath);

//     void test_times_dynamically_allocated(string saveFilePath, int initial_size, int datasets_count);

//     void test_times_dynamically_allocated_partially_sorted(string saveFilePath, int initial_size, int datasets_count, int percentage_sorted);

//     void test_times_dynamically_allocated_sorted_reversed(string saveFilePath, int initial_size, int datasets_count);    
// };