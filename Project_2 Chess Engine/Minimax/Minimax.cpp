#include "Minimax.hpp"
#include <limits>

std::vector<int> Minimax::piece_moves_index_available(unsigned int bitmask) {
    std::vector<int> indexes;
    int index = 0;
    while (bitmask) {
        if (bitmask & 1) {
            indexes.push_back(index);
        }
        bitmask >>= 1;
        index++;
    }
    return indexes;
}

double Minimax::minimax(Figure** board, int depth, int maximizing_player){
    double eval;
    Figure** temp_board = new Figure*[64];
    std::vector<int> piece_moves_available;
    if (depth == 0){ // || is terminal
        delete[]  temp_board;
        return evaluate_position(); // board as arg
    }
    if (maximizing_player == 1){
        double maxEval = std::numeric_limits<double>::infinity();
        unsigned long long* aam = all_available_moves(maximizing_player);
        for (int i = 0; i < 64; i++){
            if (board[i] != nullptr){
                piece_moves_available = piece_moves_index_available(board[i] -> mask);
                for(int j = 0; j < piece_moves_available.size(); j++){
                    temp_board = simulate_move(temp_board, i, piece_moves_available[j]);
                    eval = minimax(temp_board, depth - 1, maximizing_player * (-1));
                    maxEval = std::max(maxEval, eval);
                }
            }
        }
        return maxEval;
    
    }else{
        double minEval = -std::numeric_limits<double>::infinity();
        unsigned long long* aam = all_available_moves(maximizing_player);
        for (int i = 0; i < 64; i++){
            if (board[i] != nullptr){
                piece_moves_available = piece_moves_index_available(board[i] -> mask);
                for(int j = 0; j < piece_moves_available.size(); j++){
                    temp_board = simulate_move(temp_board, i, j);
                    eval = minimax(temp_board, depth - 1, maximizing_player * (-1));
                    minEval = std::min(minEval, eval);
                }
            }
        }
        return minEval;
    }   
}