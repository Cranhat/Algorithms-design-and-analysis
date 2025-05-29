#include "Utilities.hpp"

unsigned long long calculate_hex_val_by_index(int index){
    if (index < 0 || index > 63) {
        return 0xFF;  // Invalid
    }

    int row = index / 8;
    int col = index % 8;

    return (row << 4) | col; 
}