#include "FigureMoves.hpp"


unsigned long long FigureMoves::available_horizontal_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){

    Figure** temp_board = new Figure*[64];
    std::copy(board, board + 64, temp_board);

    int counter = 0, old_index, new_index;
    unsigned long long  second_figure_mask = figure_mask;

    while(counter++ < scope && !(figure_mask & left_move_mask)){
        std::cout << "1" << std::endl;
        old_index = __builtin_clzll(figure_mask);
        figure_mask <<= 1;
        new_index = __builtin_clzll(figure_mask);
        std::cout << "11" << std::endl;
        temp_board[new_index] = temp_board[old_index];
        temp_board[old_index] = nullptr;
        temp_board[new_index] -> mask = figure_mask;
        std::cout << "111" << std::endl;
        if (is_checked(temp_board , king_mask, teammate_mask, enemy_mask, color)){
            std::cout << "is is \n";
            continue;
        }
        std::cout << "1111" << std::endl;
        if (figure_mask & teammate_mask){
            break;
        }
        else if (figure_mask & enemy_mask){
            moves_available |= figure_mask;
            break;
        }
        moves_available |= figure_mask;
    }
    std::copy(board, board + 64, temp_board);
    counter = 0;
    while(counter++ < scope && !(second_figure_mask & right_move_mask)){
        old_index = __builtin_clzll(second_figure_mask);
        second_figure_mask >>= 1;
        new_index = __builtin_clzll(second_figure_mask);
        temp_board[new_index] = temp_board[old_index];
        temp_board[old_index] = nullptr;
        temp_board[new_index] -> mask = second_figure_mask;
        
        if (is_checked(temp_board , king_mask, teammate_mask, enemy_mask, color)){
            continue;
        }
        if (second_figure_mask & teammate_mask){
            break;
        }else if (second_figure_mask & enemy_mask){
            moves_available |= second_figure_mask;
            break;
        }
        moves_available |= second_figure_mask;
    }
    delete[] temp_board;
    return moves_available;
}

unsigned long long FigureMoves::available_down_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    if ((int) ((__builtin_clzll(figure_mask)) / 8 + 1) == 2 ){
        scope = 2;
    }
    int counter = 0;

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
    return moves_available;
}

unsigned long long FigureMoves::available_up_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    if ((int) ((__builtin_clzll(figure_mask)) / 8 + 1) == 7 ){
        scope = 2;
    }
    int counter = 0;
    
    while(counter++ < scope && !(figure_mask & up_move_mask)){
        figure_mask <<= 8;
        if (figure_mask & teammate_mask){
            break;
        }
        else if (figure_mask & enemy_mask){
            moves_available |= figure_mask;
            break;
        }
        moves_available |= figure_mask;
    }
    return moves_available;
}

unsigned long long FigureMoves::available_vertical_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    
    Figure** temp_board = new Figure*[64];
    std::copy(board, board + 64, temp_board);

    int counter = 0, old_index, new_index;
    unsigned long long  second_figure_mask = figure_mask;
    
    while(counter++ < scope && !(figure_mask & down_move_mask)){

        old_index = __builtin_clzll(figure_mask);
        figure_mask >>= 8;
        new_index = __builtin_clzll(figure_mask);
        temp_board[new_index] = temp_board[old_index];
        temp_board[old_index] = nullptr;
        temp_board[new_index] -> mask = figure_mask;
        
        if (is_checked(temp_board , king_mask, teammate_mask, enemy_mask, color)){
            continue;
        }

        if (figure_mask & teammate_mask){
            break;
        }
        else if (figure_mask & enemy_mask){
            moves_available |= figure_mask;
            break;
        }
        moves_available |= figure_mask;
    }
    std::copy(board, board + 64, temp_board);
    counter = 0;
    while(counter++ < scope && !(second_figure_mask & up_move_mask)){
        old_index = __builtin_clzll(second_figure_mask);
        second_figure_mask <<= 8;
        new_index = __builtin_clzll(second_figure_mask);
        temp_board[new_index] = temp_board[old_index];
        temp_board[old_index] = nullptr;
        temp_board[new_index] -> mask = second_figure_mask;
        
        if (is_checked(temp_board , king_mask, teammate_mask, enemy_mask, color)){
            continue;
        }
        if (second_figure_mask & teammate_mask){
            break;
        }
        else if (second_figure_mask & enemy_mask){
            moves_available |= second_figure_mask;
            break;
        }
        moves_available |= second_figure_mask;
    }
    delete[] temp_board;
    return moves_available;
}

unsigned long long FigureMoves::available_diagonal_up_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    
    Figure** temp_board = new Figure*[64];
    std::copy(board, board + 64, temp_board);

    int counter = 0, old_index, new_index;
    unsigned long long  second_figure_mask = figure_mask;

    while(counter++ < scope && !(figure_mask & diagonal_left_up_move_mask)){
        old_index = __builtin_clzll(figure_mask);
        figure_mask <<= 9;
        new_index = __builtin_clzll(figure_mask);
        temp_board[new_index] = temp_board[old_index];
        temp_board[old_index] = nullptr;
        temp_board[new_index] -> mask = figure_mask;
        
        if (is_checked(temp_board , king_mask, teammate_mask, enemy_mask, color)){
            continue;
        }
        if (figure_mask & teammate_mask){
            break;
        }else if (figure_mask & enemy_mask){
            moves_available |= figure_mask;
            break;
        }
        moves_available |= figure_mask;
    }
    std::copy(board, board + 64, temp_board);
    counter = 0;
    while(counter++ < scope && !(second_figure_mask & diagonal_right_up_move_mask)){
        old_index = __builtin_clzll(second_figure_mask);
        second_figure_mask <<= 7;
        new_index = __builtin_clzll(second_figure_mask);
        temp_board[new_index] = temp_board[old_index];
        temp_board[old_index] = nullptr;
        temp_board[new_index] -> mask = second_figure_mask;
        
        if (is_checked(temp_board , king_mask, teammate_mask, enemy_mask, color)){
            continue;
        }
        if (second_figure_mask & teammate_mask){
            break;
        }else if (second_figure_mask & enemy_mask){
            moves_available |= second_figure_mask;
            break;
        }
        moves_available |= second_figure_mask;
    }
    delete[] temp_board;
    return moves_available;
}

unsigned long long FigureMoves::available_diagonal_down_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){

    int counter = 0;
    unsigned long long  second_figure_mask = figure_mask;
    
    while(counter++ < scope && !(figure_mask & diagonal_left_down_move_mask)){
        figure_mask >>= 7;
        if (figure_mask & teammate_mask){
            break;
        }else if (figure_mask & enemy_mask){
            moves_available |= figure_mask;
            break;
        }
        
        moves_available |= figure_mask;
    }
    counter = 0;
    while(counter++ < scope && !(second_figure_mask & diagonal_right_down_move_mask)){
        second_figure_mask >>= 9;
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

unsigned long long FigureMoves::available_knight_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){

    unsigned long long  second_figure_mask = figure_mask;
    unsigned long long  third_figure_mask = figure_mask;
    unsigned long long  fourth_figure_mask = figure_mask;
    unsigned long long  fifth_figure_mask = figure_mask;
    unsigned long long  sixth_figure_mask = figure_mask;
    unsigned long long  seventh_figure_mask = figure_mask;
    unsigned long long  eighth_figure_mask = figure_mask;
    
    
    if(!(figure_mask & knight_up_up_right_move_mask)){
        figure_mask <<= 17;
        if (!(figure_mask & teammate_mask)){
            moves_available |= figure_mask;
        }
    }
    if(!(second_figure_mask & knight_up_left_left_move_mask)){
        second_figure_mask <<= 10;
        if (!(second_figure_mask & teammate_mask)){
            moves_available |= second_figure_mask;
        }
    } 
    if(!(third_figure_mask & knight_down_left_left_move_mask)){
        third_figure_mask >>= 6;
        if (!(third_figure_mask & teammate_mask)){
            moves_available |= third_figure_mask;
        }
    }
    if(!(fourth_figure_mask & knight_down_down_left_move_mask)){
        fourth_figure_mask >>= 15;
        if (!(fourth_figure_mask & teammate_mask)){
            moves_available |= fourth_figure_mask;
        }
    }
    if(!(fifth_figure_mask & knight_up_up_right_move_mask)){
        fifth_figure_mask <<= 15;
        if (!(fifth_figure_mask & teammate_mask)){
            moves_available |= fifth_figure_mask;
        }
    }
    if(!(sixth_figure_mask & knight_up_right_right_move_mask)){
        sixth_figure_mask <<= 6;
        if (!(sixth_figure_mask & teammate_mask)){
            moves_available |= sixth_figure_mask;
        }
    } 
    if(!(seventh_figure_mask & knight_down_right_right_move_mask)){
        seventh_figure_mask >>= 10;
        if (!(seventh_figure_mask & teammate_mask)){
            moves_available |= seventh_figure_mask;
        }
    }
    if(!(eighth_figure_mask & knight_down_down_right_move_mask)){
        eighth_figure_mask >>= 17;
        if (!(eighth_figure_mask & teammate_mask)){
            moves_available |= eighth_figure_mask;
        }
    }
    return moves_available;
}


