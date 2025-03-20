#include <stdlib.h>

int* create_randomized_list(int size, int max_value){
    int* lista = (int *) malloc(sizeof(int) * size);
    int randomNum;
    for (int i = 0; i < size; i++){
        randomNum = rand() % max_value;
        lista[i] = randomNum;
    }
    return lista;
}