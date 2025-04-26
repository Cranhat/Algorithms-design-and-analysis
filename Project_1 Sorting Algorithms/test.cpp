#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <windows.h>
#include <unistd.h>
#include <string>

#include "DynamicArray/DynamicArray.cpp"
#include "DataStructure/DataStructure.cpp"
#include "Testing/Testing.cpp"

#include "Bubblesort/Bubblesort.cpp"
#include "Mergesort/Mergesort.cpp"
#include "Quicksort/Quicksort.cpp"
#include "Introsort/Introsort.cpp"
#include "Insertionsort/Insertionsort.cpp"


int main(){

    // std::string saveFilePath = "C:/Users/cypri/Projects/Algorithms-design-and-analysis/Project_1 Sorting Algorithms/Results/";
    // std::string dataFilePath = "C:/Users/cypri/Projects/Algorithms-design-and-analysis/Project_1 Sorting Algorithms/Data/";

    std::string saveFilePath = "C:/Users/Cyprian/Projects/Algorithms-design-and-analysis/Project_1 Sorting Algorithms/Results/";
    std::string dataFilePath = "C:/Users/Cyprian/Projects/Algorithms-design-and-analysis/Project_1 Sorting Algorithms/Data/";

    Testing testing;

    Mergesort mergesort;
    Quicksort quicksort;
    Introsort introsort;


    int sizes[] = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 2000000};

    int mean_of_operations = 100;

    printf("1\n");
    testing.test_sort_operation(saveFilePath + "mergesort.csv", dataFilePath, mergesort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations);
    testing.test_sort_operation(saveFilePath + "quicksort.csv", dataFilePath, quicksort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations);
    testing.test_sort_operation(saveFilePath + "introsort.csv", dataFilePath, introsort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations);
    printf("2\n");
    testing.test_sort_operation(saveFilePath + "mergesort reversed.csv", dataFilePath, mergesort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 1, true);
    testing.test_sort_operation(saveFilePath + "quicksort reversed.csv", dataFilePath, quicksort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 1, true);
    testing.test_sort_operation(saveFilePath + "introsort reversed.csv", dataFilePath, introsort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 1, true);
    printf("3\n");
    testing.test_sort_operation(saveFilePath + "mergesort 25\% already sorted.csv", dataFilePath, mergesort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.25);
    testing.test_sort_operation(saveFilePath + "quicksort 25\% already sorted.csv", dataFilePath, quicksort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.25);
    testing.test_sort_operation(saveFilePath + "introsort 25\% already sorted.csv", dataFilePath, introsort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.25);
    printf("4\n");
    testing.test_sort_operation(saveFilePath + "mergesort 50\% already sorted.csv", dataFilePath, mergesort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.5);
    testing.test_sort_operation(saveFilePath + "quicksort 50\% already sorted.csv", dataFilePath, quicksort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.5);
    testing.test_sort_operation(saveFilePath + "introsort 50\% already sorted.csv", dataFilePath, introsort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.5);
    printf("5\n");
    testing.test_sort_operation(saveFilePath + "mergesort 75\% already sorted.csv", dataFilePath, mergesort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.75);
    testing.test_sort_operation(saveFilePath + "quicksort 75\% already sorted.csv", dataFilePath, quicksort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.75);
    testing.test_sort_operation(saveFilePath + "introsort 75\% already sorted.csv", dataFilePath, introsort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.75);
    printf("6\n");
    testing.test_sort_operation(saveFilePath + "mergesort 95\% already sorted.csv", dataFilePath, mergesort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.95);
    testing.test_sort_operation(saveFilePath + "quicksort 95\% already sorted.csv", dataFilePath, quicksort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.95);
    testing.test_sort_operation(saveFilePath + "introsort 95\% already sorted.csv", dataFilePath, introsort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.95);
    printf("7\n");
    testing.test_sort_operation(saveFilePath + "mergesort 99\% already sorted.csv", dataFilePath, mergesort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.99);
    testing.test_sort_operation(saveFilePath + "quicksort 99\% already sorted.csv", dataFilePath, quicksort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.99);
    testing.test_sort_operation(saveFilePath + "introsort 99\% already sorted.csv", dataFilePath, introsort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.99);
    printf("8\n");
    testing.test_sort_operation(saveFilePath + "mergesort 99.7\% already sorted.csv", dataFilePath, mergesort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.997);
    testing.test_sort_operation(saveFilePath + "quicksort 99.7\% already sorted.csv", dataFilePath, quicksort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.997);
    testing.test_sort_operation(saveFilePath + "introsort 99.7\% already sorted.csv", dataFilePath, introsort, sizes, sizeof(sizes)/sizeof(sizes[0]), mean_of_operations, 0.997);
    printf("9\n");


    return 0;
}