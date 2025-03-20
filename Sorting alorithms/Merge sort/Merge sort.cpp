#include <iostream>
#include <stdlib.h>
#include "Merge sort.hpp"

void mergesort(int* list, int size){

    if (size <= 1) return;

    int mid = (int) size/2;
    int* arrayLeft = (int *) malloc(sizeof(int) * mid);
    int* arrayRight = (int *) malloc(sizeof(int) * (size - mid));
    
    for(int i = 0; i < mid; i++){
        arrayLeft[i] = list[i];
    }
    for(int i = 0; i < (size - mid); i++){
        arrayRight[i] = list[i + mid];
    }

    mergesort(arrayLeft, mid);
    mergesort(arrayRight, size - mid);

    merge(list, arrayLeft, arrayRight, mid, size - mid);

    free(arrayLeft); free(arrayRight);
}

void merge(int* list, int* arrayLeft, int* arrayRight, int sizeLeft, int sizeRight){

    int iLeft = 0, iRight = 0, i = 0;
    
    while (iLeft < sizeLeft && iRight < sizeRight){
        if (arrayLeft[iLeft] < arrayRight[iRight]){
            list[i++] = arrayLeft[iLeft++];
        }else{
            list[i++] = arrayRight[iRight++];
        }
    }
    
    while (iLeft < sizeLeft) list[i++] = arrayLeft[iLeft++];
    while (iRight < sizeRight) list[i++] = arrayRight[iRight++];
}