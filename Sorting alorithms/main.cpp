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
    int datasets_count = 20;
    int previous_size = 100;

    int** pointers_to_datasets = (int**) malloc(sizeof(int*) * datasets_count);
    int* pointers_to_datasets_sizes = (int*) malloc(sizeof(int) * datasets_count);
    for(int i = 0; i < datasets_count; i++){
        pointers_to_datasets[i] = create_randomized_list(previous_size * 2, previous_size * 2);
        pointers_to_datasets_sizes[i] = previous_size * 2;
        previous_size = previous_size * 2;
    }
    

    void (**pointers_to_algorithms)(int*, int, int) = (void (**)(int*, int, int)) malloc(sizeof(void (*)(int*, int, int)) * 3);
    int algorithms_count = 3;
    pointers_to_algorithms[2] = (void (*)(int*, int, int)) &(heapsort);
    pointers_to_algorithms[1] = (void (*)(int*, int, int)) &(quicksort);
    pointers_to_algorithms[0] = (void (*)(int*, int, int)) &(mergesort);

    Testing testingArrays(pointers_to_algorithms, algorithms_count, pointers_to_datasets, pointers_to_datasets_sizes, datasets_count);
    std::string saveFilePath = "/Results";
    
    printf("main b\n");
    testingArrays.test_times(saveFilePath);
    printf("main c\n");
    return 0;
}