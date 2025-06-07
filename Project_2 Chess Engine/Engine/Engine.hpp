#pragma once

#include "../MovePolicy/MovePolicy.hpp"
#include "../Pieces/Pieces.hpp"
#include "../Board/Board.hpp"

class Engine : public MovePolicy{
    protected:
    int late_game;
    int aggressiveness;
    
    public:

    std::vector<std::vector<int>> all_available_moves(Figure** board, int color);

    std::vector<int> show_available_moves(Figure** board, Figure* figure, int color);


};