#include <stdlib.h>
#include "utilities.hpp"

int* create_randomized_list(int size, int max_value){
    int* lista = (int *) malloc(sizeof(int) * size);

    if (!lista) {

        printf("Memory allocation failed!\n");
        exit(1);

    }
    int randomNum;
    for (int i = 0; i < size; i++){

        randomNum = rand() % max_value;
        lista[i] = randomNum;

    }
    return lista;
}

void reverse_sorted_list(int* list, int size){
    for (int i = 0; i < size - 1; i++){

        std::swap(list[i], list[size - 1 - i]);
        
    }
}

void swap_items(int* list, int first_item_index, int second_item_index){
    int temp = list[first_item_index];
    list[first_item_index] = list[second_item_index];
    list[second_item_index] = temp;
}
