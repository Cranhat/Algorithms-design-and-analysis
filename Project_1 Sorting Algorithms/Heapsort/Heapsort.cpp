#include "Heapsort.hpp"

void Heapsort::sort(int start, int end){
    heapsort(data, start, end);
}
void Heapsort::heapsort(int* list, int start_index, int end_index){
    for(int i = end_index/ 2 - 1; i >= 0; i--){
        heapify(list, end_index, i);
    }
    for (int i = end_index - 1; i >= 0; i--){
        swapItems_heapsort(list, i, 0);
        heapify(list, i, 0);
    }
}
void Heapsort::heapify(int* list, int size, int root){
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
        swapItems_heapsort(list, largest, root);
        heapify(list, size, largest);
    }
}

void Heapsort::swapItems_heapsort(int* list, int first_item_index, int second_item_index){
    int temp = list[first_item_index];
    list[first_item_index] = list[second_item_index];
    list[second_item_index] = temp;
}