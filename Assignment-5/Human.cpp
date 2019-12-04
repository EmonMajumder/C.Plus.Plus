//
// Created by W0411567 on 12/2/2019.
//

#include <stdio.h>
#include "Human.h"
#include "GameSpecs.h"

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

Human::~Human()
{

}

void Human::move(int x, int y)
{
    movecount++;
}