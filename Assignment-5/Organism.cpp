//
// Created by W0411567 on 12/2/2019.
//
#include "Organism.h"
#include "GameSpecs.h"
#include <string>

using namespace std;

Organism::Organism()
{
    this->x = 0;
    this->y = 0;
    this->moved = false;
    this->movecount = 0;
    this->symbol = "X";
}

Organism::Organism(int x, int y,bool moved, string symbol, int movecount)
{
    this->x = x;
    this->y = y;
    this->moved = moved;
    this->movecount = movecount;
    this->symbol = symbol;
}



Organism::~Organism()
{

}

void Organism::move()
{

}