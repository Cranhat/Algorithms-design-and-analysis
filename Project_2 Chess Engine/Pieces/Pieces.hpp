#pragma once

#include <string>

struct Figure{
    std::string type;
    int identifier;
    int cost;
    unsigned long long mask;
    int color; // 1 - white, -1 - black


    virtual ~Figure() = default;
    Figure(std::string type, int identifier, int cost, unsigned long long mask, int color)
    : type(type), identifier(identifier), cost(cost), mask(mask), color(color) {}

    virtual Figure* clone() const = 0; 
};

struct Pawn : public Figure{

    Pawn(unsigned long long mask, int color) : Figure("pawn", 1, 1, mask, color){
        this -> mask = mask;
        this -> color = color;
    }

    ~Pawn() override {}

    Figure* clone() const override {
        return new Pawn(*this);
    }
};

struct Rook : public Figure{

    Rook(unsigned long long mask, int color) : Figure("rook", 2, 5, mask, color){
        this -> mask = mask;
        this -> color = color;
    }
    ~Rook() override {}

    Figure* clone() const override {
        return new Rook(*this);
    }
};

struct Knight : public Figure{

    Knight(unsigned long long mask, int color)  : Figure("knight", 3, 3, mask, color){
        this -> mask = mask;
        this -> color = color;
    }
    ~Knight() override {}

    Figure* clone() const override {
        return new Knight(*this);
    }
};

struct Bishop : public Figure{

    Bishop(unsigned long long mask, int color) : Figure("bishop", 4, 3, mask, color){
        this -> mask = mask;
        this -> color = color;
    }  

    ~Bishop() override {}

    Figure* clone() const override {
        return new Bishop(*this);
    }

};

struct Queen : public Figure{

    Queen(unsigned long long mask, int color) : Figure("queen", 6, 9, mask, color){
        this -> mask = mask;
        this -> color = color;
    }  

    ~Queen() override {}

    Figure* clone() const override {
        return new Queen(*this);
    }

};

struct King : public Figure{

    King(unsigned long long mask, int color)  : Figure("king", 5, 100000, mask, color){
        this -> mask = mask;
        this -> color = color;
    }  

    ~King() override {}

    Figure* clone() const override {
        return new King(*this);
    }
};