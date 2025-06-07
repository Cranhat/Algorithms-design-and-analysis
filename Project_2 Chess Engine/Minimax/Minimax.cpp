#include "Minimax.hpp"
#include <limits>

void print_moves(std::vector<std::vector<int>> moves){
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < (int) moves[i].size(); j++){
            std::cout << "i = " << i << " j = " << j << " available moves: " << moves[i][j] << std::endl;
        }
    }
}

double Minimax::minimax(Figure** board, int depth, int maximizing_player){
    double eval;
    if (depth == 0 ){ // add or is terminal(king captured, eval of this should be extremely high)
        // std::cout << evaluate_position(board) << std::endl;

        if (evaluate_position(board) > 2){
            print_board(board);
            std::cout << evaluate_position(board) << std::endl;
        }
        return evaluate_position(board);
    }
    if (maximizing_player == 1){            
        double maxEval = -std::numeric_limits<double>::infinity();
        std::vector<std::vector<int>> aam = all_available_moves(board, 1);
        // std::cout << "available white moves: " << std::endl;
        // print_moves(aam);  
        for (int i = 0; i < 64; i++){
            for(int j = 0; j < (int) aam[i].size(); j++){
                if (board[i] != nullptr){
                
                    Figure** temp_board = cloneBoard(board);

                    move(temp_board, i, aam[i][j]);

                    eval = minimax(temp_board, depth - 1, -1);
                    // std::cout << "current_max_eval = " << eval << std::endl;
                    maxEval = std::max(maxEval, eval);


                    // for (int k = 0; k < 64; k++) {
                    //     delete temp_board[k];
                    // }
                    // delete[] temp_board;
                }
            }
        }
        // std::cout << "max eval = " << maxEval << std::endl;
        return maxEval;
    }else{
        double minEval = std::numeric_limits<double>::infinity();
        std::vector<std::vector<int>> aam = all_available_moves(board, -1);
        // std::cout << "available black moves: " << std::endl;
        // print_moves(aam);
        for (int i = 0; i < 64; i++){
            for(int j = 0; j < (int) aam[i].size(); j++){
                if (board[i] != nullptr){
                    Figure** temp_board = cloneBoard(board);
                    move(temp_board, i, aam[i][j]);
                    eval = minimax(temp_board, depth - 1, 1);
                    // std::cout << "current_min_eval = " << eval << std::endl;
                    minEval = std::min(minEval, eval);
                // for (int k = 0; k < 64; k++) {
                //     delete temp_board[k];
                // }
                // delete[] temp_board;
                }
            }
        }
        // std::cout << "min eval = " << minEval << std::endl;
        return minEval;
    }
}