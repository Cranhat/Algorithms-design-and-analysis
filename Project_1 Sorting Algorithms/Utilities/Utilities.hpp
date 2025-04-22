#pragma once

#include <string>
#include "../DataStructure/DataStructure.hpp"

int* create_randomized_list(int min_value, int max_value, int size);

void save_array_to_csv(std::string saveFilePath, int values[], int values_count);

void reverse_sorted_list(int* list, int size);

void swap_items(int* list, int first_item_index, int second_item_index);

void allocate_from_csv(DataStructure& object, std::string FilePath, int size);
