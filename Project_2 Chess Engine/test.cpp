#include <iostream>
#include <bitset>

#include "Pieces/Pieces.cpp"
#include "Board/Board.cpp"
#include "Engine/Engine.cpp"

#include "MovePolicy/MovePolicy.cpp"
#include "MovePolicy/KingCheckPolicy.cpp"
#include "MovePolicy/SpecialMoves.cpp"
#include "MovePolicy/FigureMoves.cpp"

void print_bitboard(std::string board){
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

    std:: cout << engine.evaluate_position();

    unsigned long long* aam = engine.all_available_moves(1);


    
    std::cout << "--------------------------------------\n";
    for(int i = 0; i < 64; i++){
        std::cout << "mask with index: " << i << std::endl << aam[i] << std::endl;
        print_bitboard(std::bitset<64>(aam[i]).to_string());
    }
    std::cout << "--------------------------------------\n";

    unsigned long long* aam2 = engine.all_available_moves(-1);
    for(int i = 0; i < 64; i++){
        std::cout << "mask with index: " << i << std::endl << aam[i] << std::endl;
        print_bitboard(std::bitset<64>(aam2[i]).to_string());
    }
    std::cout << "--------------------------------------\n";


    return 0;
}

