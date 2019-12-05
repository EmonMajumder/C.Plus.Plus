//
// Created by W0411567 on 12/4/2019.
//

#include "Human.h"
#include "GameSpecs.h"
#include "City.h"
#include <vector>
#include <algorithm>

using namespace std;

Human::Human()
{
    this->x = 0;
    this->y = 0;
    this->moved = false;
    this->movecount = 0;
    this->symbol = HUMAN_CH;
}

Human::Human(int x, int y)
{
    this->x = x;
    this->y = y;
    this->moved = false;
    this->movecount = 0;
    this->symbol = HUMAN_CH;
}

Human::Human(int x, int y,int movecount)
{
    this->x = x;
    this->y = y;
    this->moved = false;
    this->movecount = movecount;
    this->symbol = HUMAN_CH;
}

Human::~Human()
{

}

void Human::move()
{
    if(moved = true)
    {
        movecount++;
        moved = false;
    }
}