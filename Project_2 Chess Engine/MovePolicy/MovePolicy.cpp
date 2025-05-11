#include "MovePolicy.hpp"


unsigned long long MovePolicy::available_horizontal_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask){

    int counter = 0;
    unsigned long long  second_figure_mask = figure_mask;

    while(counter++ < scope && !(figure_mask & right_move_mask)){
    
        figure_mask >>= 1;
        if (figure_mask & teammate_mask){
            break;
        }
        else if (figure_mask & enemy_mask){
            moves_available |= figure_mask;
            break;
        }
        moves_available |= figure_mask;
    }

    counter = 0;
    while(counter++ < scope && !(second_figure_mask & left_move_mask)){
        second_figure_mask <<= 1;
        if (second_figure_mask & teammate_mask){
            break;
        }else if (second_figure_mask & enemy_mask){
            moves_available |= second_figure_mask;
            break;
        }
        moves_available |= second_figure_mask;
    }
    return moves_available;
}

unsigned long long MovePolicy::available_vertical_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask){

    int counter = 0;
    unsigned long long  second_figure_mask = figure_mask;
    
    while(counter++ < scope && !(figure_mask & down_move_mask)){
        figure_mask >>= 8;
        if (figure_mask & teammate_mask){
            break;
        }
        else if (figure_mask & enemy_mask){
            moves_available |= figure_mask;
            break;
        }
        moves_available |= figure_mask;
    }
    counter = 0;
    while(counter++ < scope && !(second_figure_mask & up_move_mask)){
        second_figure_mask <<= 8;
        if (second_figure_mask & teammate_mask){
            break;
        }
        else if (second_figure_mask & enemy_mask){
            moves_available |= second_figure_mask;
            break;
        }
        moves_available |= second_figure_mask;
    }

    return moves_available;
}

unsigned long long MovePolicy::available_diagonal_up_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask){

    int counter = 0;
    unsigned long long  second_figure_mask = figure_mask;
    
    while(counter++ < scope && !(figure_mask & diagonal_right_up_move_mask)){
        figure_mask <<= 7;
        if (figure_mask & teammate_mask){
            break;
        }else if (figure_mask & enemy_mask){
            moves_available |= figure_mask;
            break;
        }
        moves_available |= figure_mask;
    }
    counter = 0;
    while(counter++ < scope && !(second_figure_mask & diagonal_left_up_move_mask)){
        second_figure_mask <<= 9;
        if (second_figure_mask & teammate_mask){
            break;
        }else if (second_figure_mask & enemy_mask){
            moves_available |= second_figure_mask;
            break;
        }
        moves_available |= second_figure_mask;
    }

    return moves_available;
}

unsigned long long MovePolicy::available_diagonal_down_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask){

    int counter = 0;
    unsigned long long  second_figure_mask = figure_mask;
    
    while(counter++ < scope && !(figure_mask & diagonal_right_down_move_mask)){
        figure_mask >>= 9;
        if (figure_mask & teammate_mask){
            break;
        }else if (figure_mask & enemy_mask){
            moves_available |= figure_mask;
            break;
        }
        
        moves_available |= figure_mask;
    }
    counter = 0;
    while(counter++ < scope && !(second_figure_mask & diagonal_left_down_move_mask)){
        second_figure_mask >>= 7;
        if (second_figure_mask & teammate_mask){
            break;
        }else if (second_figure_mask & enemy_mask){
            moves_available |= second_figure_mask;
            break;
        }
        moves_available |= second_figure_mask;
    }

    return moves_available;
}