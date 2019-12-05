//
// Created by W0411567 on 12/4/2019.
//
#ifndef NEWASSIGNMENT_5_HUMAN_H
#define NEWASSIGNMENT_5_HUMAN_H

#include "Organism.h"

class Human : public Organism
{
public:
    Human();
    Human(City *city, int x, int y);

    virtual ~Human();
    void move(City *city);
    void nextmovelocation(bool notneeded);
};

#endif //NEWASSIGNMENT_5_HUMAN_H
