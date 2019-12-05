//
// Created by W0411567 on 12/4/2019.
//

#ifndef NEWASSIGNMENT_5_ZOMBIE_H
#define NEWASSIGNMENT_5_ZOMBIE_H

#include "Organism.h"


class City;
class Zombie : public Organism
{
public:
    Zombie();
    Zombie(int x, int y);
    Zombie(int x, int y, int movecount);
    Zombie(int x, int y, int movecount, int starvecount);
    virtual ~Zombie();
    void move();
};

#endif //NEWASSIGNMENT_5_ZOMBIE_H
