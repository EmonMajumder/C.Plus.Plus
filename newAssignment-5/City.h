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

class City
{
public:
    Organism* grid[GRIDSIZE][GRIDSIZE];
    vector <int> positions;
    vector<int> emptygrid;
    int total;

public:
    City();
    virtual ~City();

    Organism *getOrganism( int x, int y );
    void setOrganism( Organism *organism, int x, int y );
    void move();

    friend ostream& operator<<( ostream &output, City &world );

};


#endif //NEWASSIGNMENT_5_CITY_H
