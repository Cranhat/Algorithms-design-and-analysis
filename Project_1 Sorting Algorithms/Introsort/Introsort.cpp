#include <iostream>
#include <cmath>

#include "Introsort.hpp"
#include "../Utilities/utilities.hpp"


void Introsort::sort(int start, int end){
    introsort(data, start, end, 3 * log(getSize()));
}

void Introsort::introsort(int* list, int start_index, int end_index, int depth){
    if ((end_index - start_index) < 16) return;

    if (depth == 0){
        heapsort(list, start_index, end_index);
    }
    quicksort_depth_restricted(list, start_index, end_index, depth);
}

void Introsort::quicksort_depth_restricted(int* list, int index_start, int index_end, int depth){
    if (index_start >= index_end) {
        return; 
    }
    int i = index_start;
    int j = index_end;
    int pivot = list[(index_start+index_end)/2];
    
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
        introsort(list, index_start, j, depth - 1);
    }
    if (i < index_end) {
        introsort(list, i, index_end, depth - 1);
    }
    
}

void Introsort::heapsort(int* list, int start_index, int end_index){
    for(int i = end_index/ 2 - 1; i >= 0; i--){
        heapify(list, end_index, i);
    }
    for (int i = end_index - 1; i >= 0; i--){
        swap_items(list, i, 0);
        heapify(list, i, 0);
    }
}

void Introsort::heapify(int* list, int size, int root){
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && list[left] > list[largest]){
        largest = left;
    }
    if (right < size && list[right] > list[largest]){
        largest = right;
    }
    if (largest != root){
        swap_items(list, largest, root);
        heapify(list, size, largest);
    }
}

void Introsort::introsort(int* list, int index_start, int index_end){
    int i = index_start;
    int j;
    while(i < index_end){
        j = i++;
        while(list[j - 1] > list[j] && j > 0){
            swap_items(list, j - 1, j);
            j--;
        }
    }
}