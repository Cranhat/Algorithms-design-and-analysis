#pragma once

class SpecialMoves{
    unsigned long long white_castle_left_bitboard = 0x70ULL;
    unsigned long long white_castle_right_bitboard = 0x6ULL;

    unsigned long long black_castle_left_bitboard = 0x600000000000000ULL;
    unsigned long long black_castle_right_bitboard = 0x7000000000000000ULL;
    public:
    void is_castle_available(Figure** board, std::vector<int> &available_moves_eval, int scope, unsigned long long figure_mask, unsigned long long teammate_mask, unsigned long long enemy_mask, unsigned long long king_mask, int color);

};