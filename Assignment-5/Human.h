//
// Created by W0411567 on 12/4/2019.
//

#ifndef NEWASSIGNMENT_5_HUMAN_H
#define NEWASSIGNMENT_5_HUMAN_H


#include "Organism.h"
#include "City.h"
#include <string>

class City;
class Human : public Organism
{
public:
    Human();
    Human(int x, int y);
    Human(int x, int y, int movecount);

    virtual ~Human();
    void move();
};



#endif //NEWASSIGNMENT_5_HUMAN_H
