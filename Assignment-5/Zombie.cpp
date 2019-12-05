//
// Created by W0411567 on 12/4/2019.
//

#include "Zombie.h"
#include "GameSpecs.h"
#include <vector>
#include <algorithm>

using namespace std;


Zombie::Zombie()
{
    this->x = 0;
    this->y = 0;
    this->moved = false;
    this->movecount = 0;
    this->starvecount = 0;
    this->symbol = ZOMBIE_CH;
}

Zombie::Zombie(int x, int y)
{
    this->x = x;
    this->y = y;
    this->moved = false;
    this->movecount = 0;
    this->starvecount = 0;
    this->symbol = ZOMBIE_CH;
}

Zombie::Zombie(int x, int y, int movecount)
{
    this->x = x;
    this->y = y;
    this->moved = false;
    this->movecount = movecount;
    this->starvecount = 0;
    this->symbol = ZOMBIE_CH;
}

Zombie::Zombie(int x, int y, int movecount, int starvecount)
{
    this->x = x;
    this->y = y;
    this->moved = false;
    this->movecount = movecount;
    this->starvecount = starvecount;
    this->symbol = ZOMBIE_CH;
}


Zombie::~Zombie()
{

}

void Zombie::move()
{

}

