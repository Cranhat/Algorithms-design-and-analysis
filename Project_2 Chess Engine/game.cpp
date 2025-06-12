#include <iostream>
#include <bitset>

#include "Pieces/Pieces.cpp"
#include "Board/Board.cpp"
#include "Engine/Engine.cpp"
#include "Minimax/Minimax.cpp"

#include "MovePolicy/MovePolicy.cpp"
#include "MovePolicy/KingCheckPolicy.cpp"
#include "MovePolicy/SpecialMoves.cpp"
#include "MovePolicy/FigureMoves.cpp"


#include<windows.h>

void print_bitboard(unsigned long long bitmask){
    std:: string board = std::bitset<64>(bitmask).to_string();
    for(int i = 0; i < 64; i++){
        std::cout << board[i];
        if ((i + 1) % 8 == 0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
// void print_moves(std::vector<std::vector<int>> moves){
//     for(int i = 0; i < 64; i++){
//         for(int j = 0; j < (int) moves[i].size(); j++){
//             std::cout << "i = " << i << " j = " << j << " available moves: " << moves[i][j] << std::endl;
//         }
//     }
// }

void print_move(std::vector<int> moves){
    for(int i = 0; i < moves.size(); i++){
        std::cout << " available moves: " << moves[i] << std::endl;
    }
}

int main(){
    Minimax engine;
    
    engine.print_board();

    std::pair<int, int> best_move_in_position;
    std::vector<int> available_moves;

    int old_index, new_index;
    while(1){
        std::cout << "move from: ";
        std::cin >> old_index;
        available_moves = engine.show_available_moves(engine.board, engine.board[old_index], 1);
        print_move(available_moves);

        std::cout << "\nmove to: ";
        std::cin >> new_index;
        engine.move(old_index, new_index);

        // best_move_in_position = engine.get_best_move(engine.board, 3, 1);
        // engine.move(best_move_in_position.first, best_move_in_position.second);

        best_move_in_position = engine.get_best_move(engine.board, 3, -1);
        engine.move(best_move_in_position.first, best_move_in_position.second);

        engine.print_board();
        // Sleep(1000);
    }

    return 0;
}