#include "Minimax.hpp"
#include <limits>

void print_moves(std::vector<std::vector<int>> moves){
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < (int) moves[i].size(); j++){
            std::cout << "i = " << i << " j = " << j << " available moves: " << moves[i][j] << std::endl;
        }
    }
    
}

double Minimax::minimax(Figure** board, int depth, int maximizing_player, double alpha, double beta){
    double eval;
    if (depth == 0 || is_terminal(board, maximizing_player)){
        return evaluate_position(board);
    }
    if (maximizing_player == 1){            
        double maxEval = -std::numeric_limits<double>::infinity();
        std::vector<std::vector<int>> aam = all_available_moves(board, 1);

        for (int i = 0; i < 64; i++){
            if (board[i] != nullptr){
                for(int j = 0; j < (int) aam[i].size(); j++){
                    Figure** temp_board = cloneBoard(board);
                    move(temp_board, i, aam[i][j], maximizing_player);
                    eval = minimax(temp_board, depth - 1, -1, alpha, beta);
                    alpha = std::max(alpha, eval);
                    maxEval = std::max(maxEval, eval);
                    if (beta <= alpha){
                        deleteBoard(temp_board);
                        break;
                    }
                    deleteBoard(temp_board);
                }
            }
        }
        return maxEval;
    }else{
        double minEval = std::numeric_limits<double>::infinity();
        std::vector<std::vector<int>> aam = all_available_moves(board, -1);
        for (int i = 0; i < 64; i++){
            if (board[i] != nullptr){
                for(int j = 0; j < (int) aam[i].size(); j++){
                    Figure** temp_board = cloneBoard(board);
                    move(temp_board, i, aam[i][j], maximizing_player);
                    eval = minimax(temp_board, depth - 1, 1, alpha, beta);
                    beta = std::min(beta, eval);
                    minEval = std::min(minEval, eval);
                    if (beta <= alpha){
                        deleteBoard(temp_board);
                        break;
                    }
                    deleteBoard(temp_board);
                }
            }
        }
        return minEval;
    }
}

std::pair<int, int> Minimax::get_best_move(Figure** board, int depth, int maximizing_player) {
    double bestEval = maximizing_player == 1 ? -std::numeric_limits<double>::infinity() :  std::numeric_limits<double>::infinity();

    std::pair<int, int> bestMove = {-1, -1};
    std::vector<std::vector<int>> aam = all_available_moves(board, maximizing_player);

    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < (int)aam[i].size(); j++) {
            if (board[i] != nullptr) {
                Figure** temp_board = cloneBoard(board);
                move(temp_board, i, aam[i][j], maximizing_player);
                double eval = minimax(temp_board, depth - 1, -maximizing_player, -std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());

                if ((maximizing_player == 1 && eval > bestEval) ||
                    (maximizing_player == -1 && eval < bestEval)) {
                    bestEval = eval;
                    bestMove = {i, aam[i][j]};
                }
            }
        }
    }
    return bestMove;
}