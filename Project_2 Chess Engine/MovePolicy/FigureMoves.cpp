#include "FigureMoves.hpp"
#include <bitset>

void print_bitboardd(unsigned long long bitmask){
    std:: string board = std::bitset<64>(bitmask).to_string();
    for(int i = 0; i < 64; i++){
        std::cout << board[i];
        if ((i + 1) % 8 == 0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

unsigned long long FigureMoves::calculate_new_mask(int index) {
    return index == 0 ? 0x1 : (0x1 << index);
}


void FigureMoves::move(int old_index, int new_index){
    this -> board[new_index] = this ->board[old_index];
    this -> board[old_index] = nullptr;
    this -> board[new_index] -> mask = calculate_new_mask(new_index);
}

bool FigureMoves::simulate_and_check(int old_index, int new_index, int color){
    unsigned long long king_mask = 0;
    // std::cout << "------------------" << std::endl;
    Figure** temp_board = new Figure*[64];
    for (int i = 0; i < 64; ++i) {
        temp_board[i] = this->board[i] ? this->board[i]->clone() : nullptr;
    }

    temp_board[new_index] = temp_board[old_index];
    temp_board[new_index] -> mask = calculate_new_mask(new_index);
    temp_board[old_index] = nullptr;

    // print_board(temp_board);
    // std::cout << "old index: " << old_index << "new_index: " << new_index << std::endl;
    // std::cout << "white mask: " << std::endl;
    // print_bitboardd(white_mask(temp_board));
    // std::cout << "black mask: " << std::endl;
    // print_bitboardd(black_mask(temp_board));
    // std::cout << "------------------" << std::endl;

    for (int i = 0; i < 64; ++i) {
        if (temp_board[i] != nullptr && temp_board[i] -> identifier == 5 && temp_board[i] -> color == color){
            king_mask = temp_board[i] -> mask;
        }
    }

    if (color == 1){
        if (is_checked(temp_board, king_mask, white_mask(temp_board), black_mask(temp_board), color)){
            // std::cout << "checked, indexes = " << old_index << "," << new_index << std::endl;
            // std::cout << "------------------" << std::endl;
            delete[] temp_board;
            return 1;
        }
    }else if(color == -1){
        if (is_checked(temp_board, king_mask, black_mask(temp_board), white_mask(temp_board), color)){
            delete[] temp_board;
            return 1;
        }
    }

    delete[] temp_board;
    return 0;
}

unsigned long long FigureMoves::available_horizontal_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){

    int counter = 0, old_index, new_index;
    unsigned long long  second_figure_mask = figure_mask;
    old_index = __builtin_ctzll(figure_mask);
    while(counter++ < scope && !(figure_mask & left_move_mask)){
        figure_mask <<= 1;
        if (figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(figure_mask);
        if (simulate_and_check(old_index, new_index, color)){
            continue;
        }
        moves_available |= figure_mask;
        if (figure_mask & enemy_mask){
            break;
        }
    }

    counter = 0;
    old_index = __builtin_ctzll(second_figure_mask);
    while(counter++ < scope && !(second_figure_mask & right_move_mask)){
        second_figure_mask >>= 1;
        if (second_figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(second_figure_mask);
        if (simulate_and_check(old_index, new_index, color)){
            continue;
        }
        moves_available |= second_figure_mask;
        if (second_figure_mask & enemy_mask){
            break;
        }
    }
    return moves_available;
}

unsigned long long FigureMoves::available_down_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    if ((int) ((__builtin_ctzll(figure_mask)) / 8 + 1) == 2 ){
        scope = 2;
    }
    int counter = 0;

    while(counter++ < scope && !(figure_mask & down_move_mask)){
        figure_mask >>= 8;
        if (figure_mask & teammate_mask){
            break;
        }
        moves_available |= figure_mask;
        if (figure_mask & enemy_mask){
            break;
        }
    }
    return moves_available;
}

unsigned long long FigureMoves::available_up_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    if ((int) ((__builtin_ctzll(figure_mask)) / 8 + 1) == 7 ){
        scope = 2;
    }
    int counter = 0;
    
    while(counter++ < scope && !(figure_mask & up_move_mask)){
        figure_mask <<= 8;
        if (figure_mask & teammate_mask){
            break;
        }
        moves_available |= figure_mask;
        if (figure_mask & enemy_mask){
            break;
        }
    }
    return moves_available;
}

unsigned long long FigureMoves::available_vertical_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    unsigned long long  second_figure_mask = figure_mask;

    int counter = 0, old_index, new_index;
    old_index = __builtin_ctzll(figure_mask);
    while(counter++ < scope && !(figure_mask & down_move_mask)){

        figure_mask >>= 8;
        new_index = __builtin_ctzll(figure_mask);
        if (figure_mask & teammate_mask){
            break;
        }
        if (simulate_and_check(old_index, new_index, color)){
            continue;
        }
        moves_available |= figure_mask;
        if (figure_mask & enemy_mask){
            break;
        }
    }

    counter = 0;
    old_index = __builtin_ctzll(second_figure_mask); // redundant?
    while(counter++ < scope && !(second_figure_mask & up_move_mask)){
        
        
        second_figure_mask <<= 8;
        if (second_figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(second_figure_mask);
        if (simulate_and_check(old_index, new_index, color)){
            continue;
        }
        moves_available |= second_figure_mask;
        if (second_figure_mask & enemy_mask){
            break;
        }
    }
    return moves_available;
}

unsigned long long FigureMoves::available_diagonal_up_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    
    int counter = 0, old_index, new_index;
    unsigned long long  second_figure_mask = figure_mask;

    old_index = __builtin_ctzll(figure_mask);
    while(counter++ < scope && !(figure_mask & diagonal_left_up_move_mask)){
        figure_mask <<= 9;
        if (figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(figure_mask);
        if (simulate_and_check(old_index, new_index, color)){
            continue;
        }
        moves_available |= figure_mask;  
        if (figure_mask & enemy_mask){
            break;
        }
    }
    counter = 0;
    old_index = __builtin_ctzll(second_figure_mask);
    while(counter++ < scope && !(second_figure_mask & diagonal_right_up_move_mask)){

        second_figure_mask <<= 7;
        if (second_figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(second_figure_mask);
        if (simulate_and_check(old_index, new_index, color)){
            continue;
        }
        moves_available |= second_figure_mask;
        if (second_figure_mask & enemy_mask){
            break;
        }
    }
    return moves_available;
}

unsigned long long FigureMoves::available_diagonal_down_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){

    int counter = 0, old_index, new_index;
    unsigned long long  second_figure_mask = figure_mask;

    old_index = __builtin_ctzll(figure_mask);
    while(counter++ < scope && !(figure_mask & diagonal_left_down_move_mask)){
        figure_mask >>= 7;
        if (figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(figure_mask);
        if (simulate_and_check(old_index, new_index, color)){
            continue;
        }
        moves_available |= figure_mask;
        if (figure_mask & enemy_mask){
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(second_figure_mask & diagonal_right_down_move_mask)){
        second_figure_mask >>= 9;
        if (second_figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(figure_mask);
        if (simulate_and_check(old_index, new_index, color)){
            continue;
        }
        moves_available |= second_figure_mask;
        if (second_figure_mask & enemy_mask){
            break;
        }
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


