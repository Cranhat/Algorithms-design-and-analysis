#pragma once

#include "MovePolicy.hpp"
#include "../Board/Board.hpp"

class KingCheckPolicy : public MovePolicy{
    public:
    
    bool is_terminal(unsigned long long king_mask, unsigned long long available_king_moves, unsigned long long teammate_mask, unsigned long long enemy_mask, int color);

    bool is_checked(unsigned long long king_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, int color);
};