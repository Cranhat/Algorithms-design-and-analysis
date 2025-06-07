#pragma once

#include "FigureMoves.hpp"
#include "../Board/Board.hpp"

class KingCheckPolicy{
    public:

    unsigned long long a = 0x0101010101010101ULL; // 0000000100000001000000010000000100000001000000010000000100000001
    unsigned long long b = 0x0202020202020202ULL; // 0000001000000010000000100000001000000010000000100000001000000010
    unsigned long long c = 0;
    unsigned long long d = 0;
    unsigned long long e = 0;
    unsigned long long f = 0;
    unsigned long long g = 0x4040404040404040ULL; // 0100000001000000010000000100000001000000010000000100000001000000
    unsigned long long h = 0x8080808080808080ULL; // 1000000010000000100000001000000010000000100000001000000010000000

    unsigned long long eight = 0xFF00000000000000ULL; // 1111111100000000000000000000000000000000000000000000000000000000
    unsigned long long seven = 0xFF000000000000ULL;   // 0000000011111111000000000000000000000000000000000000000000000000
    unsigned long long six = 0;
    unsigned long long five = 0;
    unsigned long long four = 0;
    unsigned long long three = 0;
    unsigned long long two = 0xFF00ULL; // 0000000000000000000000000000000000000000000000001111111100000000
    unsigned long long one = 0xFFULL;   // 0000000000000000000000000000000000000000000000000000000011111111

    unsigned long long left_move_mask = h; 
    unsigned long long right_move_mask = a; 

    unsigned long long up_move_mask = eight; 
    unsigned long long down_move_mask = one;  

    unsigned long long diagonal_left_up_move_mask = h | eight;
    unsigned long long diagonal_left_down_move_mask = h | one;

    unsigned long long diagonal_right_up_move_mask = a | eight; 
    unsigned long long diagonal_right_down_move_mask = a | one;

    unsigned long long knight_up_up_right_move_mask = a | seven | eight;
    unsigned long long knight_up_right_right_move_mask = a | b | eight; 

    unsigned long long knight_down_right_right_move_mask = a | b | one; 
    unsigned long long knight_down_down_right_move_mask = a | one | two;

    unsigned long long knight_up_up_left_move_mask = h | seven | eight; 
    unsigned long long knight_up_left_left_move_mask = h | g | eight; 

    unsigned long long knight_down_left_left_move_mask = h | g | one;
    unsigned long long knight_down_down_left_move_mask = h | one | two;
    
    // bool is_terminal(Figure** board, unsigned long long king_mask, unsigned long long available_king_moves, unsigned long long teammate_mask, unsigned long long enemy_mask, int color);

    bool is_checked(Figure** board, unsigned long long king_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, int color);
};