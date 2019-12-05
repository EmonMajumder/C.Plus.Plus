//
// Created by W0411567 on 12/4/2019.
//

#include "City.h"
#include "GameSpecs.h"
#include <iostream>
#include <vector>
#include <array>
#include "Human.h"
#include "Zombie.h"
#include "Organism.h"
#include <time.h>
#include <algorithm>
#include <chrono>
#include <random>
#include <iostream>
#include <windows.h>

using namespace std;

City::City()
{
    for(int i=0;i<GRIDSIZE;i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            this->grid[i][j] = nullptr;
        }
    }
}

City::~City()
{
    for(int i=0;i<GRIDSIZE;i++)
    {
        for(int j = 0;j<GRIDSIZE;j++)
        {
            if(this->grid[i][j] != nullptr)
            {
                delete[] grid[i][j];
            }
        }
    }
}

Organism* City::getOrganism(int y, int x)
{
    return grid[y][x];
}

void City::setOrganism(Organism *organism, int y, int x)
{
    grid[y][x] = organism;
}

void City::move()
{

}

ostream& operator<<(ostream &output, City &world)
{
    int O = 0;
    int Z = 0;

    for(int i=0;i<GRIDSIZE;i++) {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if(j== 0)
            {
                output << "|";
            }

            if(world.getOrganism(i, j) != nullptr)
            {
                if(world.getOrganism(i,j)->symbol == "O")
                {
                    output << world.getOrganism(i,j)->symbol;
                    output << "|";

                    O++;
                }
                else if(world.getOrganism(i,j)->symbol == "Z")
                {
                    output << world.getOrganism(i,j)->symbol;
                    output << "|";

                    Z++;
                }
            }
            else
            {
                output << " " << "|";
            }
        }
        output << "" <<endl;
    }
    output << "O =" << O << "   " << "Z =" << Z << endl;
    return output;
}
