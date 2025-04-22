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
#include "Heapsort/Heapsort.cpp"
#include "Mergesort/Mergesort.cpp"
#include "Quicksort/Quicksort.cpp"
#include "Introsort/Introsort.cpp"
#include "Insertionsort/Insertionsort.cpp"



int main(){
    std::string saveFilePath = "C:/Users/cypri/Projects/Algorithms-design-and-analysis/Project_1 Sorting Algorithms/Results/";
    std::string dataFilePath = "C:/Users/cypri/Projects/Algorithms-design-and-analysis/Project_1 Sorting Algorithms/Data/1.csv";

    Heapsort heapsort;
    Testing testing;
    int number_of_measurements = 30;
    int mean_of_operations = 1;
    testing.test_sort_operation(saveFilePath + "heapsort.csv", dataFilePath, heapsort, number_of_measurements, mean_of_operations);
    return 0;
}