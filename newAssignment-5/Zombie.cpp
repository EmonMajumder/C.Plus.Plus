//
// Created by W0411567 on 12/4/2019.
//
#include <chrono>
#include <random>
#include <algorithm>
#include "Zombie.h"
#include "GameSpecs.h"
#include "City.h"

using namespace std;

//Default constructor
Zombie::Zombie()
{
    this->x = 0;
    this->y = 0;
    this->moved = false;
    this->movecount = 0;
    this->starvecount = 0;
    this->symbol = ZOMBIE_CH;
}

//Constructor
Zombie::Zombie(City *city, int x, int y)
{
    this->x = x;
    this->y = y;
    this->city = city;
    this->moved = false;
    this->movecount = 0;
    this->starvecount = 0;
    this->symbol = ZOMBIE_CH;
}

Zombie::~Zombie()
{

}

//Function to determine next move location
void Zombie::nextmovelocation(bool convert)
{
    vector<int> abailableadjacentlocations;
    int adjacentlocationnum = 0;

    for (int m = -1; m < 2; m++)
    {
        for (int n = -1; n < 2; n++)
        {
            adjacentlocationnum++;

            if (x + m >= 0 && x + m < GRIDSIZE && y + n >= 0 && y + n < GRIDSIZE)
            {
                if (city->getOrganism(x + m, y + n) != nullptr)
                {
                    if (city->getOrganism(x + m, y + n)->symbol == "O")
                    {
                        abailableadjacentlocations.push_back(adjacentlocationnum);
                    }
                }
            }
        }
    }

    if (!convert)
    {
        if (abailableadjacentlocations.empty())
        {
            adjacentlocationnum = 0;

            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                {
                    adjacentlocationnum++;

                    if (x + m >= 0 && x + m < GRIDSIZE && y + n >= 0 && y + n < GRIDSIZE)
                    {
                        if (city->getOrganism(x + m, y + n) == nullptr)
                        {
                            abailableadjacentlocations.push_back(adjacentlocationnum);
                        }
                    }
                }
            }
        }
    }

    if (!abailableadjacentlocations.empty())
    {
        //Shuffle the vector to randomly select move location
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
        shuffle(abailableadjacentlocations.begin(), abailableadjacentlocations.end(), default_random_engine(seed));

        switch (abailableadjacentlocations.front()) {
            case 1: {
                x = x - 1;
                y = y - 1;
                break;
            }
            case 2: {
                x = x - 1;
                y = y;
                break;
            }
            case 3: {
                x = x - 1;
                y = y + 1;
                break;
            }
            case 4: {
                x = x;
                y = y - 1;
                break;
            }
            case 6: {
                x = x;
                y = y + 1;
                break;
            }
            case 7: {
                x = x + 1;
                y = y - 1;
                break;
            }
            case 8: {
                x = x + 1;
                y = y;
                break;
            }
            case 9: {
                x = x + 1;
                y = y + 1;
                break;
            }
        }
    }

    //clear the vector.
    abailableadjacentlocations.clear();
}

//Move Zombie to a new position.
void Zombie::move(City *city)
{
    this->city = city;
    int i = x;
    int j = y;

    nextmovelocation(false);

    moved = true;
    movecount++;
    starvecount++;

    if (city->getOrganism(x, y) != nullptr)
    {
        starvecount = 0;
    }

    city->setOrganism((Organism *)this, x, y);

    if (x != i || y != j)
    {
        city->setOrganism(nullptr, i, j);
    }

}


