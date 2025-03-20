#include <stdlib.h>
#include <iostream>
#include "Utilities/utilities.cpp"
#include "Bubble sort/Bubble sort.cpp"
#include "Heapsort/Heapsort.cpp"
#include "Merge sort/Merge sort.cpp"

int main(){
    int size = 20;
    int* lista= create_randomized_list(size, size);

    for (int i = 0; i < size; i++){
        printf("%dth element = %d\n", i, lista[i]);
    }

    printf("\n");

    mergesort(lista, size);

    for (int i = 0; i < size; i++){
        printf("%dth element = %d\n", i, lista[i]);
    }
    return 0;
}