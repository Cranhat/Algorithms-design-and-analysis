#include "Insertionsort.hpp"
#include "../Utilities/utilities.hpp"

void Insertionsort::sort(int* list, int index_start, int index_end){
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
