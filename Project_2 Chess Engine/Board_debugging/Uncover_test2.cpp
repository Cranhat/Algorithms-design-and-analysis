#include <iostream>
#include <bitset>

#include "../Pieces/Pieces.cpp"
#include "../Board/Board.cpp"
#include "../Engine/Engine.cpp"

#include "../MovePolicy/MovePolicy.cpp"
#include "../MovePolicy/KingCheckPolicy.cpp"
#include "../MovePolicy/SpecialMoves.cpp"
#include "../MovePolicy/FigureMoves.cpp"


void print_bitboard(std::string board){
    for(int i = 0; i < 64; i++){
        std::cout << board[i];
        if ((i + 1) % 8 == 0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

/*
0 1 2 3 4 5 6 7
8 ...
*/

int main(){
    // Engine engine;
    Engine board;

    for (int i = 0; i < 64; i++){
        board.board[i] = nullptr;
    }

    
    board.board[0] = new King(0x8000000000000000ULL, 1);
    board.board[1] = new Rook(0x4000000000000000ULL, 1);
    board.board[7] = new Rook(0x100000000000000ULL,-1);
    board.board[15] = new Rook(0x1000000000000ULL, -1);


    board.print_board();

    print_bitboard(std::bitset<64>(board.show_available_moves(board.board[1], 1)).to_string());

    // print_bitboard(std::bitset<64>(board.show_available_moves(board.board[7], -1)).to_string());

    // std::cout << "--------------------------------------\n";
    // for(int i = 0; i < 64; i++){
    //     if (aam[i] != 0){
    //         std::cout << "mask with index: " << i << std::endl << aam[i] << std::endl;
    //         print_bitboard(std::bitset<64>(aam[i]).to_string());
    //     }

    // }
    // std::cout << "--------------------------------------\n";

    // std::cout << "end\n"; 

    return 0;
}