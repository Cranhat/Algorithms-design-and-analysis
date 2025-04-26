#include <iostream>
#include <cmath>

#include "Introsort.hpp"
#include "../Utilities/utilities.hpp"


void Introsort::sort(int start, int end){
    introsort(data, start, end, 2 * log(getSize()));
}

void Introsort::introsort(int* list, int start_index, int end_index, int depth){
    if ((end_index - start_index) < 16) insertionsort(data, start_index, end_index);

    else if (depth == 0){
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
        quicksort_depth_restricted(list, index_start, j, depth - 1);
    }
    if (i < index_end) {
        quicksort_depth_restricted(list, i, index_end, depth - 1);
    }
    
}

void Introsort::heapsort(int* list, int start_index, int end_index){
    int size = end_index - start_index + 1;
    for (int i = start_index + size/2 - 1; i >= start_index; i--){
        heapify(list, start_index, size, i);
    }
    for (int i = end_index; i > start_index; i--){
        swap_items(list, start_index, i);
        heapify(list, start_index, i - start_index, start_index);
    }
}

void Introsort::heapify(int* list, int base, int size, int root){
    int largest = root;
    int left = base + 2 * (root - base) + 1;
    int right = base + 2 * (root - base) + 2;

    if (left < base + size && list[left] > list[largest]){
        largest = left;
    }
    if (right < base + size && list[right] > list[largest]){
        largest = right;
    }
    if (largest != root){
        swap_items(list, largest, root);
        heapify(list, base, size, largest);
    }
}

void Introsort::insertionsort(int* list, int index_start, int index_end){
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