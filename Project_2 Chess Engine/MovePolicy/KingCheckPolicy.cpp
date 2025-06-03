#include "KingCheckPolicy.hpp"
#include <iostream>
#include <stdint.h>
#include <stdio.h>

//__builtin_ctzll(bitboard) // returns first positive bit lavue index from right
//__builtin_clzll(bitboard) // returns first positive bit lavue index from left

bool KingCheckPolicy::is_terminal(Figure** board, unsigned long long king_mask, unsigned long long available_king_moves, unsigned long long teammate_mask, unsigned long long enemy_mask, int color){
    if (is_checked(board, king_mask, teammate_mask, enemy_mask, color) & !available_king_moves){
        return true;
    }
    return false;
}

bool KingCheckPolicy::is_checked(Figure** board,unsigned long long king_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, int color){
    unsigned long long king_checking_figures = 0;
    int scope = 8;
    int index;
    int counter;
    unsigned long long copies[16];


    for (int i = 0; i < 16; i++) {
        copies[i] = king_mask;
    }
    
    counter = 0;
    while(counter++ < scope && !(copies[0] & right_move_mask)){
        copies[0] >>= 1;
        if (copies[1] & teammate_mask){
            break;
        }else if (copies[0] & enemy_mask){

            index = __builtin_ctzll(copies[0]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 2 || board[index] -> identifier == 6 || (counter == 1 && (board[index] -> identifier == 5))){
                    king_checking_figures |= copies[1];
                }
            }
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[1] & left_move_mask)){
    
        copies[1] <<= 1;
        if (copies[1] & teammate_mask){
            break;
        }else if (copies[1] & enemy_mask){
            index = __builtin_ctzll(copies[1]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 2 || board[index] -> identifier == 6 || (counter == 1 && (board[index] -> identifier == 5))){
                    king_checking_figures |= copies[1];
                }
            }
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[2] & up_move_mask)){
        copies[2] <<= 8;
        if (copies[2] & teammate_mask){
            break;
        }else if (copies[2] & enemy_mask){
            index = __builtin_ctzll(copies[2]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 2 || board[index] -> identifier == 6 || (counter == 1 && (board[index] -> identifier == 5))){
                    king_checking_figures |= copies[2];
                }
            }

            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[3] & down_move_mask)){
    
        copies[3] >>= 8;
        if (copies[3] & teammate_mask){
            break;
        }else if (copies[3] & enemy_mask){
            
            index = __builtin_ctzll(copies[3]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 2 || board[index] -> identifier == 6 || (counter == 1 && (board[index] -> identifier == 5))){
                    king_checking_figures |= copies[3];
                }
            }
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[4] & diagonal_right_up_move_mask)){
    
        copies[4] <<= 7;
        if (copies[4] & teammate_mask){
            break;
        }else if (copies[4] & enemy_mask){
            index =__builtin_ctzll(copies[4]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 4 || board[index] -> identifier == 6 || (counter == 1 && (board[index] -> identifier == 5)) || (color == 1 && counter == 1 && (board[index] -> identifier == 1))){
                    king_checking_figures |= copies[4];
                }
            }
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[5] & diagonal_left_up_move_mask)){
        copies[5] <<= 9;
        if (copies[5] & teammate_mask){
            break;
        }else if (copies[5] & enemy_mask){
            index =__builtin_ctzll(copies[5]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 4 || board[index] -> identifier == 6 || (counter == 1 && (board[index] -> identifier == 5)) || (color == 1 && counter == 1 && (board[index] -> identifier == 1))){
                    king_checking_figures |= copies[5];
                }
            }
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[6] & diagonal_right_down_move_mask)){
    
        copies[6] >>= 9;
        if (copies[6] & teammate_mask){
            break;
        }else if (copies[6] & enemy_mask){
            index =__builtin_ctzll(copies[6]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 4 || board[index] -> identifier == 6 || (counter == 1 && (board[index] -> identifier == 5)) || (color == -1 && counter == 1 && (board[index] -> identifier == 1))){
                    king_checking_figures |= copies[6];
                }
            }
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(copies[7] & diagonal_left_down_move_mask)){
        copies[7] >>= 7;
        if (copies[7] & teammate_mask){
            break;
        }else if (copies[7] & enemy_mask){
            index =__builtin_ctzll(copies[7]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 4 || board[index] -> identifier == 6 || (counter == 1 && (board[index] -> identifier == 5)) || (color == -1 && counter == 1 && (board[index] -> identifier == 1))){
                    king_checking_figures |= copies[7];
                }
            }
            break;
        }
    }
    if(!(copies[8] & knight_up_up_left_move_mask)){
        copies[8] <<= 17;
        if (copies[8] & enemy_mask){
            index =__builtin_ctzll(copies[8]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 3){
                    king_checking_figures |= copies[8];
                }
            }
        }
    }
    if(!(copies[9] & knight_up_left_left_move_mask)){
        copies[9] <<= 10;
        if (copies[9] & enemy_mask){
            index =__builtin_ctzll(copies[9]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 3){
                    king_checking_figures |= copies[9];
                }
            }
        }
    } 
    if(!(copies[10]& knight_down_left_left_move_mask)){
        copies[10] >>= 6;
        if (copies[10] & enemy_mask){
            index =__builtin_ctzll(copies[10]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 3){
                    king_checking_figures |= copies[10];
                }
            }
        }
    }
    if(!(copies[11] & knight_down_down_left_move_mask)){
        copies[11] >>= 15;
        if (copies[11] & enemy_mask){
            index =__builtin_ctzll(copies[11]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 3){
                    king_checking_figures |= copies[11];
                }
            }
        }
    }
    if(!(copies[12] & knight_up_up_right_move_mask)){
        copies[12] <<= 15;
        if (copies[12] & enemy_mask){
            index =__builtin_ctzll(copies[12]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 3){
                    king_checking_figures |= copies[12];
                }
            }
        }
    }
    if(!(copies[13] & knight_up_right_right_move_mask)){
        copies[13] <<= 6;
        if (copies[13] & enemy_mask){
            index =__builtin_ctzll(copies[13]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 3){
                    king_checking_figures |= copies[13];
                }
            }
        }
    } 
    if(!(copies[14] & knight_down_right_right_move_mask)){
        copies[14] >>= 10;
        if (copies[14] & enemy_mask){
            index =__builtin_ctzll(copies[14]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 3){
                    king_checking_figures |= copies[14];
                }
            }
        }
    }
    if(!(copies[15] & knight_down_down_right_move_mask)){
        copies[15] >>= 17;
        if (copies[15] & enemy_mask){
            index =__builtin_ctzll(copies[15]);
            if (board[index] != nullptr){
                if (board[index] -> identifier == 3){
                    king_checking_figures |= copies[15];
                }
            }
        }
    }
    if(king_checking_figures){
        return true;
    }else{
        return false;
    }
}
