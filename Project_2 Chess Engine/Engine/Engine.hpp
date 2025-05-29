#pragma once

#include "Masks.hpp"
#include "../MovePolicy/MovePolicy.hpp"
#include "../Pieces/Pieces.hpp"
#include "../Board/Board.hpp"

class Engine : public MovePolicy, public Board{
    protected:
    int late_game;
    int aggrevieness;
    
    public:

    unsigned long long* all_available_moves(int playing_color);

    unsigned long long show_available_moves(Figure* figure);

    float evaluate_position();

    void move(int start_position, int end_position, int move_mask);

    double get_additional_move_value(int index, int piece_type, int piecie_color);

};