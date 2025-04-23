#pragma once

#include "../DynamicArray/DynamicArray.hpp"


class Insertionsort : public DynamicArray {
    public:

    void sort(int start, int end);

    void insertionsort(int* list, int index_start, int index_end);

    using DynamicArray::DynamicArray;
    
};
