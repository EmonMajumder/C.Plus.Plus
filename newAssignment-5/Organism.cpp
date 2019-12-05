//
// Created by W0411567 on 12/4/2019.
//

#include "Organism.h"

using namespace std;

Organism::Organism()
{
    this->x = 0;
    this->y = 0;
    this->moved = false;
    this->movecount = 0;
    this->symbol = "";
    this->starvecount = 0;
}

Organism::Organism(City *city, int x, int y)
{
    this->x = x;
    this->y = y;
    this->city = city;
    this->moved = false;
    this->movecount = 0;
    this->symbol = "";
    this->starvecount = 0;
}

Organism::~Organism()
{

}