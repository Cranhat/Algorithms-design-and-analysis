#include <iostream>
#include "Insertion sort/Insertion sort.cpp"

int main(){

    int lista[10] = {1, 2, 8, 5, 1, 2, 123, 88, 3, 10};

    for(int i = 0; i < 10; i++){
        printf("%dith = %d\n", i, lista[i]);
    }

    printf("\n");

    insertion_sort(lista, 0, 10);

    for(int i = 0; i < 10; i++){
        printf("%dith = %d\n", i, lista[i]);
    }

    return 0;
}