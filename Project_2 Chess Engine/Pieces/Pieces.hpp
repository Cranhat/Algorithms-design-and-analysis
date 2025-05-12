#pragma once

#include <string>

struct Figure{
    std::string type;
    int identifier;
    unsigned long long mask;
    int color; // 1 - white, -1 - black

    virtual ~Figure() = default;
    Figure(std::string type, int identifier, unsigned long long mask, int color)
    : type(type), identifier(identifier), mask(mask), color(color) {}


};

struct Pawn : public Figure{

    Pawn(unsigned long long mask, int color) : Figure("pawn", 1, mask, color){
        this -> mask = mask;
        this -> color = color;
    }

    ~Pawn() override {}
};

struct Rook : public Figure{

    Rook(unsigned long long mask, int color) : Figure("rook", 2, mask, color){
        this -> mask = mask;
        this -> color = color;
    }
    ~Rook() override {}
};

struct Horse : public Figure{

    Horse(unsigned long long mask, int color)  : Figure("horse", 3, mask, color){
        this -> mask = mask;
        this -> color = color;
    }
    ~Horse() override {}

};

struct Bishop : public Figure{

    Bishop(unsigned long long mask, int color) : Figure("bishop", 4, mask, color){
        this -> mask = mask;
        this -> color = color;
    }  

    ~Bishop() override {}

};

struct Queen : public Figure{

    Queen(unsigned long long mask, int color) : Figure("queen", 5, mask, color){
        this -> mask = mask;
        this -> color = color;
    }  

    ~Queen() override {}

};

struct King : public Figure{

    King(unsigned long long mask, int color)  : Figure("king", 6, mask, color){
        this -> mask = mask;
        this -> color = color;
    }  

    ~King() override {}

};