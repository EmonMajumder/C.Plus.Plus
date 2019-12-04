#ifndef _Human_H
#define _Human_H

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

#endif
