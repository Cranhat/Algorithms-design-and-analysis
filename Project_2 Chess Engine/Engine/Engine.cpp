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


// king_mask = findKing(temp_board, color) -> mask;
// if (color == 1){
//     if (is_checked(temp_board, king_mask, white_mask(temp_board), black_mask(temp_board), color)){
//         deleteBoard(temp_board);
//         return 1;
//     }
    
int Engine::isCheckmate(Figure** board, int color){
    unsigned long long teammate_mask = color == 1 ? white_mask(board) : black_mask(board);
    unsigned long long enemy_mask = color == 1 ? black_mask(board) : white_mask(board);
    int checkmate = color == 1 ? 1 : -1;
    bool all_empty = true;

    for (const auto& moves : all_available_moves(board, color)) {
        if (!moves.empty()) {
            all_empty = false;
            break;
        }
    }

    if(is_checked(board, findKing(board, color) -> mask, teammate_mask, enemy_mask, color) && all_empty){
        return checkmate;
    }
    return 0;
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
            is_castle_available(board, available_moves_eval, 1, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            available_horizontal_moves(board, available_moves_eval, 1, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            available_diagonal_up_moves(board, available_moves_eval, 1, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            available_diagonal_down_moves(board, available_moves_eval, 1, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            available_vertical_moves(board, available_moves_eval, 1, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
            
        }else{
            is_castle_available(board, available_moves_eval, 1, figure -> mask, white_mask(board), black_mask(board), king_mask, color);
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

