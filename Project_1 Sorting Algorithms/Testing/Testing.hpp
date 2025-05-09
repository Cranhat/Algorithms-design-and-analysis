#pragma once

#include <string>
#include <functional>
#include "../DataStructure/DataStructure.hpp"


class Testing{
    
    public:

    double test_time(DataStructure& object, std::function<void()> func);
    
    void save_to_csv(std::string saveFilePath, std::string key_name, std::string value_name, int keys[], double values[], int values_count);

    void test_sort_operation(std::string saveFilePath, std::string dataFilePath, DataStructure& object, int sizes[], int sizes_size,  int mean_of_operations, float fraction_already_sorted, bool reversed, std::string key_name, std::string value_name);

};