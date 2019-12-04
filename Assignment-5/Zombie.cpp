//
// Created by W0411567 on 12/2/2019.
//
#include <stdio.h>
#include "Zombie.h"
#include "GameSpecs.h"

using namespace std;

Zombie::Zombie()
{
    this->x = 0;
    this->y = 0;
    this->moved = false;
    this->movecount = 0;
    this->symbol = ZOMBIE_CH;
}

Zombie::Zombie(int x, int y)
{
    this->x = x;
    this->y = y;
    this->moved = false;
    this->movecount = 0;
    this->symbol = ZOMBIE_CH;
}


Zombie::~Zombie()
{

}

void Zombie::move(int x, int y)
{
    movecount++;
}
