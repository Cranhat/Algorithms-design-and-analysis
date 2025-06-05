// #include "Minimax.hpp"
// #include <limits>

// double Minimax::minimax(Figure** board, int depth, int maximizing_player){
//     if (depth == 0 || is_terminal){
//         return evaluate_position();
//     }
//     if (maximizing_player == 1){
//         double maxEval = std::numeric_limits<int>::min();
//         unsigned long long* all_available_moves = all_available_moves(maximizing_player);
//         for (int i = 0; i < 64; i++){
//             if (board[i] != nullptr){
//                 temp_board = simulate_move(i, *get every new index of a figure*);
//                 eval = minimax(figure** temp_board, depth - 1, maximizing_player * (-1));
//                 maxEval = std::max(maxEval, eval);
//             }
//         }
//         return maxEval;
    
//     }else{
//         double minEval = std::numeric_limits<int>::max();
//         unsigned long long* all_available_moves = all_available_moves(maximizing_player);
//         for (int i = 0; i < 64; i++){
//             if (board[i] != nullptr){
//                 temp_board = simulate_move(i, *get every new index of a figure*);
//                 eval = minimax(int figure** temp_board,, int depth - 1, maximizing_player * (-1));
//                 maxEval = max(maxEval, eval);
//             }

//         return minEval;
//     }
// }