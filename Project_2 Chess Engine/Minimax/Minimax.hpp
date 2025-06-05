#pragma once
#include "../Engine/Engine.hpp"

class Minimax : public Engine{
    public:
    double minimax(Figure** board, int depth, int maximizing_player);

};
