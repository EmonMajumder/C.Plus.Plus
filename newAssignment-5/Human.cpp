#include "Human.h"
#include "GameSpecs.h"
#include "City.h"
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

//Default constructor
Human::Human()
{
    this->x = 0;
    this->y = 0;
    this->moved = false;
    this->movecount = 0;
    this->symbol = HUMAN_CH;
}

//Constructor
Human::Human(City *city, int x, int y)
{
    this->x = x;
    this->y = y;
    this->city = city;
    this->moved = false;
    this->movecount = 0;
    this->symbol = HUMAN_CH;
}

Human::~Human()
{

}

//Function to determine next move location
void Human::nextmovelocation(bool notneeded)
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
                if (city->getOrganism(x + m, y + n) == nullptr && adjacentlocationnum % 2 == 0)
                {
                    abailableadjacentlocations.push_back(adjacentlocationnum);
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

//Move human to a new position.
void Human::move(City *city)
{
    this->city = city;
    int i = x;
    int j = y;

    nextmovelocation(true);
    movecount += 1;
    moved = true;

    city->setOrganism((Organism*)this, x, y);

    if (x != i || y != j)
    {
        city->setOrganism(nullptr, i, j);
    }
}
