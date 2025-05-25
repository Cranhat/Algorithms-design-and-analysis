#include "Engine.hpp"
#include <iostream>

unsigned long long* Engine::all_available_moves(int playing_color){

    unsigned long long* all_available_moves = (unsigned long long*) malloc(sizeof(unsigned long long) * 64);

    for(int i = 0; i < 64; i++){
        if (board[i] == nullptr){
            all_available_moves[i] = 0;

        }else{
            if(board[i] -> color == playing_color){
                all_available_moves[i] = show_available_moves(board[i]);
            }
        }
    }
    return all_available_moves;
}

unsigned long long Engine::show_available_moves(Figure* figure){
    unsigned long long available_moves;
    switch (figure -> identifier)
    {
    case 1:
        if (figure -> color == 1){
            available_moves = available_up_moves(0, 1, figure -> mask, white_mask(), black_mask());
        }else{
            available_moves = available_down_moves(0, 1, figure -> mask, black_mask(), white_mask());
        }
        break;
    case 2:
        if (figure -> color == 1){
            available_moves = available_vertical_moves(0, 8, figure -> mask, white_mask(), black_mask());
            available_moves = available_horizontal_moves(available_moves, 8, figure -> mask, white_mask(), black_mask());
        }else{
            available_moves = available_vertical_moves(0, 8, figure -> mask, black_mask(), white_mask());
            available_moves = available_horizontal_moves(available_moves, 8, figure -> mask, black_mask(), white_mask());
        }
        break;
    case 3:
        if (figure -> color == 1){
            available_moves = available_knight_moves(0, 0, figure -> mask, white_mask(), black_mask());
        }else{
            available_moves = available_knight_moves(0, 0, figure -> mask, black_mask(), white_mask());
        } 
        break;
    case 4:
        if (figure -> color == 1){
            available_moves = available_diagonal_up_moves(0, 8, figure -> mask, white_mask(), black_mask());
            available_moves = available_diagonal_down_moves(available_moves, 8, figure -> mask, white_mask(), black_mask());
        }else{
            available_moves = available_diagonal_up_moves(0, 8, figure -> mask, black_mask(), white_mask());
            available_moves = available_diagonal_down_moves(available_moves, 8, figure -> mask, black_mask(), white_mask());
        }
        break;
    case 5:
        if (figure -> color == 1){
            available_moves = available_diagonal_up_moves(0, 1, figure -> mask, white_mask(), black_mask());
            available_moves = available_diagonal_down_moves(available_moves, 1, figure -> mask, white_mask(), black_mask());
            available_moves = available_vertical_moves(available_moves, 1, figure -> mask, white_mask(), black_mask());
            available_moves = available_horizontal_moves(available_moves, 1, figure -> mask, white_mask(), black_mask());
        }else{
            available_moves = available_diagonal_up_moves(0, 1, figure -> mask, black_mask(), white_mask());
            available_moves = available_diagonal_down_moves(available_moves, 1, figure -> mask, black_mask(), white_mask());
            available_moves = available_vertical_moves(available_moves, 1, figure -> mask, black_mask(), white_mask());
            available_moves = available_horizontal_moves(available_moves, 1, figure -> mask, black_mask(), white_mask());
        }
        break;
    case 6:
        if (figure -> color == 1){
            available_moves = available_diagonal_up_moves(0, 8, figure -> mask, white_mask(), black_mask());
            available_moves = available_diagonal_down_moves(available_moves, 8, figure -> mask, white_mask(), black_mask());
            available_moves = available_vertical_moves(available_moves, 8, figure -> mask, white_mask(), black_mask());
            available_moves = available_horizontal_moves(available_moves, 8, figure -> mask, white_mask(), black_mask());
        }else{
            available_moves = available_diagonal_up_moves(0, 8, figure -> mask, black_mask(), white_mask());
            available_moves = available_diagonal_down_moves(available_moves, 8, figure -> mask, black_mask(), white_mask());
            available_moves = available_vertical_moves(available_moves, 8, figure -> mask, black_mask(), white_mask());
            available_moves = available_horizontal_moves(available_moves, 8, figure -> mask, black_mask(), white_mask());
        }
        break;
    default: 

        break;
    }
    return available_moves;
}

float Engine::evaluate_position(){ // add Figure** board to args, change to cost
    float sum = 0;
    for(int i = 0; i < 64; i++){
        if (board[i] != nullptr){
            sum += (board[i] -> identifier) * (board[i] -> color);
        }
    }
    return sum;
}