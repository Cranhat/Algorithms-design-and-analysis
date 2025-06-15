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
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[0] = new King(0x1ULL, 1);
    engine.board[8] = new Rook(0x100ULL, 1);

    engine.board[58] = new King(0x400000000000000ULL, -1);
    engine.board[57] = new Rook(0x200000000000000ULL, -1);
    engine.board[56] = new Rook(0x100000000000000ULL, -1);

    engine.print_board();

    std::cout << engine.isCheckmate(engine.board, -1);

    return 0;
}