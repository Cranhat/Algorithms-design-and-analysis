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

int main(){
    Engine engine;

    int check_var;

    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[56] = new Pawn(0x100000000000000ULL, -1);
    engine.board[0] = new King(0x1ULL, 1);

    engine.print_board();

    check_var = engine.is_checked(engine.board, engine.board[56] -> mask, 0, engine.board[0] -> mask, 1);
    std::cout << check_var << std::endl;

    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[56] = new Rook(0x100000000000000ULL, -1);
    engine.board[0] = new King(0x1ULL, 1);

    engine.print_board();

    check_var = engine.is_checked(engine.board, engine.board[56] -> mask, 0, engine.board[0] -> mask, 1);
    std::cout << check_var << std::endl;

    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[56] = new Knight(0x100000000000000ULL, -1);
    engine.board[0] = new King(0x1ULL, 1);

    engine.print_board();

    check_var = engine.is_checked(engine.board, engine.board[56] -> mask, 0, engine.board[0] -> mask, 1);
    std::cout << check_var << std::endl;

    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[56] = new Bishop(0x100000000000000ULL, -1);
    engine.board[0] = new King(0x1ULL, 1);

    engine.print_board();

    check_var = engine.is_checked(engine.board, engine.board[56] -> mask, 0, engine.board[0] -> mask, 1);
    std::cout << check_var << std::endl;

    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[56] = new King(0x100000000000000ULL, -1);
    engine.board[0] = new King(0x1ULL, 1);

    engine.print_board();

    check_var = engine.is_checked(engine.board, engine.board[56] -> mask, 0, engine.board[0] -> mask, 1);
    std::cout << check_var << std::endl;

    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[56] = new Queen(0x100000000000000ULL, -1);
    engine.board[0] = new King(0x1ULL, 1);

    engine.print_board();

    check_var = engine.is_checked(engine.board, engine.board[56] -> mask, 0, engine.board[0] -> mask, 1);
    std::cout << check_var << std::endl;

    std::cout << "-------------------------------" << std::endl; 
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[9] = new Bishop(0x200ULL, -1);
    engine.board[0] = new King(0x1ULL, 1);

    engine.print_board();

    check_var = engine.is_checked(engine.board, engine.board[56] -> mask, 0, engine.board[49] -> mask, 1);
    std::cout << check_var << std::endl;

    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[10] = new Knight(0x400ULL, -1);
    engine.board[0] = new King(0x1ULL, 1);

    engine.print_board();

    check_var = engine.is_checked(engine.board, engine.board[56] -> mask, 0, engine.board[50] -> mask, 1);
    std::cout << check_var << std::endl;

    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[1] = new Pawn(0x2ULL, 1);
    engine.board[8] = new Pawn(0x100ULL, 1);
    engine.board[10] = new Knight(0x400ULL, -1);
    engine.board[0] = new King(0x1ULL, 1);
    engine.board[9] = new Pawn(0x200ULL, 1);

    engine.print_board();

    check_var = engine.is_checked(engine.board, engine.board[56] -> mask, 0, engine.board[50] -> mask, 1);
    std::cout << check_var << std::endl;

    return 0;
}