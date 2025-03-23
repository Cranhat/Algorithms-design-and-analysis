#include <iostream>
#include <stdlib.h>
#include "Quicksort_v2.hpp"
#include <unistd.h>

// It processes information just like my brain

void quicksort_v2(int* list, int index_start, int index_end) {
    if (index_start >= index_end) {
        return; 
    }
    int i = index_start;
    int j = index_start;

    find_pivot_v2(list, index_start, index_end);

    while (i < index_end) {
        if (list[i] <= list[index_end]) {
            swapItems_v2(list, j, i);
            j++;
        }
        i++;
    }
    
    swapItems_v2(list, j, index_end);

    if (j > index_start) {
        quicksort_v2(list, index_start, j - 1);
    }
    if (j + 1 < index_end) {
        quicksort_v2(list, j + 1, index_end);
    }
}

void find_pivot_v2(int* list, int start, int end){
    int size = end - start;
    int pivot_index;
    if (size > 3){
        if (list[0] > list[end] && list[0] < list[end - (int) size / 2]){
            pivot_index = 0;
        }
        else if (list[end - 1] > list[0] && list[end] < list[end - (int) size / 2]){
            pivot_index = end;
        }
        else if (list[end - (int) size / 2] > list[0] && list[end - (int) size / 2] < list[end]){
            pivot_index = end - (int) size / 2;
        }
    }else{
        pivot_index = end - (int) size / 2;
    }
    swapItems_v2(list, pivot_index, end);
}

void swapItems_v2(int* list, int first_item_index, int second_item_index){
    int temp = list[first_item_index];
    list[first_item_index] = list[second_item_index];
    list[second_item_index] = temp;
}
