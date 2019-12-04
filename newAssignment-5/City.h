//
// Created by W0411567 on 12/4/2019.
//

#ifndef NEWASSIGNMENT_5_CITY_H
#define NEWASSIGNMENT_5_CITY_H

#include <iostream>
#include "GameSpecs.h"
#include "Organism.h"

using namespace std;

class City
{
private:
    Organism* grid[GRIDSIZE][GRIDSIZE];

public:
    City();
    virtual ~City();

    Organism *getOrganism( int x, int y );
    void setOrganism( Organism *organism, int x, int y );
    void move(int x, int y);

    //friend ostream& operator<<( ostream &output, World &world );

};


#endif //NEWASSIGNMENT_5_CITY_H
