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
#include "Quicksort/Quicksort_v2.cpp"

using namespace std;
using namespace literals;


int main(){
    int size = 100;
    int** pointers_to_datasets = (int**) malloc(sizeof(int*) * 2);
    pointers_to_datasets[0] = create_randomized_list(size, size);
    pointers_to_datasets[1] = create_randomized_list(size, size * 2);

    void (**pointers_to_algorithms)(int*, int, int) = (void (**)(int*, int, int)) malloc(sizeof(void (*)(int*, int, int)) * 3);
    pointers_to_algorithms[0] = (void (*)(int*, int, int)) &(heapsort);
    pointers_to_algorithms[1] = (void (*)(int*, int, int)) &(quicksort);
    pointers_to_algorithms[2] = (void (*)(int*, int, int)) &(mergesort);
    

    Testing testingArrays(pointers_to_algorithms, pointers_to_datasets, 0, size);

    std::string saveFilePath;
    testingArrays.test_times(0, size, saveFilePath);
    testingArrays.test_times(1, size, saveFilePath);


    // int size = 21442;
    // int* lista = create_randomized_list(size, size * 2);

    // // heapsort(lista, size);

    // auto start = std::chrono::high_resolution_clock::now();

    // quicksort(lista, 0, size - 1);

    // auto end = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<double> duration = end - start;
    // double fp_seconds = duration / 1.01s;
    // printf("%f", fp_seconds);

    // printf("\n");

    // auto start_v2 = std::chrono::high_resolution_clock::now();

    // heapsort(lista, size - 1);

    // auto end_v2 = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<double> duration_v2 = end_v2 - start_v2;
    // double fp_seconds_v2 = duration_v2 / 1.01s;
    // printf("%f", fp_seconds_v2);

    
    


    return 0;
}