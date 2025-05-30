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
    Engine engine;
    Board someobj;

    Figure** board = new Figure*[64];
    for (int i = 0; i < 64; i++){
        board[i] = nullptr;
    }

    
    board[0] = new Rook(0x8000000000000000ULL, -1);
    board[1] = new Rook(0x4000000000000000ULL,-1);
    board[56] = new King(0x80ULL, 1);

    someobj.print_board(board);

    unsigned long long available_king_moves = 0;
    unsigned long long enemy_mask = board[0] -> mask | board[1] -> mask;
    unsigned long long teammate_mask = 0;
    unsigned long long king_mask = board[56] -> mask;
    int king_scope = 1;

    available_king_moves = engine.available_vertical_moves(available_king_moves, king_scope, king_mask, teammate_mask, enemy_mask);
    available_king_moves = engine.available_horizontal_moves(available_king_moves, king_scope, king_mask, teammate_mask, enemy_mask);
    available_king_moves = engine.available_diagonal_up_moves(available_king_moves, king_scope, king_mask, teammate_mask, enemy_mask);
    available_king_moves = engine.available_diagonal_down_moves(available_king_moves, king_scope, king_mask, teammate_mask, enemy_mask);

    print_bitboard(std::bitset<64>(available_king_moves).to_string());

    int check_var = engine.is_checked(board, king_mask, teammate_mask, enemy_mask, 1);
    int check_terminal = engine.is_terminal(board, king_mask, available_king_moves, teammate_mask, enemy_mask, 1);

    std::cout << "is checked: " << check_var << std::endl;
    std::cout << "is terminal: " << check_terminal << std::endl;




    for (int i = 0; i < 64; i++){
        delete board[i];
    }
    delete board;
    

    return 0;
}