#pragma once

#include "../DynamicArray/DynamicArray.hpp"

class Bubblesort : public DynamicArray {
    
    public:
    
    void sort(int start, int end);

    void bubblesort(int* list, int size);

    using DynamicArray::DynamicArray;
    
};