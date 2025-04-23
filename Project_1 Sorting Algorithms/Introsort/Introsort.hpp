#pragma once

#include "../DynamicArray/DynamicArray.hpp"


class Introsort : public DynamicArray {

    public: 

    void sort(int start, int end);

    void introsort(int* list, int start_index, int end_index, int depth);

    void quicksort_depth_restricted(int* list, int index_start, int index_end, int depth);    
    
    void introsort(int* list, int index_start, int index_end);
    
    void heapify(int* list, int size, int root);
    
    void heapsort(int* list, int start_index, int end_index);
};
