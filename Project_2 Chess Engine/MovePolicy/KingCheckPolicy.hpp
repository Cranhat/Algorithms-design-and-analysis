#pragma once

#include "FigureMoves.hpp"
#include "../Board/Board.hpp"


class KingCheckPolicy : public FigureMoves{
    public:
    
    bool is_terminal(Figure** board, unsigned long long king_mask, unsigned long long available_king_moves, unsigned long long teammate_mask, unsigned long long enemy_mask, int color);

    bool is_checked(Figure** board, unsigned long long king_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, int color);
};