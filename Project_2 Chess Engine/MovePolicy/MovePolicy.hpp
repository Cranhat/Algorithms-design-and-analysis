
/*
Moving  up and down involves bit shift in amount of moves * rows, with taking int account edge cases,
Moving left and down involves bitwise left or right shift, taking into consideration left and right move mask,
Moving diagonally involves combining both operations,

All operations needs to be checked if king isnt check before move, after move, is draw because 50 moves without capture have been made, is piece in the way, and is piece in the destination
*/
#pragma once

#include "../Pieces/Pieces.hpp"

class MovePolicy{
    protected:

    unsigned long long right_move_mask = 0x101010101010101ULL; // 0000000100000001000000010000000100000001000000010000000100000001
    unsigned long long left_move_mask = 0x8080808080808080ULL; // 1000000010000000100000001000000010000000100000001000000010000000

    unsigned long long up_move_mask = 0xFF00000000000000ULL; // 1111111100000000000000000000000000000000000000000000000000000000
    unsigned long long down_move_mask = 0xFFULL; // 0000000000000000000000000000000000000000000000000000000011111111

    unsigned long long diagonal_right_up_move_mask = 0xFF01010101010101ULL; // 1111111100000001000000010000000100000001000000010000000100000001
    unsigned long long diagonal_right_down_move_mask = 0x1010101010101FFULL; // 0000000100000001000000010000000100000001000000010000000111111111

    unsigned long long diagonal_left_up_move_mask = 0xFF80808080808080ULL;// 1111111110000000100000001000000010000000100000001000000010000000
    unsigned long long diagonal_left_down_move_mask = 0x80808080808080FFULL;// 1000000010000000100000001000000010000000100000001000000011111111

    public:

    unsigned long long available_horizontal_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask);

    unsigned long long available_vertical_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask);

    unsigned long long available_diagonal_up_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask);

    unsigned long long available_diagonal_down_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask);
    
};
/*
11111111
00000001
00000001
00000001
00000001
00000001
00000001
00000001
*/