#include <iostream>
#include <bitset>

#include "Pieces/Pieces.cpp"
#include "Board/Board.cpp"
#include "Engine/Engine.cpp"

#include "MovePolicy/MovePolicy.cpp"
#include "MovePolicy/KingCheckPolicy.cpp"
#include "MovePolicy/SpecialMoves.cpp"
#include "MovePolicy/FigureMoves.cpp"

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
int main(){
    Engine engine;

    engine.Board::print_board();

    std:: cout << "pos eval" << engine.evaluate_position(engine.board) << std::endl;

    std::vector<std::vector<int>> all_available_moves = engine.all_available_moves(engine.board, 1);

    // std::vector<int> some_moves = engine.show_available_moves(engine.board, engine.board[62], -1);

    // std::cout << "--------------------------------------\n";
    // for(int i = 0; i < some_moves.size(); i++){
    //     std::cout << "moves for index " << i << "=" << some_moves[i]<< std::endl;
    // }
    // std::cout << "--------------------------------------\n";
    // std::cout << "end\n";

    
    std::cout << "--------------------------------------\n";
    for(int i = 0; i < 64; i++){

        for(int j = 0; j < all_available_moves[i].size(); j++){
            std::cout << i << ":" << all_available_moves[i][j] << std::endl;
        }
    }

    std::cout << "--------------------------------------\n";
    std::cout << "end\n";

    
    return 0;
}

