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
is_checked(Figure** board, unsigned long long king_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, int color)
*/

/*
0 1 2 3 4 5 6 7
8 ...
*/
int main(){
    Engine engine;
    Board someobj;

    Figure** board = new Figure*[64];
    for (int i = 0; i < 64; i++){
        board[i] = nullptr;
    }

    
    board[0] = new Rook(0x8000000000000000ULL, -1);
    // board[1] = new Rook(0x4000000000000000ULL,-1);
    board[56] = new King(0x80ULL, 1);

    someobj.print_board(board);


    int check_var = engine.is_checked(board, board[56] -> mask, 0, board[0] -> mask, 1);
    std::cout << check_var << std::endl;




    for (int i = 0; i < 64; i++){
        delete board[i];
    }
    delete board;
    

    return 0;
}