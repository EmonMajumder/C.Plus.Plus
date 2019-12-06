//
// Created by W0411567 on 12/4/2019.
//

#ifndef NEWASSIGNMENT_5_CITY_H
#define NEWASSIGNMENT_5_CITY_H

#include <iostream>
#include <vector>
#include "GameSpecs.h"
#include "Organism.h"

using namespace std;

class Organism;

class City
{

private:
    Organism* grid[GRIDSIZE][GRIDSIZE];

public:
    City();

    //Destructor
    virtual ~City();

    //Getter
    Organism *getOrganism(int x, int y);

    //Setter
    void setOrganism(Organism *organism, int x, int y);

    //Operator overloading.
    friend ostream& operator<<(ostream &output, City &world);
};

#endif //NEWASSIGNMENT_5_CITY_H
