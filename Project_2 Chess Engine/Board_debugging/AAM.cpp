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
    for (int i = 8; i < 16; i++){
        engine.board[i] = nullptr;
    }
    for (int i = 47; i < 55; i++){
        engine.board[i] = nullptr;
    }
    // engine.board[0] = new King(0x1ULL, 1);
    // engine.board[8] = new Rook(0x100ULL, 1);

    // engine.board[63] = new King(0x8000000000000000ULL, -1);
    // engine.board[56] = new Rook(0x100000000000000ULL, -1);

    engine.print_board();

    // std::vector<int> some_moves = engine.show_available_moves(engine.board, engine.board[56], -1);

    // std::cout << "--------------------------------------\n";
    // for(int i = 0; i < some_moves.size(); i++){
    //     std::cout << "moves for index " << i << "=" << some_moves[i]<< std::endl;
    // }
    // std::cout << "--------------------------------------\n";
    // std::cout << "end\n";

    std::vector<std::vector<int>> all_available_moves = engine.all_available_moves(engine.board, -1);

    std::cout << "--------------------------------------\n";
    for (size_t i = 0; i < all_available_moves.size(); i++) {
        std::cout << "Row " << i << ": ";
        for (size_t j = 0; j < all_available_moves[i].size(); j++) {
            std::cout << all_available_moves[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "--------------------------------------\n";
    std::cout << "end\n";


    return 0;
}