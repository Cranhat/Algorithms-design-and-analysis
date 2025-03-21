#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <windows.h>
#include <unistd.h>

#include "Utilities/utilities.cpp"
#include "Testing/Testing.cpp"

#include "Bubble sort/Bubble sort.cpp"
#include "Heapsort/Heapsort.cpp"
#include "Merge sort/Merge sort.cpp"

using namespace std::literals;

int main(){
    int size = 1000;

    int** pointers_to_datasets = (int**) malloc(sizeof(int*) * 2);
    pointers_to_datasets[0] = create_randomized_list(size, size);
    pointers_to_datasets[1] = create_randomized_list(size, size);

    void (**pointers_to_algorithms)(int*, int) = (void (**)(int*, int)) malloc(sizeof(void (*)(int*, int)));
    pointers_to_algorithms[0] = (void (*)(int*, int)) &(bubble_sort);
    pointers_to_algorithms[1] = (void (*)(int*, int)) &(mergesort);


    Testing testingArrays(pointers_to_algorithms, pointers_to_datasets, size);

    double time_elapsed_1 = testingArrays.test_time(0, 0);
    printf("%f", time_elapsed_1);
    // double time_elapsed_2 = testingArrays.test_time(1, 0);
    
    // printf("First time elapsed: %f\tSecond time elapsed: %f\n", time_elapsed_1, time_elapsed_2);




    return 0;
}