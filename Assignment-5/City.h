#ifndef _CITY_H
#define _CITY_H

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

#endif

