#pragma once
#include <vector>
#include "KingCheckPolicy.hpp"
#include "SpecialMoves.hpp"
#include "../Board/Board.hpp"
#include "Masks.hpp"

class FigureMoves : public KingCheckPolicy, public Board {
    public:

    void available_horizontal_moves(Figure** bord, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    void available_vertical_moves(Figure** bord, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    void available_diagonal_up_moves(Figure** bord, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    void available_diagonal_down_moves(Figure** bord, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    void available_knight_moves(Figure** bord, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    void available_up_moves(Figure** bord, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    void available_down_moves(Figure** bord, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

    bool simulate_and_check(Figure** board, std::vector<int> &available_moves_eval, int old_index, int new_index, int color);

    unsigned long long calculate_new_mask(int new_index);

    void move(int old_index, int new_index, int color);

    void move(Figure** board, int old_index, int new_index, int color);

    double evaluate_position(Figure** board);

    double get_additional_move_value(int index, int piece_type, int piecie_color);

    Figure* findKing(Figure** board, int color);

    Figure** cloneBoard(Figure** board);

    bool is_terminal(Figure** board, int color);

    void moveCastle(int old_index, int new_index, int color);

    void deleteBoard(Figure** board);
};
