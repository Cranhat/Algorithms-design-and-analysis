#include <iostream>
#include <bitset>

#include "Pieces/Pieces.cpp"
#include "Board/Board.cpp"
#include "Engine/Engine.cpp"

#include "MovePolicy/MovePolicy.cpp"
#include "MovePolicy/KingCheckPolicy.cpp"
#include "MovePolicy/SpecialMoves.cpp"
#include "MovePolicy/FigureMoves.cpp"
#include "Minimax/Minimax.cpp"

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

    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[0] = new King(0x1ULL, 1);
    engine.board[8] = new Rook(0x100ULL, 1);
    engine.board[58] = new King(0x400000000000000ULL, -1);
    engine.board[57] = new Rook(0x200000000000000ULL, -1);
    engine.board[56] = new Rook(0x100000000000000ULL, -1);

    engine.Board::print_board();
    std::cout << "--------------" << std::endl;
    std:: cout << "pos eval" << engine.evaluate_position() << std::endl;
    std::cout << "minmax start\n";
    engine.minimax(engine.board, 3, 1);
    std::cout << "minmax end\n";
    std::cout << "--------------" << std::endl;

    return 0;
}

