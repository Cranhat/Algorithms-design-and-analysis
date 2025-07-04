#pragma once

#include <string>
#include <iostream>
#include "../Pieces/Pieces.hpp"

/*
Board = 
{-2, -3, -4, -5, -6, -4, -3, -2},
{1, 1, 1, 1, 1, 1, 1, 1},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0},
{1, 1, 1, 1, 1, 1, 1, 1},
{2, 3, 4, 5, 6, 4, 3, 2}
rows = 8,
cols = 8
*/
/*
whites:
pawn = 1,
rook = 2,
horse = 3, 
bishop = 4,
queen = 6, 
king = 5

blacks:
pawn = 1,
rook = -2,
horse = -3, 
bishop = -4,
queen = -6, 
king = -5
*/


class Board{
    public:
    
    Figure** board =  new Figure*[64];
    Figure* white_king_pointer;
    Figure* black_king_pointer;
    int turn_counter = 0;

    Board(){
                
        for (int i = 0; i < 64; i++){
            board[i] = nullptr;
        }
        
        board[0] = new Rook(0x1ULL, 1);
        board[1] = new Knight(0x2ULL, 1);
        board[2] = new Bishop(0x4ULL, 1);
        board[3] = new King(0x8ULL, 1);
        board[4] = new Queen(0x10ULL, 1);
        board[5] = new Bishop(0x20ULL, 1);
        board[6] = new Knight(0x40LL, 1);
        board[7] = new Rook(0x80ULL, 1);

        board[8] = new Pawn(0x100ULL, 1);
        board[9] = new Pawn(0x200ULL, 1);
        board[10] = new Pawn(0x400ULL, 1);
        board[11] = new Pawn(0x800ULL, 1);
        board[12] = new Pawn(0x1000ULL, 1);
        board[13] = new Pawn(0x2000ULL, 1);
        board[14] = new Pawn(0x4000ULL, 1);
        board[15] = new Pawn(0x8000ULL, 1);


        board[48] = new Pawn(0x1000000000000ULL, -1);
        board[49] = new Pawn(0x2000000000000ULL, -1);
        board[50] = new Pawn(0x4000000000000ULL, -1);
        board[51] = new Pawn(0x8000000000000ULL, -1);
        board[52] = new Pawn(0x10000000000000ULL, -1);
        board[53] = new Pawn(0x20000000000000ULL, -1);
        board[54] = new Pawn(0x40000000000000ULL, -1);
        board[55] = new Pawn(0x80000000000000ULL, -1);

        board[56] = new Rook(0x100000000000000ULL, -1);
        board[57] = new Knight(0x200000000000000ULL, -1);
        board[58] = new Bishop(0x400000000000000ULL, -1);
        board[59] = new King(0x800000000000000ULL, -1);
        board[60] = new Queen(0x1000000000000000ULL, -1);
        board[61] = new Bishop(0x2000000000000000ULL, -1);
        board[62] = new Knight(0x4000000000000000ULL, -1);
        board[63] = new Rook(0x8000000000000000ULL, -1);

        white_king_pointer = board[59];
        black_king_pointer = board[3];
    }

    

    ~Board(){
        for (int i = 0; i < 64; i++){
            delete board[i];
        }
        delete board;
        delete white_king_pointer;
        delete black_king_pointer;
    }

    void print_board();

    void print_board(Figure** temp_board);

    unsigned long long black_mask();

    unsigned long long white_mask();

    unsigned long long black_mask(Figure** temp_board);

    unsigned long long white_mask(Figure** temp_board);

    unsigned long long get_king_mask(int color);
    
};