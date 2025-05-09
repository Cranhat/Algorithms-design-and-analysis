/*
Moving  up and down involves bit shift in amount of moves * rows, with taking int account edge cases,
Moving left and down involves bitwise left or right shift, taking into consideration left and right move mask,
Moving diagonally involves combining both operations,

All operations needs to be checked if king isnt check before move, after move, is draw because 50 moves without capture have been made, is piece in the way, and is piece in the destination
*/

class MovePolicy{
    protected:

    unsigned long long righ_move_mask = 72340172838076673; // 0000000100000001000000010000000100000001000000010000000100000001
    unsigned long long left_move_mask = 36170086419038336; // 10000000100000001000000010000000100000001000000010000000

    public:
    
};