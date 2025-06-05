#include "Engine.hpp"
#include <iostream>

unsigned long long* Engine::all_available_moves(int color){
    unsigned long long* all_available_moves = new unsigned long long[64];
    // unsigned long long* all_available_moves = (unsigned long long*) malloc(sizeof(unsigned long long) * 64);

    for(int i = 0; i < 64; i++){
        if (board[i] == nullptr){
            all_available_moves[i] = 0;

        }else{
            if(board[i] -> color == color && board[i] != nullptr){
                all_available_moves[i] = show_available_moves(board[i], color);
            }
        }
    }
    return all_available_moves;
}

unsigned long long Engine::show_available_moves(Figure* figure, int color){

    unsigned long long king_mask = get_king_mask(color);
    unsigned long long available_moves;
    switch (figure -> identifier)
    {
    case 1:
        if (figure -> color == 1){
            available_moves = available_up_moves(0, 1, figure -> mask, white_mask(), black_mask(), king_mask, color);
        }else{
            available_moves = available_down_moves(0, 1, figure -> mask, black_mask(), white_mask(), king_mask, color);
        }
        break;
    case 2:
        if (figure -> color == 1){
            available_moves = available_vertical_moves(0, 8, figure -> mask, white_mask(), black_mask(), king_mask, color);
            available_moves = available_horizontal_moves(available_moves, 8, figure -> mask, white_mask(), black_mask(), king_mask, color);
        }else{
            available_moves = available_vertical_moves(0, 8, figure -> mask, black_mask(), white_mask(), king_mask, color);
            available_moves = available_horizontal_moves(available_moves, 8, figure -> mask, black_mask(), white_mask(), king_mask, color);
        }
        break;
    case 3:
        if (figure -> color == 1){
            available_moves = available_knight_moves(0, 0, figure -> mask, white_mask(), black_mask(), king_mask, color);
        }else{
            available_moves = available_knight_moves(0, 0, figure -> mask, black_mask(), white_mask(), king_mask, color);
        } 
        break;
    case 4:
        if (figure -> color == 1){
            available_moves = available_diagonal_up_moves(0, 8, figure -> mask, white_mask(), black_mask(), king_mask, color);
            available_moves = available_diagonal_down_moves(available_moves, 8, figure -> mask, white_mask(), black_mask(), king_mask, color);
        }else{
            available_moves = available_diagonal_up_moves(0, 8, figure -> mask, black_mask(), white_mask(), king_mask, color);
            available_moves = available_diagonal_down_moves(available_moves, 8, figure -> mask, black_mask(), white_mask(), king_mask, color);
        }
        break;
    case 5:
        if (figure -> color == 1){
            available_moves = available_horizontal_moves(0, 1, figure -> mask, white_mask(), black_mask(), king_mask, color);
            available_moves = available_diagonal_up_moves(available_moves, 1, figure -> mask, white_mask(), black_mask(), king_mask, color);
            available_moves = available_diagonal_down_moves(available_moves, 1, figure -> mask, white_mask(), black_mask(), king_mask, color);
            available_moves = available_vertical_moves(available_moves, 1, figure -> mask, white_mask(), black_mask(), king_mask, color);
            
        }else{
            available_moves = available_diagonal_up_moves(0, 1, figure -> mask, black_mask(), white_mask(), king_mask, color);
            available_moves = available_diagonal_down_moves(available_moves, 1, figure -> mask, black_mask(), white_mask(), king_mask, color);
            available_moves = available_vertical_moves(available_moves, 1, figure -> mask, black_mask(), white_mask(), king_mask, color);
            available_moves = available_horizontal_moves(available_moves, 1, figure -> mask, black_mask(), white_mask(), king_mask, color);
        }
        break;
    case 6:
        if (figure -> color == 1){
            available_moves = available_diagonal_up_moves(0, 8, figure -> mask, white_mask(), black_mask(), king_mask, color);
            available_moves = available_diagonal_down_moves(available_moves, 8, figure -> mask, white_mask(), black_mask(), king_mask, color);
            available_moves = available_vertical_moves(available_moves, 8, figure -> mask, white_mask(), black_mask(), king_mask, color);
            available_moves = available_horizontal_moves(available_moves, 8, figure -> mask, white_mask(), black_mask(), king_mask, color);
        }else{
            available_moves = available_diagonal_up_moves(0, 8, figure -> mask, black_mask(), white_mask(), king_mask, color);
            available_moves = available_diagonal_down_moves(available_moves, 8, figure -> mask, black_mask(), white_mask(), king_mask, color);
            available_moves = available_vertical_moves(available_moves, 8, figure -> mask, black_mask(), white_mask(), king_mask, color);
            available_moves = available_horizontal_moves(available_moves, 8, figure -> mask, black_mask(), white_mask(), king_mask, color);
        }
        break;
    default: 

        break;
    }
    return available_moves;
}

double Engine::evaluate_position(){
    double sum = 0;
    for(int i = 0; i < 64; i++){
        if (board[i] != nullptr){
        
            sum += ((board[i] -> cost) + get_additional_move_value(__builtin_ctzll(board[i] -> mask), board[i] -> identifier, board[i] -> color)) * (board[i] -> color);

        }
    }
    return sum;
}


double Engine::get_additional_move_value(int index, int piece_type, int piece_color){
    float additional_value = 0;

    additional_value += center_pieces_mask[index];

    if (piece_color == 1){
        if (piece_type == 5){
            additional_value += white_king_mask[index];
        }
    }

    if (piece_color == -1){
        if (piece_type == 5){
            additional_value += black_king_mask[index];
        }
    }

    return additional_value;
}