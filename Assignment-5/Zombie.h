#ifndef _Zombie_H
#define _Zombie_H

#include "Organism.h"

class Zombie : public Organism
{
public:
	Zombie();
	Zombie(int x, int y);
	virtual ~Zombie();
	void move(int x, int y);
};

#endif
