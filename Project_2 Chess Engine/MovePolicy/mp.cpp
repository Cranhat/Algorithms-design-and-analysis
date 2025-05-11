#include <iostream>
#include <bitset>
#include <string>

#include "MovePolicy.cpp"
#include "../Board/Board.cpp"

void print_board(std::string board){
    for(int i = 0; i < 64; i++){
        std::cout << board[i];
        if ((i + 1) % 8 == 0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int main(){ 

    MovePolicy mp;

    Board board;

    unsigned long long black_mask = board.black_mask();

    unsigned long long white_mask = board.white_mask();

    unsigned long long moves_available = 0;

    unsigned long long figure_mask = 0x8000000ULL;


    // print_board(std::bitset<64>(black_mask).to_string());


    board.print_board();
    print_board(std::bitset<64>(figure_mask).to_string());

    moves_available = mp.available_horizontal_moves(moves_available, 8, figure_mask, white_mask, black_mask);
    print_board(std::bitset<64>(moves_available).to_string());

    moves_available = mp.available_vertical_moves(moves_available, 8, figure_mask, white_mask, black_mask);
    print_board(std::bitset<64>(moves_available).to_string());

    moves_available = mp.available_diagonal_up_moves(moves_available, 8, figure_mask, white_mask, black_mask);
    print_board(std::bitset<64>(moves_available).to_string());
   
    moves_available = mp.available_diagonal_down_moves(moves_available, 8, figure_mask, white_mask, black_mask);
    print_board(std::bitset<64>(moves_available).to_string()); 





    return 0; 
}



/* 
00000000
00000000
00000000
00000000
00001000
00000000
00000000
00000000
*/
