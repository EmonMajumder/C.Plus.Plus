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
    Zombie(City *city, int x, int y);

    void nextmovelocation(bool convert);
    virtual ~Zombie();
    void move(City *city);
};

#endif //NEWASSIGNMENT_5_ZOMBIE_H
