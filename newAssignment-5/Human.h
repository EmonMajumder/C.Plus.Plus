//
// Created by W0411567 on 12/4/2019.
//

#ifndef NEWASSIGNMENT_5_HUMAN_H
#define NEWASSIGNMENT_5_HUMAN_H


#include "Organism.h"
#include <string>

class Human : public Organism
{
public:
    Human();
    Human(int x, int y);
    virtual ~Human();
    void move(int x, int y);
};



#endif //NEWASSIGNMENT_5_HUMAN_H
