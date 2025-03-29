#include <iostream>
#include <cmath>

#include "Introsort.hpp"
#include "../Utilities/utilities.hpp"
#include "../Insertion sort/Insertion sort.hpp"
#include "../Heapsort/Heapsort.hpp"
;
void introsort(int* list, int start_index, int end_index, int depth){
    if ((end_index - start_index) < 16) return;

    if (depth == 0){
        heapsort(list, start_index, end_index);
    }
    quicksort_depth_restricted(list, start_index, end_index, depth);
}

void quicksort_depth_restricted(int* list, int index_start, int index_end, int depth){
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