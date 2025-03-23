#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <windows.h>
#include <unistd.h>

#include "Utilities/utilities.cpp"
// #include "Testing/Testing.cpp"

#include "Bubble sort/Bubble sort.cpp"
#include "Heapsort/Heapsort.cpp"
#include "Merge sort/Merge sort.cpp"

#include "Quicksort/Quicksort.cpp"
#include "Quicksort/Quicksort_v2.cpp"

using namespace std::literals;

int main(){
    // 2147483647
    // int size = 21474836;
    int size = 8147483;
    int* lista = create_randomized_list(size, size);


    // int** pointers_to_datasets = (int**) malloc(sizeof(int*) * 2);
    // pointers_to_datasets[0] = create_randomized_list(size, size);
    // pointers_to_datasets[1] = create_randomized_list(size, size);

    // void (**pointers_to_algorithms)(int*, int) = (void (**)(int*, int)) malloc(sizeof(void (*)(int*, int)));
    // pointers_to_algorithms[0] = (void (*)(int*, int)) &(quicksort);
    // pointers_to_algorithms[1] = (void (*)(int*, int)) &(mergesort);


    // Testing testingArrays(pointers_to_algorithms, pointers_to_datasets, size);

    // double time_elapsed_1 = testingArrays.test_time(0, 0);
    // printf("%f\n", time_elapsed_1);
    // double time_elapsed_2 = testingArrays.test_time(1, 0);
    // printf("%f\n", time_elapsed_2);

    auto start = std::chrono::high_resolution_clock::now();

    quicksort_v2(lista, 0, size - 1);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    double fp_seconds = duration / 1.01s;
    printf("%f", fp_seconds);

    printf("\n");

    auto start_v2 = std::chrono::high_resolution_clock::now();

    mergesort(lista, size - 1, 0);

    auto end_v2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration_v2 = end_v2 - start_v2;
    double fp_seconds_v2 = duration_v2 / 1.01s;
    printf("%f", fp_seconds_v2);

    
    


    return 0;
}