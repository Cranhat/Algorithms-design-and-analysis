#include "Board.hpp"
#include <iostream>


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
    for(int i = 0; i < 64; i++){
        if (board[i] != nullptr){
            std::cout << board[i] -> identifier  *  board[i] -> color << " ";
        }else{
            std::cout << "0 " ;
        }
        if ((i + 1) % 8 == 0) std::cout << std::endl;
    }
}

