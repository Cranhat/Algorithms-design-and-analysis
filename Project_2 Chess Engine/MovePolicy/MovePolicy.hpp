/*
Moving  up and down involves bit shift in amount of moves * rows, with taking int account edge cases,
Moving left and down involves bitwise left or right shift, taking into consideration left and right move mask,
Moving diagonally involves combining both operations,

All operations needs to be checked if king isnt check before move, after move, is draw because 50 moves without capture have been made, is piece in the way, and is piece in the destination
*/

class MovePolicy{
    protected:

    unsigned long long righ_move_mask = 72340172838076673; // 0000000100000001000000010000000100000001000000010000000100000001
    unsigned long long left_move_mask = 36170086419038336; // 1000000010000000100000001000000010000000100000001000000010000000

    // unsigned long long up_move_mask = 18374686479671623680;   // 1111111100000000000000000000000000000000000000000000000000000000
    unsigned long long up_move_mask = 0xFF00000000000000ULL;
    unsigned long long down_move_mask = 255; // 0000000000000000000000000000000000000000000000000000000011111111

    public:

    unsigned long long available_horizontal_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask);

    unsigned long long available_vertical_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask);

    unsigned long long available_diagonal_moves(unsigned long long moves_available, int scope, unsigned long long figure_mask);
    
};