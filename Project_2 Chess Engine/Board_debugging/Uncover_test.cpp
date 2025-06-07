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
    Engine engine;

    unsigned long long* aam = new unsigned long long[64];
    int check_var, mate_var;
    std::cout << "Test1:\n";
    std::cout << "-------------------------------" << std::endl;
    for (int i = 0; i < 64; i++){
        engine.board[i] = nullptr;
    }
    engine.board[0] = new King(0x1ULL, 1);
    engine.board[8] = new Rook(0x100ULL, 1);

    engine.board[56] = new Rook(0x100000000000000ULL, -1);

    engine.print_board();

   
    std::vector<std::vector<int>> all_available_moves = engine.all_available_moves(engine.board, 1);

    std::cout << "--------------------------------------\n";
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < all_available_moves[i].size(); j++){
            std::cout << "i = " << i << " j = " << j << " available moves: " << all_available_moves[i][j] << std::endl;
        }
    }

    std::cout << "--------------------------------------\n";
    std::cout << "end\n";

    
    // check_var = engine.is_checked(engine.board, engine.board[0] S-> mask, 0, engine.board[0] -> mask, 1);
    // unsigned long long king_available_moves = aam[0];
    // unsigned long long rook_available_moves = aam[8];
    // mate_var = engine.is_terminal(engine.board, engine.get_king_mask(1), king_available_moves, engine.white_mask(), engine.black_mask(), 1);
    // // std::cout << "king available moves:\n"; 
    // // print_bitboard(king_available_moves);
    // // std::cout << "rook available moves:\n"; 
    // // print_bitboard(rook_available_moves);
    // std::cout << "check var: " << check_var << std::endl;
    // std::cout << "mate var: " << mate_var << std::endl;
    // std::cout << "-------------------------------" << std::endl;

    
    // std::cout << "Test2:\n";
    // std::cout << "-------------------------------" << std::endl;
    // for (int i = 0; i < 64; i++){
    //     engine.board[i] = nullptr;
    // }
    // engine.board[0] = new King(0x1ULL, 1);
    // engine.board[8] = new Rook(0x100ULL, 1);
    // engine.board[57] = new Rook(0x200000000000000ULL, -1);
    // engine.board[56] = new Rook(0x100000000000000ULL, -1);

    // engine.print_board();
    // all_available_moves = engine.all_available_moves(1);

    // // unsigned long long king_available_moves = aam[0];
    // // unsigned long long rook_available_moves = aam[8];

    // // std::cout << "white mask: " << std::endl;
    // // print_bitboard(engine.white_mask());
    // // std::cout << "black mask: " << std::endl;
    // // print_bitboard(engine.black_mask());
    // // std::cout << "king mask: " << std::endl;
    // // print_bitboard(engine.get_king_mask(1));

    // check_var = engine.is_checked(engine.board, engine.board[0] -> mask, engine.white_mask(), engine.black_mask(), 1);
    
    // mate_var = engine.is_terminal(engine.board, engine.board[0] -> mask, king_available_moves, engine.white_mask(), engine.black_mask(), 1);

    // std::cout << "king available moves:\n"; 
    // print_bitboard(king_available_moves);
    // std::cout << "rook available moves:\n"; 
    // print_bitboard(rook_available_moves);
    // std::cout << "check var: " << check_var << std::endl;
    // std::cout << "mate var: " << mate_var << std::endl;
    // std::cout << "-------------------------------" << std::endl;

    return 0;
}