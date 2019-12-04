#ifndef _Organism_H
#define _Organism_H

#include <iostream>
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

        //enum { 1,2,3,4,5,6,7,8,9 };

    public:
        Organism();
        Organism( int x, int y,bool moved, string symbol, int movecount);
        virtual ~Organism();

        virtual void move();
        //virtual void spawn() = 0;
        //virtual int getSpecies() = 0; //this could also be coded concrete here
        //virtual void getPosition() = 0;

    //	void setPosition( int x, int y );
    //	void endTurn();
    //	bool isTurn();
    //
    //	friend ostream& operator<<( ostream &output, Organism *organism );
};

#endif
