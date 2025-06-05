#pragma once

#include "KingCheckPolicy.hpp"
#include "../Board/Board.hpp"
#include "Masks.hpp"

class FigureMoves : public KingCheckPolicy, public Board{    

    public:

    unsigned long long available_horizontal_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    unsigned long long available_vertical_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    unsigned long long available_diagonal_up_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    unsigned long long available_diagonal_down_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    unsigned long long available_knight_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    unsigned long long available_up_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    unsigned long long available_down_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    bool simulate_and_check(int old_index, int new_index, int color, double* eval_ptr);

    unsigned long long calculate_new_mask(int new_index);

    void move(int old_index, int new_index);

    double evaluate_position();
    
    double get_additional_move_value(int index, int piece_type, int piecie_color);

};
