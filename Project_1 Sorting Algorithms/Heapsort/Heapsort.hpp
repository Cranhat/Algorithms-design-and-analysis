#pragma once

#include "../DynamicArray/DynamicArray.hpp"

class Heapsort : public DynamicArray {
    public:

    void sort();

    void heapsort(int* list, int start_index, int end_index);

    void heapify(int* list, int size, int root);

    void swapItems_heapsort(int* list, int first_item_index, int second_item_index);
};

