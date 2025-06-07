#include <iostream>
#include <bitset>

#include "../Pieces/Pieces.cpp"
#include "../Board/Board.cpp"
#include "../Engine/Engine.cpp"
#include "../Minimax/Minimax.cpp"

#include "../MovePolicy/MovePolicy.cpp"
#include "../MovePolicy/KingCheckPolicy.cpp"
#include "../MovePolicy/SpecialMoves.cpp"
#include "../MovePolicy/FigureMoves.cpp"


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
    Minimax engine;
    
    std::cout << "Test1:\n";
    std::cout << "-------------------------------" << std::endl;
    // for (int i = 0; i < 64; i++){
    //     engine.board[i] = nullptr;
    // }
    // engine.board[0] = new King(0x1ULL, 1);
    // engine.board[8] = new Rook(0x100ULL, 1);

    // engine.board[63] = new King(0x8000000000000000ULL, -1);
    // engine.board[56] = new Rook(0x100000000000000ULL, -1);

    engine.print_board();

   
    // std::vector<std::vector<int>> all_available_moves = engine.all_available_moves(engine.board, -1);

    std::cout << "--------------------------------------\n";
    // for(int i = 0; i < 64; i++){
    //     for(int j = 0; j < all_available_moves[i].size(); j++){
    //         std::cout << "i = " << i << " j = " << j << " available moves: " << all_available_moves[i][j] << std::endl;
    //     }
    // }
    engine.minimax(engine.board, 4, 1);
    std::cout << "--------------------------------------\n";
    std::cout << "end\n";


    return 0;
}