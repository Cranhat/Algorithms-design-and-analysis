#pragma once

#include "Masks.hpp"
#include "../MovePolicy/MovePolicy.hpp"
#include "../Pieces/Pieces.hpp"
#include "../Board/Board.hpp"

class Engine : public MovePolicy{
    protected:
    int late_game;
    int aggressiveness;
    
    public:

    unsigned long long* all_available_moves(int color);

    unsigned long long show_available_moves(Figure* figure, int color);

    float evaluate_position();

    double get_additional_move_value(int index, int piece_type, int piecie_color);

};