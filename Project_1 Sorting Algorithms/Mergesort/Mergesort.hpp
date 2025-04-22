#pragma once

#include "../DataStructure/DataStructure.hpp"

class Mergesort : public DataStructure {
    public:

    void sort(int* list, int start_index, int end_index);

    void merge(int* list, int* arrayLeft, int* arrayRight, int sizeLeft, int sizeRight);

};
