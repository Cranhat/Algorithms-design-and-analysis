#include "Board.hpp"
#include <iostream>
#include <cmath>


bool Board::is_terminal(){
    return false;
}

bool Board::is_white_checked(){
    return false;
}

bool Board::is_black_checked(){
    return false;
}

void Board::print_board(){
    for(int i = 63; i >= 0; i--){
        if (board[i] != nullptr){
            std::cout << board[i] -> identifier  *  board[i] -> color << " ";
        }else{
            std::cout << "0 " ;
        }
        if ((i) % 8 == 0) std::cout << std::endl;
    }
}

unsigned long long Board::black_mask(){
    unsigned long long black_mask = 0;
    for(int i = 0; i < 64; i++){
        if (board[i] && (board[i] -> color == -1)){
            black_mask |= (1ULL << i);
        }
    }
    return black_mask;
}

unsigned long long Board::white_mask(){
    unsigned long long white_mask = 0;
    for(int i = 0; i < 64; i++){
        if (board[i] && (board[i] -> color == 1)){
            white_mask |= (1ULL << i);
        }
    }
    return white_mask;
}