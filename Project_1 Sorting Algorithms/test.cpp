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
    std::string dataFilePath = "C:/Users/cypri/Projects/Algorithms-design-and-analysis/Project_1 Sorting Algorithms/Data/";

    // std::string saveFilePath = "C:/Users/Cyprian/Projects/Algorithms-design-and-analysis/Project_1 Sorting Algorithms/Results/";
    // std::string dataFilePath = "C:/Users/Cyprian/Projects/Algorithms-design-and-analysis/Project_1 Sorting Algorithms/Data/";

    Testing testing;

    Heapsort heapsort;
    Quicksort quicksort;
    Introsort introsort;


    // int number_of_measurements = 40; // 1 600 000
    int number_of_measurements = 20;
    int mean_of_operations = 1;
    
    testing.test_sort_operation(saveFilePath + "heapsort.csv", dataFilePath, heapsort, number_of_measurements, mean_of_operations);
    testing.test_sort_operation(saveFilePath + "quicksort.csv", dataFilePath, quicksort, number_of_measurements, mean_of_operations);
    testing.test_sort_operation(saveFilePath + "introsort.csv", dataFilePath, introsort, number_of_measurements, mean_of_operations);

    testing.test_sort_reversed_operation(saveFilePath + "heapsort reversed.csv", dataFilePath, heapsort, number_of_measurements, mean_of_operations);
    testing.test_sort_reversed_operation(saveFilePath + "quicksort reversed.csv", dataFilePath, quicksort, number_of_measurements, mean_of_operations);
    testing.test_sort_reversed_operation(saveFilePath + "introsort reversed.csv", dataFilePath, introsort, number_of_measurements, mean_of_operations);

    testing.test_sort_operation(saveFilePath + "heapsort 25\% already sorted.csv", dataFilePath, heapsort, number_of_measurements, mean_of_operations, 0.25);
    testing.test_sort_operation(saveFilePath + "quicksort 25\% already sorted.csv", dataFilePath, quicksort, number_of_measurements, mean_of_operations, 0.25);
    testing.test_sort_operation(saveFilePath + "introsort 25\% already sorted.csv", dataFilePath, introsort, number_of_measurements, mean_of_operations, 0.25);

    testing.test_sort_operation(saveFilePath + "heapsort 50\% already sorted.csv", dataFilePath, heapsort, number_of_measurements, mean_of_operations, 0.5);
    testing.test_sort_operation(saveFilePath + "quicksort 50\% already sorted.csv", dataFilePath, quicksort, number_of_measurements, mean_of_operations, 0.5);
    testing.test_sort_operation(saveFilePath + "introsort 50\% already sorted.csv", dataFilePath, introsort, number_of_measurements, mean_of_operations, 0.5);

    
    testing.test_sort_operation(saveFilePath + "heapsort 75\% already sorted.csv", dataFilePath, heapsort, number_of_measurements, mean_of_operations, 0.75);
    testing.test_sort_operation(saveFilePath + "quicksort 75\% already sorted.csv", dataFilePath, quicksort, number_of_measurements, mean_of_operations, 0.75);
    testing.test_sort_operation(saveFilePath + "introsort 75\% already sorted.csv", dataFilePath, introsort, number_of_measurements, mean_of_operations, 0.75);

    
    testing.test_sort_operation(saveFilePath + "heapsort 95\% already sorted.csv", dataFilePath, heapsort, number_of_measurements, mean_of_operations, 0.95);
    testing.test_sort_operation(saveFilePath + "quicksort 95\% already sorted.csv", dataFilePath, quicksort, number_of_measurements, mean_of_operations, 0.95);
    testing.test_sort_operation(saveFilePath + "introsort 95\% already sorted.csv", dataFilePath, introsort, number_of_measurements, mean_of_operations, 0.95);


    testing.test_sort_operation(saveFilePath + "heapsort 99\% already sorted.csv", dataFilePath, heapsort, number_of_measurements, mean_of_operations, 0.99);
    testing.test_sort_operation(saveFilePath + "quicksort 99\% already sorted.csv", dataFilePath, quicksort, number_of_measurements, mean_of_operations, 0.99);
    testing.test_sort_operation(saveFilePath + "introsort 99\% already sorted.csv", dataFilePath, introsort, number_of_measurements, mean_of_operations, 0.99);

    
    testing.test_sort_operation(saveFilePath + "heapsort 99.7\% already sorted.csv", dataFilePath, heapsort, number_of_measurements, mean_of_operations, 0.997);
    testing.test_sort_operation(saveFilePath + "quicksort 99.7\% already sorted.csv", dataFilePath, quicksort, number_of_measurements, mean_of_operations, 0.997);
    testing.test_sort_operation(saveFilePath + "introsort 99.7\% already sorted.csv", dataFilePath, introsort, number_of_measurements, mean_of_operations, 0.997);



    return 0;
}