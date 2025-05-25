#pragma once

#include "../MovePolicy/MovePolicy.hpp"
#include "../Pieces/Pieces.hpp"
#include "../Board/Board.hpp"

class Engine : public MovePolicy, public Board{
    public:

    unsigned long long* all_available_moves(int playing_color);

    unsigned long long show_available_moves(Figure* figure);

    float evaluate_position();

};