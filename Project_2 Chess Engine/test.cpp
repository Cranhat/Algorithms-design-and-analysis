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

    // std:: cout << engine.evaluate_position();

    unsigned long long* aam = new unsigned long long[64];

    aam = engine.all_available_moves(-1);


    
    std::cout << "--------------------------------------\n";
    for(int i = 0; i < 64; i++){
        std::cout << "mask with index: " << i << std::endl << aam[i] << std::endl;
        print_bitboard(aam[i]);
    }
    std::cout << "--------------------------------------\n";
    std::cout << "end\n";

    delete[] aam;
    return 0;
}

