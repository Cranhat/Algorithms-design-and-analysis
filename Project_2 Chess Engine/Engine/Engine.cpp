#include "Engine.hpp"
#include <iostream>
#include <vector>


std::vector<std::vector<int>> Engine::all_available_moves(Figure** board, int color) {
    std::vector<std::vector<int>> available_moves(64);
    for(int i = 0; i < 64; i++) {
        if (board[i] != nullptr && board[i]->color == color) {
            available_moves[i] = show_available_moves(board, board[i], color);
        }
    }
    return available_moves;
}

std::vector<int> Engine::show_available_moves(Figure** board, Figure* figure, int color){
    std::vector<int> available_moves_eval;
    unsigned long long king_mask = get_king_mask(color);

    switch (figure -> identifier)
    {
    case 1:
        if (figure -> color == 1){
            available_up_moves(board, available_moves_eval, 1, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
        }else{
            available_down_moves(board, available_moves_eval, 1, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
        }
        break;
    case 2:
        if (figure -> color == 1){
            available_vertical_moves(board, available_moves_eval, 8, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            available_horizontal_moves(board, available_moves_eval, 8, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
        }else{
            available_vertical_moves(board, available_moves_eval, 8, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
            available_horizontal_moves(board, available_moves_eval, 8, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
        }
        break;
    case 3:
        if (figure -> color == 1){
            available_knight_moves(board, available_moves_eval, 0, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
        }else{
            available_knight_moves(board, available_moves_eval, 0, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
        } 
        break;
    case 4:
        if (figure -> color == 1){
            available_diagonal_up_moves(board, available_moves_eval, 8, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            available_diagonal_down_moves(board, available_moves_eval, 8, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
        }else{
            available_diagonal_up_moves(board, available_moves_eval, 8, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
            available_diagonal_down_moves(board, available_moves_eval, 8, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
        }
        break;
    case 5:
        if (figure -> color == 1){
            available_horizontal_moves(board, available_moves_eval, 1, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            available_diagonal_up_moves(board, available_moves_eval, 1, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            available_diagonal_down_moves(board, available_moves_eval, 1, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            available_vertical_moves(board, available_moves_eval, 1, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            
        }else{
            available_diagonal_up_moves(board, available_moves_eval, 1, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
            available_diagonal_down_moves(board, available_moves_eval, 1, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
            available_vertical_moves(board, available_moves_eval, 1, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
            available_horizontal_moves(board, available_moves_eval, 1, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
        }
        break;
    case 6:
        if (figure -> color == 1){
            available_diagonal_up_moves(board, available_moves_eval, 8, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            available_diagonal_down_moves(board, available_moves_eval, 8, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            available_vertical_moves(board, available_moves_eval, 8, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            available_horizontal_moves(board, available_moves_eval, 8, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
        }else{
            available_diagonal_up_moves(board, available_moves_eval, 8, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
            available_diagonal_down_moves(board, available_moves_eval, 8, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
            available_vertical_moves(board, available_moves_eval, 8, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
            available_horizontal_moves(board, available_moves_eval, 8, figure -> mask, black_mask(board), white_mask(board), king_mask, color);
        }
        break;
    default: 

        break;
    }
    return available_moves_eval;
}

