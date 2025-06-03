#include "Board.hpp"
#include <iostream>
#include <cmath>


void Board::print_board(){
    for(int i = 63; i >= 0; i--){
        if (board[i] != nullptr){
            if (board[i] -> color == -1){
                std::cout << board[i] -> identifier  *  board[i] -> color << " ";
            }else{
                std::cout << " " <<board[i] -> identifier  *  board[i] -> color << " ";
            }
        }else{
            std::cout << " 0 " ;
        }
        if ((i) % 8 == 0) std::cout << "   " << (int)  (i/8) + 1 <<std::endl;
    }
    std::cout << std::endl <<  " h  g  f  e  d  c  b  a " << std::endl;  
}

void Board::print_board(Figure** board){
    for(int i = 63; i >= 0; i--){
        if (board[i] != nullptr){
            if (board[i] -> color == -1){
                std::cout << board[i] -> identifier  *  board[i] -> color << " ";
            }else{
                std::cout << " " <<board[i] -> identifier  *  board[i] -> color << " ";
            }
        }else{
            std::cout << " 0 " ;
        }
        if ((i) % 8 == 0) std::cout << "   " << (int)  (i/8) + 1 <<std::endl;
    }
    std::cout << std::endl <<  " h  g  f  e  d  c  b  a " << std::endl;  
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

unsigned long long Board::black_mask(Figure** temp_board){
    unsigned long long black_mask = 0;
    for(int i = 0; i < 64; i++){
        if (temp_board[i] && (temp_board[i] -> color == -1)){
            black_mask |= (1ULL << i);
        }
    }
    return black_mask;
}

unsigned long long Board::white_mask(Figure** temp_board){
    unsigned long long white_mask = 0;
    for(int i = 0; i < 64; i++){
        if (temp_board[i] && (temp_board[i] -> color == 1)){
            white_mask |= (1ULL << i);
        }
    }
    return white_mask;
}

unsigned long long Board::get_king_mask(int color){
    if (color == 1){
        return this -> white_king_pointer -> mask;
    }else if (color == -1){
        return this -> black_king_pointer -> mask;
    }
    return 0;
}