#include "City.h"
#include "GameSpecs.h"
#include <iostream>
#include <vector>
#include <array>
#include "Human.h"
#include "Zombie.h"
#include "Organism.h"
#include <time.h>

using namespace std;

City::City()
{
    for(int i=0;i<10;i++)
    {
        for (int j = 0; j < 10; j++)
        {
            this->grid[0][0] = nullptr;
        }
    }
}

City::~City()
{
    for(int i=0;i<10;i++)
    {
        for(int j = 0;j<10;j++)
        {
            if(this->grid[i][j] != NULL)
            {
                delete[] grid[i][j];
            }
        }
    }
}

Organism* City::getOrganism(int x, int y)
{
    return grid[x][y];
}

void City::setOrganism(Organism *organism, int x, int y)
{
    grid[x][y] = organism;
}

void City::move(int x, int y)
{
    int checkx;
    int checky;

    int a[8];

    for(int i=0;i<=2;i++)
    {
        switch(i)
        {
            case 0:
            {
                checkx = x - 1;
                for(int j=0;j<=2;j++)
                {
                    switch(j)
                    {
                        case 0:
                        {
                            checky = y-1;
                            break;
                        }

                        case 1:
                        {
                            break;
                        }

                        case 2:
                        {
                            checky = y+1;
                            break;
                        }
                    }
                }
                break;
            }

            case 1:
            {
                for(int j=0;j<=2;j++)
                {
                    switch(j)
                    {
                        case 0:
                        {
                            checky = y-1;
                            break;
                        }

                        case 1: {
                            break;
                        }

                        case 2: {
                            checky = y+1;
                            break;
                        }
                    }
                }
                break;
            }

            case 2:
            {
                checkx = x + 1;
                for(int j=0;j<=2;j++)
                {
                    switch(j)
                    {
                        case 0:
                        {
                            checky = y-1;
                            break;
                        }

                        case 1: {
                            break;
                        }

                        case 2: {
                            checky = y+1;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }

}



//ostream& City::operator<<(ostream &output, World &world)



