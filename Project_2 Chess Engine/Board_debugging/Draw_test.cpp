#include <iostream>
#include <bitset>

#include "../Pieces/Pieces.cpp"
#include "../Board/Board.cpp"
#include "../Engine/Engine.cpp"

#include "../MovePolicy/MovePolicy.cpp"
#include "../MovePolicy/KingCheckPolicy.cpp"
#include "../MovePolicy/SpecialMoves.cpp"
#include "../MovePolicy/FigureMoves.cpp"


void print_bitboard(unsigned long long bitmask){
    std:: string board = std::bitset<64>(bitmask).to_string();
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

    int check_var, mate_var;

    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[0] = new King(0x8000000000000000ULL, -1);
    engine.board[56] = new King(0x80ULL, 1);

    engine.print_board();

    unsigned long long white_king_available_moves = engine.show_available_moves(engine.board[56], 1);
    print_bitboard(white_king_available_moves);
    unsigned long long black_king_available_moves = engine.show_available_moves(engine.board[0], -1);
    print_bitboard(black_king_available_moves);

    check_var = engine.is_checked(engine.board, engine.board[56] -> mask, 0, engine.board[0] -> mask, 1);
    mate_var = engine.is_terminal(engine.board, engine.get_king_mask(1), white_king_available_moves, engine.white_mask(), engine.black_mask(), 1);
    std::cout << "check var: " << check_var << std::endl;
    std::cout << "mate var: " << mate_var << std::endl;

    return 0;
}