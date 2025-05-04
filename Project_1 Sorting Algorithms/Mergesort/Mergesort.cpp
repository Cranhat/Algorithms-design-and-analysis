#include <iostream>
#include <stdlib.h>

#include "Mergesort.hpp"

void Mergesort::sort(int start, int end){

    mergesort(data, start, end);

}

void Mergesort::mergesort(int* list, int start_index, int end_index){

    if (end_index <= 1) return;

    int mid = (int) end_index/2;
    int* arrayLeft = (int *) malloc(sizeof(int) * mid);
    int* arrayRight = (int *) malloc(sizeof(int) * (end_index - mid));
    
    for(int i = 0; i < mid; i++){

        arrayLeft[i] = list[i];

    }
    for(int i = 0; i < (end_index - mid); i++){

        arrayRight[i] = list[i + mid];

    }

    mergesort(arrayLeft, 0, mid);
    mergesort(arrayRight, 0, end_index - mid);

    merge(list, arrayLeft, arrayRight, mid, end_index - mid);

    free(arrayLeft); free(arrayRight);

}



void Mergesort::merge(int* list, int* arrayLeft, int* arrayRight, int sizeLeft, int sizeRight){

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