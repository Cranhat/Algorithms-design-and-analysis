#pragma once
#include "../Engine/Engine.hpp"

class Minimax : public Engine{
    
    public:
    double minimax(Figure** board, int depth, int maximizing_player, double alpha, double beta);

    std::pair<int, int> get_best_move(Figure** board, int depth, int maximizing_player);

    // std::vector<std::pair<int, int>> get_best_moves(Figure** board, int depth, int maximizing_player);

    // double double_minmax_search(Figure** board, int depth, int maximizing_player, double alpha, double beta);
};
