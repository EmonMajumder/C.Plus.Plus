//
// Created by W0411567 on 12/4/2019.
//

#ifndef NEWASSIGNMENT_5_ORGANISM_H
#define NEWASSIGNMENT_5_ORGANISM_H
#include <string>

using namespace std;

class Organism
{
public:
    int x;
    int y;
    bool moved;
    string symbol;
    int movecount;
    int starvecount;

    //enum { 1,2,3,4,5,6,7,8,9 };

public:
    Organism();
    Organism( int x, int y,bool moved, string symbol, int movecount);

    virtual ~Organism() = 0;
    virtual void move() = 0;
    //virtual void spawn() = 0;
    //virtual int getSpecies() = 0; //this could also be coded concrete here
    //virtual void getPosition() = 0;

    //	void setPosition( int x, int y );
    //	void endTurn();
    //	bool isTurn();
    //
    //	friend ostream& operator<<( ostream &output, Organism *organism );
};


#endif //NEWASSIGNMENT_5_ORGANISM_H
