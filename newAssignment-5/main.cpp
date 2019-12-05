#include "Human.h"
#include "Zombie.h"
#include "City.h"
#include "Organism.h"
#include <string>
#include <time.h>
#include <algorithm>
#include <chrono>
#include <random>

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

void movecity()
{
    gridlocationnum =0;
    vector<int> abailableadjacentlocations;
    int adjacentlocationnum = 0;

    int newXposition = 0;
    int newYposition = 0;
    int counter = 0;
    int humantocreate = 0;
    int Zombietocreate = 0;


    for(int i=0; i < GRIDSIZE ; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            gridlocationnum++;

            if(city.getOrganism(i,j)!= nullptr)
            {
                if(!city.getOrganism(i,j)->moved)
                {
                    adjacentlocationnum = 0;

                    for(int m=-1;m<2;m++)
                    {
                        for(int n=-1;n<2;n++)
                        {
                            adjacentlocationnum++;

                            if(i+m>=0 && i+m<GRIDSIZE && j+n>=0 && j+n<GRIDSIZE)
                            {
                                if(city.getOrganism(i+m,j+n) == nullptr)
                                {
                                    if(city.getOrganism(i,j)->symbol == "O")
                                    {
                                        if(adjacentlocationnum%2 == 0)
                                        {
                                            abailableadjacentlocations.push_back(adjacentlocationnum);
                                        }
                                    }
                                    else
                                    {
                                        abailableadjacentlocations.push_back(adjacentlocationnum);
                                    }
                                }
                            }
                        }
                    }


                    if(!abailableadjacentlocations.empty())
                    {
                        unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
                        shuffle ( abailableadjacentlocations.begin(), abailableadjacentlocations.end(), default_random_engine(seed));

                        switch (abailableadjacentlocations.front())
                        {
                            case 1:
                            {
                                newYposition = i-1;
                                newXposition = j-1;
                                break;
                            }
                            case 2:
                            {
                                newYposition = i-1;
                                newXposition = j;
                                break;
                            }
                            case 3:
                            {
                                newYposition = i-1;
                                newXposition = j+1;
                                break;
                            }
                            case 4:
                            {
                                newYposition = i;
                                newXposition = j-1;
                                break;
                            }
                            case 6:
                            {
                                newYposition = i;
                                newXposition = j+1;
                                break;
                            }
                            case 7:
                            {
                                newYposition = i+1;
                                newXposition = j-1;
                                break;
                            }
                            case 8:
                            {
                                newYposition = i+1;
                                newXposition = j;
                                break;
                            }
                            case 9:
                            {
                                newYposition = i+1;
                                newXposition = j+1;
                                break;
                            }
                        }

                        if(city.getOrganism(i,j)->symbol == "O")
                        {
                            city.setOrganism((Organism*)new Human(newYposition,newXposition,city.getOrganism(i,j)->movecount),newYposition,newXposition);
                        }
                        else if(city.getOrganism(i,j)->symbol == "Z")
                        {
                            city.setOrganism((Organism*)new Zombie(newYposition,newXposition,city.getOrganism(i,j)->movecount),newYposition,newXposition);
                        }

                        city.getOrganism(newYposition,newXposition)->moved = true;

                        city.setOrganism(nullptr,i,j);

                        abailableadjacentlocations.clear();


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
                emptygrids.push_back(gridlocationnum);
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
}

int main() {

    initializecity();

    cout << city <<endl;

    int i = 0;

    while(i<10)
    {
        movecity();
        cout << city << endl;

        i++;
    }

    return  0;
}