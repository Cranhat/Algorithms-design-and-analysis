#include "MovePolicy.hpp"


unsigned long long MovePolicy::available_horizontal_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask){

    int counter = 0;
    unsigned long long  second_figure_mask = figure_mask;

    while(counter++ < scope && !(figure_mask & righ_move_mask)){
        figure_mask >>= 1;
        moves_available |= figure_mask;
    }

    counter = 0;
    while(counter++ < scope && !(figure_mask & left_move_mask)){
        second_figure_mask <<= 1;
        moves_available |= second_figure_mask;
    }
    return moves_available;
}

unsigned long long MovePolicy::available_vertical_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask){

    int counter = 0;
    unsigned long long  second_figure_mask = figure_mask;
    
    while(counter++ < scope && !(figure_mask & up_move_mask)){
        figure_mask >>= 8;
        moves_available |= figure_mask;
    }
    counter = 0;
    while(counter++ < scope && !(second_figure_mask & down_move_mask)){
        second_figure_mask <<= 8;
        moves_available |= second_figure_mask;
    }

    return moves_available;
}

unsigned long long MovePolicy::available_diagonal_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask){
    return moves_available;
}