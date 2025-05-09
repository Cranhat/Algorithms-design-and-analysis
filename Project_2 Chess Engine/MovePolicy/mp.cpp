#include <iostream>
#include <bitset>

#include "MovePolicy.cpp"
// unsigned long long white_pawns = 65280; // 0000000000000000000000000000000000000000000000001111111100000000
// unsigned long long black_pawns = 71776119061217280; // 0000000011111111000000000000000000000000000000000000000000000000
    
// unsigned long long white_rooks= 129; // 0000000000000000000000000000000000000000000000000000000010000001
// unsigned long long black_rooks = 9295429630892703744; // 1000000100000000000000000000000000000000000000000000000000000000
    
// unsigned long long white_horses = 66; // 0000000000000000000000000000000000000000000000000000000001000010
// unsigned long long black_horses = 4755801206503243776; // 0100001000000000000000000000000000000000000000000000000000000000
    
// unsigned long long white_bishops = 36; // 0000000000000000000000000000000000000000000000000000000000100100
// unsigned long long black_bishops = 2594073385365405696; // 0010010000000000000000000000000000000000000000000000000000000000
    
// unsigned long long white_king = 16; // 0000000000000000000000000000000000000000000000000000000000010000
// unsigned long long black_king = 1152921504606846976; // 0001000000000000000000000000000000000000000000000000000000000000
    
// unsigned long long white_queen = 8; // 0000000000000000000000000000000000000000000000000000000000001000
// unsigned long long black_queen= 576460752303423488; // 0000100000000000000000000000000000000000000000000000000000000000

// unsigned long long left_move_mask = 72340172838076673; // 0000000100000001000000010000000100000001000000010000000100000001
// unsigned long long right_move_mask = 36170086419038336; // 1000000010000000100000001000000010000000100000001000000010000000

int Board[64] = {
    -2, -3, -4, -5, -6, -4, -3, -2,
    -1, -1, -1, -1, -1, -1, -1, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    2, 3, 4, 5, 6, 4, 3, 2}; // access via 8 * r + c

// void print_board(int* board){
//     for(int i = 0; i < 64; i++){
//         std::cout << board[i];
//         if ((i + 1) % 8 == 0){
//             std::cout << std::endl;
//         }
//     }
// }

int main(){ 
    // unsigned long long left_move_mask = 72340172838076673; // 0000000100000001000000010000000100000001000000010000000100000001
    // unsigned long long right_move_mask = 36170086419038336; // 1000000010000000100000001000000010000000100000001000000010000000

    // unsigned long long figure_mask = 4294967296;           // 0000000000000000000000000000000100000000000000000000000000000000
    // printf("operation: %llu \n", (figure_mask & right_move_mask));

    // std::cout << "right_move_mask: " << std::bitset<64>(right_move_mask) << std::endl;
    // std::cout << "figure_mask:     " << std::bitset<64>(figure_mask) << std::endl;
    // std::cout << "operation:       " << std::bitset<64>(figure_mask & right_move_mask) << std::endl;

    unsigned long long figure_mask = 8589934592;     // 0000000000000000000000000000001000000000000000000000000000000000
    unsigned long long moves_available = 0;
    MovePolicy mp;

    std::cout << "operation:       " << std::bitset<64>(moves_available) << std::endl;
    moves_available = mp.available_horizontal_moves(moves_available, 2, figure_mask);

    std::cout << "operation:       " << std::bitset<64>(moves_available) << std::endl;
    moves_available = mp.available_vertical_moves(moves_available, 2, figure_mask);

    std::cout << "operation:       " << std::bitset<64>(moves_available) << std::endl;
    return 0; 
}



/* 
00000000
00000000
00000000
00000010
00000000
00000000
00000000
00000000
*/
/*
00000000
00000010
00000010
00001101
00000010
00000010
00000000
00000000
*/
