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

using namespace std;

City::City()
{
    this->total = 0;

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
    int k = 0;
    int l = 0;
    int counter = 0;
    int humantocreate = 0;
    int Zombietocreate = 0;
    int positionnum = 0;

    for(int i=0; i < GRIDSIZE ; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if(grid[i][j]!= nullptr)
            {
                if(!grid[i][j]->moved)
                {
                    positionnum = 0;

                    for(int m=-1;m<2;m++)
                    {
                        for(int n=-1;n<2;n++)
                        {
                            positionnum++;
                            if(i+m>=0 && i+m<GRIDSIZE && j+n>=0 && j+n<GRIDSIZE)
                            {
                                if(grid[i+m][j+n] == nullptr)
                                {
                                    positions.push_back(positionnum);
                                }
                            }
                        }
                    }


                    if(!positions.empty())
                    {
                        unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
                        shuffle ( positions.begin(), positions.end(), default_random_engine(seed));

                        switch (positions.front())
                        {
                            case 1:
                            {
                                k = i-1;
                                l = j-1;
                                break;
                            }
                            case 2:
                            {
                                k = i-1;
                                l = j;
                                break;
                            }
                            case 3:
                            {
                                k = i-1;
                                l = j+1;
                                break;
                            }
                            case 4:
                            {
                                k = i;
                                l = j-1;
                                break;
                            }
                            case 6:
                            {
                                k = i;
                                l = j+1;
                                break;
                            }
                            case 7:
                            {
                                k = i+1;
                                l = j-1;
                                break;
                            }
                            case 8:
                            {
                                k= i+1;
                                l = j;
                                break;
                            }
                            case 9:
                            {
                                k = i+1;
                                l = j+1;
                                break;
                            }
                        }

                        if(grid[i][j]->symbol == "O")
                        {
                            grid[k][l] = (Organism*)new Human(k,l,grid[i][j]->movecount);
                        }
                        else if(grid[i][j]->symbol == "Z")
                        {
                            grid[k][l] = (Organism*)new Zombie(k,l,grid[i][j]->movecount);
                        }
                        grid[k][l]->moved = true;
                        grid[i][j] = nullptr;
                        positions.clear();


//                    if(grid[i][j]->moved)
//                    {
//                        grid[k][l]->move();
//                        if(grid[k][l]->symbol == "O" && grid[k][l]->movecount == 3)
//                        {
//                            //create a new human
//                            positionnum = 0;
//                            positions.clear();
//                            int c = 0;
//                            int d = 0;
//                            for(int m=-1;m<2;m++)
//                            {
//                                for(int n=-1;n<2;n++)
//                                {
//                                    positionnum++;
//                                    if(k+m>=0 && k+m<GRIDSIZE && l+n>=0 && l+n<GRIDSIZE)
//                                    {
//                                        if(grid[k+m][l+n] == NULL)
//                                        {
//                                            positions.push_back(positionnum);
//                                        }
//                                    }
//                                }
//                            }
//
//                            random_shuffle ( positions.begin(), positions.end() );
//
//                            if(positions.size()>0)
//                            {
//                                switch (positions.front()) {
//                                    case 1: {
//                                        c = k - 1;
//                                        d = l - 1;
//                                        break;
//                                    }
//                                    case 2: {
//                                        c = k - 1;
//                                        break;
//                                    }
//                                    case 3: {
//                                        c = k - 1;
//                                        d = l + 1;
//                                        break;
//                                    }
//                                    case 4: {
//                                        d = l - 1;
//                                        break;
//                                    }
//                                    case 6: {
//                                        d = l + 1;
//                                        break;
//                                    }
//                                    case 7: {
//                                        c = k + 1;
//                                        d = l - 1;
//                                        break;
//                                    }
//                                    case 8: {
//                                        c = k + 1;
//                                        break;
//                                    }
//                                    case 9: {
//                                        c = k + 1;
//                                        d = l + 1;
//                                        break;
//                                    }
//                                }
//                            }
//                            grid[c][d] = (Organism*)new Human(c,d);
//                        }
//                        else if(grid[i][j]->symbol == "Z")
//                        {
//                            Zombietocreate++;
//                        }
//                    }
                    }
                }
            }
            else
            {
                emptygrid.push_back(counter);
            }

//            this->grid[i][j]->move();
//            if(grid[i][j]->moved)
//            {
//                grid[grid[i][j]->x][grid[i][j]->y] = grid[i][j];
//                grid[i][j] = nullptr;
//            }

            counter++;
        }
    }

    for(int i=0; i < GRIDSIZE ; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if(grid[i][j]!= nullptr)
            {
                grid[i][j]->moved = false;
            }
        }
    }
}

ostream& operator<<(ostream &output, City &world)
{
    int total= 0;
    for(int i=0;i<GRIDSIZE;i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if(j== 0)
            {
                output << "|";
            }
            if(world.getOrganism(i, j) != NULL)
            {
                output << world.getOrganism(i,j)->symbol << "|";
                total++;
            }
            else
            {
                output << " " << "|";
            }
        }
        output << "" <<endl;
    }
    output << total;
    return output;
}
