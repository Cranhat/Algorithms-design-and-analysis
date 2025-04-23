#include <iostream>
#include <stdlib.h>
#include "Quicksort.hpp"


#include "../Utilities/utilities.hpp"


void Quicksort::sort(int start, int end){
    quicksort(data, start, end);
}

void Quicksort::quicksort(int* list, int index_start, int index_end){
    if (index_start >= index_end) {
        return; 
    }
    int i = index_start;
    int j = index_end;
    int pivot = list[(index_start+index_end)/2];
    int pivot_index = (index_end + index_start)/2;
    
    while (i <= j){
        while(list[i] < pivot){
            i++;
        }
        while(list[j] > pivot){
            j--;
        }
        if(i <= j){
            swap_items(list, i, j);
            i++;
            j--;
        }
        
    }
    if (j > index_start) {
        quicksort(list, index_start, j);
    }
    if (i < index_end) {
        quicksort(list, i, index_end);
    }
}

int Quicksort::find_pivot(int* list, int start, int end){
    int size = end - start;
    int pivot_index;
    if (size > 3){
        if (list[0] > list[end] && list[0] < list[end - size / 2]){
            pivot_index = 0;
        }
        else if (list[end - 1] > list[0] && list[end] < list[end - size / 2]){
            pivot_index = end;
        }
        else if (list[end - size / 2] > list[0] && list[end - size / 2] < list[end]){
            pivot_index = end -  size / 2;
        }
    }else{
        pivot_index = end -  size / 2;
    }
    return pivot_index;
}