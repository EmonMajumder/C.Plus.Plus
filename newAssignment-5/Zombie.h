//
// Created by W0411567 on 12/4/2019.
//

#ifndef NEWASSIGNMENT_5_ZOMBIE_H
#define NEWASSIGNMENT_5_ZOMBIE_H

#include "Organism.h"

class Zombie : public Organism
{
public:
    Zombie();
    Zombie(int x, int y);
    virtual ~Zombie();
    void move(int x, int y);
};

#endif //NEWASSIGNMENT_5_ZOMBIE_H
