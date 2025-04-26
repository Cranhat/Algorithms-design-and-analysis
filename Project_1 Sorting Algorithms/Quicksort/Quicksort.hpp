#pragma once

#include "../DynamicArray/DynamicArray.hpp"

class Quicksort : public DynamicArray {
    public:

    void sort(int start, int end);

    void quicksort(int* list, int index_start, int index_end);

    int find_pivot(int* list, int start, int end);

    using DynamicArray::DynamicArray;
};
