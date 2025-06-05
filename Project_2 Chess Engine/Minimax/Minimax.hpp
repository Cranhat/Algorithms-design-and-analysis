#pragma once
#include "../Engine/Engine.hpp"
#include <vector>

class Minimax : public Engine{
    public:
    double minimax(Figure** board, int depth, int maximizing_player);
    std::vector<int> piece_moves_index_available(unsigned int bitmask);   
};

