#include "SpecialMoves.hpp"

void SpecialMoves::is_castle_available(Figure** board, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    if (color == 1){
        if(!(teammate_mask & white_castle_right_bitboard) && board[0]){
            available_moves_eval.push_back(1);
        }
        if(!(teammate_mask & white_castle_left_bitboard) && board[7]){
            available_moves_eval.push_back(5);
        }
    }else if(color == -1){
        if(!(teammate_mask & black_castle_right_bitboard) && board[56]){
            available_moves_eval.push_back(55);
        }
        if(!(teammate_mask & black_castle_left_bitboard) && board[63]){
            available_moves_eval.push_back(61);
        }
    }
}