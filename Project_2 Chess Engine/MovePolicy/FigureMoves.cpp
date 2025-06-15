#include "FigureMoves.hpp"
#include <bitset>
#include <vector>
#include <stdexcept>
#include <memory>

void print_bitboardd(unsigned long long bitmask){
    std:: string board = std::bitset<64>(bitmask).to_string();
    for(int i = 0; i < 64; i++){
        std::cout << board[i];
        if ((i + 1) % 8 == 0){
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

unsigned long long FigureMoves::calculate_new_mask(int index) {
    if (index < 0 || index > 63) return 0;
    return 1ULL << index;
}

void FigureMoves::moveCastle(int old_index, int new_index, int color){

    switch (new_index)
    {
    case 1:
        move(0, 2, color);
        break;
    case 5:
        move(7, 4, color);
        break;
    case 57:
        move(56, 58, color);
        break;
    case 61:
        move(63, 60, color);
        break;
    default:
        break;
    }
}

void FigureMoves::move(int old_index, int new_index, int color){
    
    
    if (this -> board[old_index] != nullptr){
        
        if (this -> board[old_index] -> identifier == 5){
            if (abs(new_index - old_index) == 2){
                moveCastle(old_index, new_index, color);
            } 
        }
        if (((int) new_index / 8 == 7 || new_index / 8 == 0) && this -> board[old_index] -> identifier == 1){
            delete board[old_index];
            this -> board[old_index] = nullptr;
            this -> board[new_index] = new Queen(calculate_new_mask(new_index), color);
        }else{
            this -> board[new_index] = this ->board[old_index];
            this -> board[old_index] = nullptr;
            this -> board[new_index] -> mask = calculate_new_mask(new_index);
        }
    }
    this -> board[new_index] -> wasMovedFlag = 1;
}

bool FigureMoves::isTerminal(Figure** board, int color){
    if (findKing(board, 1) && findKing(board, -1)){
        return false;
    }
    return true;
}

void FigureMoves::move(Figure** board, int old_index, int new_index, int color){
    if (board[old_index] != nullptr){
        if (((int) new_index / 8 == 7 || new_index / 8 == 0) && board[old_index] -> identifier == 1){
            board[old_index] = nullptr;
            board[new_index] = new Queen(calculate_new_mask(new_index), color);
        }else{
            board[new_index] = board[old_index];
            board[old_index] = nullptr;
            board[new_index] -> mask = calculate_new_mask(new_index);
        }
    }
    else{
        std::cerr << "Unable to move from nullptr" << std::endl;
    }
}

Figure* FigureMoves::findKing(Figure** board, int color){
    for (int i = 0; i < 64; ++i) {
        if (board[i] != nullptr && board[i] -> identifier == 5 && board[i] -> color == color){
            return board[i];
        }
    }
    return nullptr;
}

Figure** FigureMoves::cloneBoard(Figure** board){
    Figure** temp_board = new Figure*[64];
        for (int i = 0; i < 64; ++i) {
        temp_board[i] = board[i] ? board[i]->clone() : nullptr;
    }
    return temp_board;
}

void FigureMoves::deleteBoard(Figure** board){
    for(int i = 0; i < 64; i++){
        delete board[i];
    }
    delete board;
}

bool FigureMoves::simulate_and_check(Figure** board, std::vector<int> &available_moves_eval, int old_index, int new_index, int color){
    unsigned long long king_mask = 0;
    Figure** temp_board = cloneBoard(board);
    move(temp_board, old_index, new_index, color);

    king_mask = findKing(temp_board, color) -> mask;
    if (color == 1){
        if (is_checked(temp_board, king_mask, white_mask(temp_board), black_mask(temp_board), color)){
            deleteBoard(temp_board);
            return 1;
        }
    }else if(color == -1){
        if (is_checked(temp_board, king_mask, black_mask(temp_board), white_mask(temp_board), color)){
            deleteBoard(temp_board);
            return 1;
        }
    }    
    available_moves_eval.push_back(new_index);
    deleteBoard(temp_board);
    return 0;
}

double FigureMoves::evaluate_position(Figure** board){
    double sum = 0;
    for(int i = 0; i < 64; i++){
        if (board[i] != nullptr){
            sum += ((board[i] -> cost) + get_additional_move_value(__builtin_ctzll(board[i] -> mask), board[i] -> identifier, board[i] -> color)) * (board[i] -> color);
        }
    }
    return sum;
}

double FigureMoves::get_additional_move_value(int index, int piece_type, int piece_color){
    float additional_value = 0;
    additional_value += center_pieces_mask[index];
    if (piece_color == 1){
        if (piece_type == 5){
            additional_value += white_king_mask[index];
        }
    }
    if (piece_color == -1){
        if (piece_type == 5){
            additional_value += black_king_mask[index];
        }
    }
    return additional_value;
}

void FigureMoves::available_horizontal_moves(Figure** board, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    int counter = 0, old_index, new_index;
    unsigned long long  second_figure_mask = figure_mask;
    old_index = __builtin_ctzll(figure_mask);
    while(counter++ < scope && !(figure_mask & left_move_mask)){
        figure_mask <<= 1;
        if (figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(figure_mask);
        if (simulate_and_check(board, available_moves_eval, old_index, new_index, color)){
            continue;
        }
        if (figure_mask & enemy_mask){
            break;
        }
    }
    counter = 0;
    old_index = __builtin_ctzll(second_figure_mask);
    while(counter++ < scope && !(second_figure_mask & right_move_mask)){
        second_figure_mask >>= 1;
        if (second_figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(second_figure_mask);
        if (simulate_and_check(board, available_moves_eval, old_index, new_index, color)){
            continue;
        }
        if (second_figure_mask & enemy_mask){
            break;
        }
    }
}
void FigureMoves::available_down_moves(Figure** board, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    if ((int) ((__builtin_ctzll(figure_mask)) / 8) == 6){
        scope = 2;
    }
    unsigned long long second_figure_mask = figure_mask;
    unsigned long long third_figure_mask = figure_mask;
    unsigned long long fourth_figure_mask = figure_mask;
    int counter = 0, new_index;
    int old_index = __builtin_ctzll(figure_mask);
    while(counter++ < scope && !(figure_mask & down_move_mask)){
        figure_mask >>= 8;
        if (figure_mask & teammate_mask || figure_mask & enemy_mask){
            break;
        }
        new_index = __builtin_ctzll(figure_mask);
        if (simulate_and_check(board, available_moves_eval, old_index, new_index, color)){
        continue;
        }
    }
    if (!(second_figure_mask & diagonal_left_down_move_mask)){
        second_figure_mask >>= 7;
        if(second_figure_mask & enemy_mask){
            new_index = __builtin_ctzll(second_figure_mask);
            simulate_and_check(board, available_moves_eval, old_index, new_index, color);
        }
    }
    if (!(third_figure_mask & diagonal_right_down_move_mask)){
        third_figure_mask >>= 9;
        if(third_figure_mask & enemy_mask){
            new_index = __builtin_ctzll(third_figure_mask);
            simulate_and_check(board, available_moves_eval, old_index, new_index, color);
        }
    }
}

void FigureMoves::available_up_moves(Figure** board, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    if ((int) ((__builtin_ctzll(figure_mask)) / 8) == 1){
        scope = 2;
    }
    unsigned long long second_figure_mask = figure_mask;
    unsigned long long third_figure_mask = figure_mask;
    unsigned long long fourth_figure_mask = figure_mask;
    int counter = 0;
    int old_index = __builtin_ctzll(figure_mask);
    int new_index;
    while(counter++ < scope && !(figure_mask & up_move_mask)){
        figure_mask <<= 8;
        if (figure_mask & teammate_mask || figure_mask & enemy_mask){
            break;
        }
        new_index = __builtin_ctzll(figure_mask);
        if (simulate_and_check(board, available_moves_eval, old_index, new_index, color)){
        continue;
        }
    }
    
    if (!(second_figure_mask & diagonal_left_up_move_mask)){
        second_figure_mask <<= 9;
        if(second_figure_mask & enemy_mask){
            new_index = __builtin_ctzll(second_figure_mask);
            simulate_and_check(board, available_moves_eval, old_index, new_index, color);
        }
    }
    
    if (!(third_figure_mask & diagonal_right_up_move_mask)){
        third_figure_mask <<= 7;
        if(third_figure_mask & enemy_mask){
            new_index = __builtin_ctzll(third_figure_mask);
            simulate_and_check(board, available_moves_eval, old_index, new_index, color);
        }
    }
}

void FigureMoves::available_vertical_moves(Figure** board, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    unsigned long long  second_figure_mask = figure_mask;
    int counter = 0, old_index, new_index;
    old_index = __builtin_ctzll(figure_mask);
    while(counter++ < scope && !(figure_mask & down_move_mask)){
        figure_mask >>= 8;
        new_index = __builtin_ctzll(figure_mask);
        if (figure_mask & teammate_mask){
            break;
        }
        if (simulate_and_check(board, available_moves_eval, old_index, new_index, color)){
            continue;
        }if (figure_mask & enemy_mask){
            break;
        }
    }

    counter = 0;
    while(counter++ < scope && !(second_figure_mask & up_move_mask)){
        second_figure_mask <<= 8;
        if (second_figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(second_figure_mask);
        if (simulate_and_check(board, available_moves_eval, old_index, new_index, color)){
            continue;
        }
        if (second_figure_mask & enemy_mask){
            break;
        }
    }
}

void FigureMoves::available_diagonal_up_moves(Figure** board, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    int counter = 0, old_index, new_index;
    unsigned long long  second_figure_mask = figure_mask;

    old_index = __builtin_ctzll(figure_mask);
    while(counter++ < scope && !(figure_mask & diagonal_left_up_move_mask)){
        figure_mask <<= 9;
        if (figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(figure_mask);
        if (simulate_and_check(board, available_moves_eval, old_index, new_index, color)){
            continue;
        }
        if (figure_mask & enemy_mask){
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(second_figure_mask & diagonal_right_up_move_mask)){
        second_figure_mask <<= 7;
        if (second_figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(second_figure_mask);
        if (simulate_and_check(board, available_moves_eval, old_index, new_index, color)){
            continue;
        }
        if (second_figure_mask & enemy_mask){
            break;
        }
    }
}
void FigureMoves::available_diagonal_down_moves(Figure** board, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    int counter = 0, old_index, new_index;
    unsigned long long  second_figure_mask = figure_mask;

    old_index = __builtin_ctzll(figure_mask);
    while(counter++ < scope && !(figure_mask & diagonal_left_down_move_mask)){
        figure_mask >>= 7;
        if (figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(figure_mask);
        if (simulate_and_check(board, available_moves_eval, old_index, new_index, color)){
            continue;
        }
        if (figure_mask & enemy_mask){
            break;
        }
    }
    counter = 0;
    while(counter++ < scope && !(second_figure_mask & diagonal_right_down_move_mask)){
        second_figure_mask >>= 9;
        if (second_figure_mask & teammate_mask){
            break;
        }
        new_index = __builtin_ctzll(second_figure_mask);
        if (simulate_and_check(board, available_moves_eval, old_index, new_index, color)){
            continue;
        }
        if (second_figure_mask & enemy_mask){
            break;
        }
    }
}

void FigureMoves::available_knight_moves(Figure** board, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color){
    unsigned long long figures_masks[8];
    for (int i = 0; i < 8; i++){
        figures_masks[i] = figure_mask;
    }
    int new_index, old_index;
    
    old_index = __builtin_ctzll(figure_mask);
    if(!(figures_masks[0] & knight_up_up_left_move_mask)){
        figures_masks[0] <<= 17;
        if(!(figures_masks[0] & teammate_mask)){
            new_index = __builtin_ctzll(figures_masks[0]);
            simulate_and_check(board, available_moves_eval, old_index, new_index, color);
        }

    }
    if(!(figures_masks[1] & knight_up_left_left_move_mask)){
        figures_masks[1] <<= 10;
        if (!(figures_masks[1] & teammate_mask)){      
            new_index = __builtin_ctzll(figures_masks[1]);
            simulate_and_check(board, available_moves_eval, old_index, new_index, color);
        }

    } 
    if(!(figures_masks[2] & knight_down_left_left_move_mask)){
        figures_masks[2]  >>= 6;
        if(!(figures_masks[2] & teammate_mask)){
            new_index = __builtin_ctzll(figures_masks[2] );
            simulate_and_check(board, available_moves_eval, old_index, new_index, color);  
        }
    }
    if(!(figures_masks[3]  & knight_down_down_left_move_mask)){
        figures_masks[3] >>= 15;
        if (!(figures_masks[3] & teammate_mask)){
            new_index = __builtin_ctzll(figures_masks[3]);
            simulate_and_check(board, available_moves_eval, old_index, new_index, color);
        }
    }
    if(!(figures_masks[4] & knight_up_up_right_move_mask)){
        figures_masks[4] <<= 15;
        if(!(figures_masks[4] & teammate_mask)){
            new_index = __builtin_ctzll(figures_masks[4]);
            simulate_and_check(board, available_moves_eval, old_index, new_index, color);
        }
    }
    if(!(figures_masks[5] & knight_up_right_right_move_mask)){
        figures_masks[5] <<= 6;
        if(!(figures_masks[5] & teammate_mask)){
            new_index = __builtin_ctzll(figures_masks[5] );
            simulate_and_check(board, available_moves_eval, old_index, new_index, color);
        }
    } 
    if(!(figures_masks[6]  & knight_down_right_right_move_mask)){
        figures_masks[6] >>= 10;
        if(!(figures_masks[6] & teammate_mask)){
            new_index = __builtin_ctzll(figures_masks[6]);
            simulate_and_check(board, available_moves_eval, old_index, new_index, color);
        }
    }
    if(!(figures_masks[7] & knight_down_down_right_move_mask)){
        figures_masks[7] >>= 17;
        if(!(figures_masks[7] & teammate_mask)){
            new_index = __builtin_ctzll(figures_masks[7]);
            simulate_and_check(board, available_moves_eval, old_index, new_index, color);
        }

    }
}


