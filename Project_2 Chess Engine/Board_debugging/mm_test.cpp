#include <iostream>
#include <bitset>

#include "../Pieces/Pieces.cpp"
#include "../Board/Board.cpp"
#include "../Engine/Engine.cpp"
#include "../Minimax/Minimax.cpp"

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
    Minimax engine;
    
    std::cout << "Test1:\n";
    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[0] = new King(0x1ULL, 1);
    engine.board[8] = new Rook(0x100ULL, 1);

    engine.board[63] = new King(0x8000000000000000ULL, -1);
    engine.board[56] = new Rook(0x100000000000000ULL, -1);

    engine.print_board();

    // engine.minimax(engine.board, 3, 1);
    // Figure** board, int depth, int maximizing_player)
    std::pair<int, int> best_move_in_position = engine.get_best_move(engine.board, 5, 1);

    std::cout << "best move is from: " << best_move_in_position.first << " to: " << best_move_in_position.second  << std::endl;

    return 0;
}