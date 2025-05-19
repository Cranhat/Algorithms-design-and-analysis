#include <iostream>
#include <bitset>
#include <string>

#include "../Board/Board.cpp"
#include "MovePolicy.cpp"
#include "KingCheckPolicy.cpp"
#include "../Pieces/Pieces.cpp"

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

    KingCheckPolicy kp;

    unsigned long long black_mask = board.black_mask();

    unsigned long long white_mask = board.white_mask();

    unsigned long long moves_available = 0;

    unsigned long long figure_mask = 0x80000000ULL;


    board.print_board();
    std::cout << "figure mask:" << std::endl;
    print_board(std::bitset<64>(figure_mask).to_string());
    
    // moves_available = mp.available_horizontal_moves(moves_available, 8, figure_mask, white_mask, black_mask);
    // print_board(std::bitset<64>(moves_available).to_string());

    // moves_available = mp.available_vertical_moves(moves_available, 8, figure_mask, white_mask, black_mask);
    // print_board(std::bitset<64>(moves_available).to_string());

    // moves_available = mp.available_diagonal_up_moves(moves_available, 8, figure_mask, white_mask, black_mask);
    // print_board(std::bitset<64>(moves_available).to_string());
   
    // moves_available = mp.available_diagonal_down_moves(moves_available, 8, figure_mask, white_mask, black_mask);
    // print_board(std::bitset<64>(moves_available).to_string()); 
    
    
    
    bool is_king_checked;

    // is_king_checked = kp.is_checked(figure_mask, white_mask, black_mask);
    is_king_checked = kp.is_checked(figure_mask, black_mask, white_mask);
    std::cout << is_king_checked << std::endl;

    // moves_available = mp.available_knight_moves(moves_available, 1, figure_mask, white_mask, black_mask);
    // print_board(std::bitset<64>(moves_available).to_string()); 

    return 0; 
}



/* 
00000000
00000000
00000000
00000000
10000000
00000000
00000000
00000000

80000000
*/


/* 
00000000
00000000
00000000
00000000
00000001
00000000
00000000
00000000

1000000
*/