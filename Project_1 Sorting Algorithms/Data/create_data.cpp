#include <iostream>
#include <string>

#include "../DataStructure/DataStructure.cpp"
#include "../Utilities/Utilities.cpp"


int main(){
    std::string saveFilePath = "C:/Users/cypri/Projects/Algorithms-design-and-analysis/Project_1 Sorting Algorithms/Data/";
    // std::string saveFilePath = "C:/Users/Cyprian/Projects/Algorithms-design-and-analysis/Project_1 Sorting Algorithms/Data/";
    int* list;
    int list_size = 2000000;
    for (int i = 0; i < 100; i++){
        list = create_randomized_list(list_size, list_size);

        save_array_to_csv(saveFilePath + std::to_string(i) + ".csv", list , list_size);
    }
    return 0;
}