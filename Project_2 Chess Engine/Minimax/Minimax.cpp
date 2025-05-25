#include "Minimax.hpp"
#include <limits>

// void Minimax::minimax(int position, int depth, int maximizing_player){
//     // if (depth == 0 || is_terminal){
//     //     return static_evaluation_of_position;
//     // }
//     if (maximizing_player == 1){
//         int maxEval = -std::numeric_limits<int>::min();
//         for every_position:
//             eval = minimax(int position, int depth - 1, maximizing_player * (-1));
//             maxEval = max(maxEval, eval);
//         return maxEval;
//     }else{
//         int minEval = -std::numeric_limits<int>::max();
//         for every_position:
//             eval = minimax(int position, int depth - 1, maximizing_player * (-1));
//             maxEval = max(maxEval, eval);
//         return minEval;
//     }
// }

// //initial call
// minimax(current_position, 3, 1) // 1 for white