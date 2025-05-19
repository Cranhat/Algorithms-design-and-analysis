#include "KingCheckPolicy.hpp"
#include <iostream>
#include <stdint.h>
#include <stdio.h>

// __builtin_ctzll(bitboard)

// bool KingCheckPolicy::is_terminal(unsigned long long king_mask, unsigned long long available_king_moves){
//     if (is_checked(king_mask, 0, 0) & !available_king_moves){
//         return true;
//     }
//     return false;
// }

bool KingCheckPolicy::is_checked(unsigned long long king_mask, unsigned long long teammate_mask, unsigned long long enemy_mask){
    unsigned long long king_checking_figures = 0;
    int scope = 8;
    int index;
    int counter;
    unsigned long long copies[12];

    for (int i = 0; i < 12; i++) {
        copies[i] =  king_mask;
    }
    
    counter = 0;
    while(counter++ < scope && !(copies[1] & right_move_mask)){
        copies[1] >>= 1;
        if (copies[1] & teammate_mask){
            break;
        }else if (copies[1] & enemy_mask){

            index = __builtin_ctzll(copies[1]);
            std::cout << index << std::endl;
            if (board[index] -> identifier == 2 || board[index] -> identifier == 6){
                king_checking_figures |= copies[1];
            }
            break;
        }
    }

    counter = 0;
    while(counter++ < scope && !(copies[2] & left_move_mask)){
    
        copies[2] <<= 1;
        if (copies[2] & teammate_mask){
            break;
        }else if (copies[2] & enemy_mask){
            index = __builtin_ctzll(copies[2]);
            if (board[index] -> identifier == 2 || board[index] -> identifier == 6){
                king_checking_figures |= copies[2];
            }
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[3] & up_move_mask)){
    
        copies[3] >>= 8;
        if (copies[3] & teammate_mask){
            break;
        }else if (copies[3] & enemy_mask){
            index = __builtin_ctzll(copies[3]);
            if (board[index] -> identifier == 2 || board[index] -> identifier == 6){
                king_checking_figures |= copies[3];
            }
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[4] & down_move_mask)){
    
        copies[4] <<= 8;
        if (copies[4] & teammate_mask){
            break;
        }else if (copies[4] & enemy_mask){
            index = __builtin_ctzll(copies[4]);
            if (board[index] -> identifier == 2 || board[index] -> identifier == 6){
                king_checking_figures |= copies[4];
            }
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[5] & diagonal_right_up_move_mask)){
    
        copies[5] <<= 7;
        if (copies[5] & teammate_mask){
            break;
        }else if (copies[5] & enemy_mask){
            index = __builtin_ctzll(copies[5]);
            if (board[index] -> identifier == 3 || board[index] -> identifier == 6){
                king_checking_figures |= copies[5];
            }
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[6] & diagonal_left_up_move_mask)){
        copies[6] <<= 9;
        if (copies[6] & teammate_mask){
            break;
        }else if (copies[6] & enemy_mask){
            index = __builtin_ctzll(copies[6]);
            if (board[index] -> identifier == 3 || board[index] -> identifier == 6){
                king_checking_figures |= copies[6];
            }
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[7] & diagonal_right_down_move_mask)){
    
        copies[7] >>= 9;
        if (copies[7] & teammate_mask){
            break;
        }else if (copies[7] & enemy_mask){
            index = __builtin_ctzll(copies[7]);
            if (board[index] -> identifier == 4 || board[index] -> identifier == 6){
                king_checking_figures |= copies[7];
            }
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[8] & diagonal_left_down_move_mask)){
        copies[8] >>= 7;
        if (copies[8] & teammate_mask){
            break;
        }else if (copies[8] & enemy_mask){
            index = __builtin_ctzll(copies[8]);
            if (board[index] -> identifier == 4 || board[index] -> identifier == 6){
                king_checking_figures |= copies[8];
            }
            break;
        }
    }

    if(king_checking_figures){
        return true;
    }else{
        return false;
    }

}
