#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <windows.h>
#include <unistd.h>
#include <string>

#include "Utilities/utilities.cpp"
#include "Testing/Testing.cpp"

#include "Bubble sort/Bubble sort.cpp"
#include "Heapsort/Heapsort.cpp"
#include "Merge sort/Merge sort.cpp"
#include "Quicksort/Quicksort.cpp"
#include "Introsort/Introsort.cpp"
#include "Insertion sort/Insertion sort.cpp"

using namespace std;
using namespace literals;


int main(){
    // int previous_size = 100;
    // int datasets_count = 12;
    
    // int** pointers_to_datasets = (int**) malloc(sizeof(int*) * datasets_count);
    // int* pointers_to_datasets_sizes = (int*) malloc(sizeof(int) * datasets_count);
    // for(int i = 0; i < datasets_count; i++){
    //     pointers_to_datasets[i] = create_randomized_list(previous_size, previous_size);
    //     pointers_to_datasets_sizes[i] = previous_size;
    //     previous_size = previous_size * 2;
    // }

    // void (**pointers_to_algorithms)(int*, int, int) = (void (**)(int*, int, int)) malloc(sizeof(void (*)(int*, int, int)) * 3);
    // int algorithms_count = 3;
    // pointers_to_algorithms[2] = (void (*)(int*, int, int)) &(heapsort);
    // pointers_to_algorithms[1] = (void (*)(int*, int, int)) &(quicksort);
    // pointers_to_algorithms[0] = (void (*)(int*, int, int)) &(mergesort);

    // Testing testingArrays(pointers_to_algorithms, algorithms_count, pointers_to_datasets, pointers_to_datasets_sizes, datasets_count);
    // string saveFilePath = "/Result";

    // printf("test_times_normally_allocated\n");

    // testingArrays.test_times(saveFilePath);

    // printf("test_times_dynamically_allocated\n");
    // string secondSaveFilePath = "/Result2";

    // testingArrays.test_times_dynamically_allocated(secondSaveFilePath, 100, datasets_count);

    // printf("test_times_dynamically_allocated_partially_sorted\n");
    // string thirdSaveFilePath = "/Result3";

    // testingArrays.test_times_dynamically_allocated_partially_sorted(thirdSaveFilePath, 100, datasets_count, 0.9);

    // printf("test_times_dynamically_allocated_sorted_reversed\n");
    // string fourthSaveFilePath = "/Result4";

    // testingArrays.test_times_dynamically_allocated_sorted_reversed(fourthSaveFilePath, 100, datasets_count);
    


    
    printf("end\n");
    int size = 100000;
    int* lista = create_randomized_list(size, size);

    // for(int i = 0; i < size; i++){
    //     printf("%dith = %d\n", i, lista[i]);
    // }

    printf("\n");

    auto start = std::chrono::high_resolution_clock::now();
    introsort(lista, 0, size, 32);
    // quicksort(lista, 0, size);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    
    double fp_seconds = duration / 1.00s;

    printf("time elapsed: %f\n", fp_seconds);

    // for(int i = 0; i < size; i++){
    //     printf("%dith = %d\n", i, lista[i]);
    // }

    return 0;
}