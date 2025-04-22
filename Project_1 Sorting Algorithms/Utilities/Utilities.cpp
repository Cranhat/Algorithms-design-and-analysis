#include <stdlib.h>
#include <fstream>

#include "Utilities.hpp"

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

void save_array_to_csv(std::string saveFilePath, int values[], int values_count){

    std::ofstream myFile;
    
    myFile.open(saveFilePath.c_str(), std::ios::out | std::ios::trunc);

    for(int i = 0; i < values_count; i++){

        myFile << values[i] << "\n";

    }

    myFile.close();
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

void allocate_from_csv(DataStructure& object, std::string FilePath, int size){

    std::ifstream myFile(FilePath.c_str(), std::ios::in);

    int number;
    int count = 0;

    object.clear();

    while (myFile >> number && count < size){

        object.addBack(number);
        count++;
        
    }

    myFile.close();
}