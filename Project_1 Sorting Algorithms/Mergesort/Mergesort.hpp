#pragma once

#include "../DynamicArray/DynamicArray.hpp"

class Mergesort : public DynamicArray {
    public:

    void sort();

    void mergesort(int* list, int start_index, int end_index);

    void merge(int* list, int* arrayLeft, int* arrayRight, int sizeLeft, int sizeRight);

};
