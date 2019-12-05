#include "Human.h"
#include "Zombie.h"
#include "City.h"
#include "Organism.h"
#include <string>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <random>
#include <iostream>
#include <windows.h>
#include <thread>


City city;
int gridleft1 = GRIDSIZE*GRIDSIZE/4; //100
int humanleft1 = HUMAN_STARTCOUNT/4;
int zombieleft1 = ZOMBIE_STARTCOUNT/4;
int gridleft2 = gridleft1; //100
int humanleft2 = humanleft1;
int zombieleft2 = zombieleft1;
vector<int> emptygrids;
int gridlocationnum = 0;


void resetgridinitializationvalues()
{
    gridleft1 = GRIDSIZE*GRIDSIZE/4;
    humanleft1 = HUMAN_STARTCOUNT/4; //1
    zombieleft1 = ZOMBIE_STARTCOUNT/4; //1
    gridleft2 = gridleft1;
    humanleft2 = humanleft1; //2
    zombieleft2 = zombieleft1; //2
}

void initializecity()
{
    srand (time(NULL));

    for(int i=0;i<GRIDSIZE;i++)
    {
        if(i == GRIDSIZE/2)
        {
            resetgridinitializationvalues();
        }

        for(int j=0;j<GRIDSIZE;j++)
        {
            if(j<GRIDSIZE/2)
            {
                if(humanleft1>0)
                {
                    if(humanleft1<gridleft1)
                    {
                        if((rand() % 7+1) == 3)
                        {
                            city.setOrganism((Organism*)new Human(i,j),i,j);
                            humanleft1--;
                        }
                        else if(zombieleft1 > 0)
                        {
                            if((rand() % 10+1) == 2)
                            {
                                city.setOrganism( (Organism*)new Zombie(i,j),i,j);
                                zombieleft1--;
                            }
                        }
                    }
                    else
                    {
                        city.setOrganism((Organism*)new Human(i,j),i,j);
                        humanleft1--;
                    }
                }
                gridleft1--;
            }
            else
            {
                if(humanleft2>0)
                {
                    if(humanleft2<gridleft2)
                    {
                        if((rand() % 7+1) == 4)
                        {
                            city.setOrganism((Organism*)new Human(i,j),i,j);
                            humanleft2--;
                        }
                        else if(zombieleft2 > 0)
                        {
                            if((rand() % 10+1) == 3)
                            {
                                city.setOrganism( (Organism*)new Zombie(i,j),i,j);
                                zombieleft2--;
                            }
                        }
                    }
                    else
                    {
                        city.setOrganism((Organism*)new Human(i,j),i,j);
                        humanleft2--;
                    }
                }
                gridleft2--;
            }
        }
    }
}

int *nextmovelocationforhuman(int x,int y)
{
    vector<int> abailableadjacentlocations;
    int adjacentlocationnum = 0;
    static int location[2];
    location[0] = GRIDSIZE+1;
    location[1] = GRIDSIZE+1;

    for (int m = -1; m < 2; m++)
    {
        for (int n = -1; n < 2; n++)
        {
            adjacentlocationnum++;

            if (x + m >= 0 && x + m < GRIDSIZE && y + n >= 0 && y + n < GRIDSIZE)
            {
                if (city.getOrganism(x + m, y + n) == nullptr && adjacentlocationnum % 2 == 0)
                {
                    abailableadjacentlocations.push_back(adjacentlocationnum);
                }
            }
        }
    }

    if (!abailableadjacentlocations.empty())
    {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
        shuffle(abailableadjacentlocations.begin(), abailableadjacentlocations.end(), default_random_engine(seed));

        switch (abailableadjacentlocations.front()) {
            case 1: {
                location[0] = x - 1;
                location[1] = y - 1;
                break;
            }
            case 2: {
                location[0] = x - 1;
                location[1] = y;
                break;
            }
            case 3: {
                location[0] = x - 1;
                location[1] = y + 1;
                break;
            }
            case 4: {
                location[0] = x;
                location[1] = y - 1;
                break;
            }
            case 6: {
                location[0] = x;
                location[1] = y + 1;
                break;
            }
            case 7: {
                location[0] = x + 1;
                location[1] = y - 1;
                break;
            }
            case 8: {
                location[0] = x + 1;
                location[1] = y;
                break;
            }
            case 9: {
                location[0] = x + 1;
                location[1] = y + 1;
                break;
            }
        }
    }

    abailableadjacentlocations.clear();

    return location;
}

int *nextmovelocationforzombie(int x, int y, bool convert)
{
    vector<int> abailableadjacentlocations;
    int adjacentlocationnum = 0;
    static int location[2];
    location[0] = GRIDSIZE+1;
    location[1] = GRIDSIZE+1;

    for (int m = -1; m < 2; m++)
    {
        for (int n = -1; n < 2; n++)
        {
            adjacentlocationnum++;

            if (x + m >= 0 && x + m < GRIDSIZE && y + n >= 0 && y + n < GRIDSIZE)
            {
                if (city.getOrganism(x + m, y + n) != nullptr)
                {
                    if(city.getOrganism(x + m, y + n)->symbol == "O" )
                    {
                        abailableadjacentlocations.push_back(adjacentlocationnum);
                    }
                }
            }
        }
    }

    if(!convert)
    {
        if(abailableadjacentlocations.empty())
        {
            adjacentlocationnum = 0;

            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                {
                    adjacentlocationnum++;

                    if (x + m >= 0 && x + m < GRIDSIZE && y + n >= 0 && y + n < GRIDSIZE)
                    {
                        if (city.getOrganism(x + m, y + n) == nullptr)
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
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
        shuffle(abailableadjacentlocations.begin(), abailableadjacentlocations.end(), default_random_engine(seed));

        switch (abailableadjacentlocations.front()) {
            case 1: {
                location[0] = x - 1;
                location[1] = y - 1;
                break;
            }
            case 2: {
                location[0] = x - 1;
                location[1] = y;
                break;
            }
            case 3: {
                location[0] = x - 1;
                location[1] = y + 1;
                break;
            }
            case 4: {
                location[0] = x;
                location[1] = y - 1;
                break;
            }
            case 6: {
                location[0] = x;
                location[1] = y + 1;
                break;
            }
            case 7: {
                location[0] = x + 1;
                location[1] = y - 1;
                break;
            }
            case 8: {
                location[0] = x + 1;
                location[1] = y;
                break;
            }
            case 9: {
                location[0] = x + 1;
                location[1] = y + 1;
                break;
            }
        }
    }

    abailableadjacentlocations.clear();

    return location;
}

void addhuman()
{
    int newIposition = 0;
    int newJposition = 0;
    int *nextmove;

    for(int i=0; i < GRIDSIZE ; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if(city.getOrganism(i,j)!= nullptr)
            {
                if(city.getOrganism(i,j)->moved && city.getOrganism(i,j)->symbol == "O" && city.getOrganism(i,j)->movecount == 3)
                {
                    nextmove = nextmovelocationforhuman(i,j);
                    newIposition = *(nextmove+0);
                    newJposition = *(nextmove+1);

                    if(newIposition<GRIDSIZE)
                    {
                        city.setOrganism((Organism*)new Human(newIposition,newJposition),newIposition,newJposition);
                    }

                    city.getOrganism(i,j)->movecount = 0;
                }
            }
            else
            {
                emptygrids.push_back(gridlocationnum);
            }
        }
    }
}

void addZombie()
{
    int newIposition = 0;
    int newJposition = 0;
    int *nextmove;

    for(int i=0; i < GRIDSIZE ; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if(city.getOrganism(i,j)!= nullptr)
            {
                if(city.getOrganism(i,j)->moved && city.getOrganism(i,j)->symbol == "Z" && city.getOrganism(i,j)->movecount >= 8)
                {
                    nextmove = nextmovelocationforzombie(i,j,true);
                    newIposition = *(nextmove+0);
                    newJposition = *(nextmove+1);

                    if(newIposition<GRIDSIZE)
                    {
                        city.setOrganism((Organism *) new Zombie(newIposition, newJposition), newIposition, newJposition);
                        city.getOrganism(i,j)->movecount = 0;
                    }
                }
            }
        }
    }
}

void clearmoved()
{
    for(int i=0; i < GRIDSIZE ; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if(city.getOrganism(i,j)!= nullptr)
            {
                if(city.getOrganism(i,j)->moved)
                {
                    city.getOrganism(i,j)->moved = false;
                }
            }
        }
    }
}
void moveHuman()
{
    gridlocationnum = 0;
    int newIposition = 0;
    int newJposition = 0;
    int *nextmove;

    for(int i=0; i < GRIDSIZE ; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if(city.getOrganism(i,j)!= nullptr)
            {
                if(!city.getOrganism(i,j)->moved)
                {
                    if(city.getOrganism(i,j)->symbol == "O")
                    {
                        nextmove = nextmovelocationforhuman(i,j);
                        newIposition = *(nextmove+0);
                        newJposition = *(nextmove+1);
                        if(newIposition<GRIDSIZE)
                        {
                            city.setOrganism((Organism*)new Human(newIposition,newJposition,city.getOrganism(i,j)->movecount+1),newIposition,newJposition);
                            city.getOrganism(newIposition,newJposition)->moved = true;
                            city.setOrganism(nullptr,i,j);
                        }
                        else
                        {
                            city.getOrganism(i,j)->movecount+=1;
                        }
                    }
                }
            }
        }
    }
}

void moveZombie()
{
    int newIposition = 0;
    int newJposition = 0;
    int *nextmove;

    for(int i=0; i < GRIDSIZE ; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if(city.getOrganism(i,j)!= nullptr)
            {
                if(!city.getOrganism(i,j)->moved)
                {
                    if(city.getOrganism(i,j)->symbol == "Z")
                    {
                        nextmove = nextmovelocationforzombie(i,j, false);
                        newIposition = *(nextmove+0);
                        newJposition = *(nextmove+1);
                        if(newIposition<GRIDSIZE)
                        {
                            if(city.getOrganism(newIposition, newJposition) != nullptr)
                            {
                                city.setOrganism((Organism *) new Zombie(newIposition, newJposition,city.getOrganism(i, j)->movecount + 1),newIposition, newJposition);
                            }
                            else
                            {
                                city.setOrganism((Organism *) new Zombie(newIposition, newJposition,city.getOrganism(i, j)->movecount + 1,city.getOrganism(i, j)->starvecount + 1),newIposition, newJposition);
                            }
                            city.getOrganism(newIposition,newJposition)->moved = true;
                            city.setOrganism(nullptr, i, j);
                        }
                        else
                        {
                            city.getOrganism(i,j)->movecount+=1;
                            city.getOrganism(i,j)->starvecount+=1;
                        }

                    }
                }
            }
        }
    }
}

void convertZombie()
{
    for(int i=0; i < GRIDSIZE ; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if(city.getOrganism(i,j)!= nullptr)
            {
                if(city.getOrganism(i,j)->symbol == "Z" && city.getOrganism(i,j)->starvecount == 3)
                {
                    city.setOrganism((Organism *) new Human(i, j), i, j);
                }
            }
        }
    }
}

void Col(int c)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
    return;
}

int main() {

    initializecity();

    cout<< "Initial Setup of Layout" <<endl;
    cout << city <<endl;

    int i = 1;

    double counter = 0;
    double pauseInterval = 3;
    clock_t startTime = clock();
    clock_t previousTime = startTime;

    while(i<100)
    {
        startTime = clock();
        counter+=startTime-previousTime;
        previousTime = startTime;
        if(counter>pauseInterval * CLOCKS_PER_SEC)
        {
            counter -=pauseInterval * CLOCKS_PER_SEC;

            cout << "Round: " << i << endl;
            moveZombie();
            moveHuman();
            convertZombie();
            addZombie();
            addhuman();
            clearmoved();
            //cout << city ;
            int O = 0;
            int Z = 0;

            for(int i=0;i<GRIDSIZE;i++) {
                for (int j = 0; j < GRIDSIZE; j++)
                {
                    if(j== 0)
                    {
                        Col(7);
                        cout << "|";
                    }

                    if(city.getOrganism(i, j) != nullptr)
                    {
                        if(city.getOrganism(i,j)->symbol == "O")
                        {
                            Col(3);
                            cout << city.getOrganism(i,j)->symbol;

                            Col(7);
                            cout << "|";

                            O++;
                        }
                        else if(city.getOrganism(i,j)->symbol == "Z")
                        {
                            Col(12);
                            cout << city.getOrganism(i,j)->symbol;

                            Col(7);
                            cout << "|";

                            Z++;
                        }
                    }
                    else
                    {
                        cout << " " << "|";
                    }
                }
                cout << "" <<endl;
            }
            cout << "O =" << O << "   " << "Z =" << Z << endl;
            i++;
        }
    }
    return  0;
}