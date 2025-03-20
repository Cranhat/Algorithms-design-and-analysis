#include <iostream>

#include "Bubble sort.hpp"

using namespace std;

void bubble_sort(int* list, int size){
    for(int i = 0; i < size - 1; i ++){
        for(int j = 0; j < size - i - 1; j++){
            if (list[j] > list[j + 1]){
                list[j] = list[j] + list[j + 1];
                list[j + 1] = list[j] - list[j + 1];
                list[j] = list[j] - list[j + 1];
            }
        }
    }
}

int main(){
    int size = 8;
    int* lista = (int *) malloc(sizeof(int) * size);
    int randomNum;

    for (int i = 0; i < size; i++){
        randomNum = rand() % 101;
        lista[i] = randomNum;
    }


    bubble_sort(lista, size);

    for (int i = 0; i < 8; i++){
        printf("%dth element = %d\n", i, lista[i]);
    }
    return 0;
}