#include "Human.h"
#include "Zombie.h"
#include "City.h"
#include "Organism.h"
#include <string>
#include <time.h>



int main() {

    int gridleft1 = GRIDSIZE*GRIDSIZE/4; //100
    int humanleft1 = HUMAN_STARTCOUNT/4;
    int zombieleft1 = ZOMBIE_STARTCOUNT/4;
    int gridleft2 = gridleft1; //100
    int humanleft2 = humanleft1;
    int zombieleft2 = zombieleft1;

    string s = "";

    City city;

    srand (time(NULL));

    for(int i=0;i<GRIDSIZE;i++)
    {
        if(i == GRIDSIZE/2)
        {
            gridleft1 = GRIDSIZE*GRIDSIZE/4;
            humanleft1 = HUMAN_STARTCOUNT/4; //1
            zombieleft1 = ZOMBIE_STARTCOUNT/4; //1
            gridleft2 = gridleft1;
            humanleft2 = humanleft1; //2
            zombieleft2 = zombieleft1; //2
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
    int couterofZombiesandhuman = 0;
    for(int i=0;i<GRIDSIZE;i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if(j== 0)
            {
                cout << "|";
            }
            if(city.getOrganism(i, j) != NULL)
            {
                cout << city.getOrganism(i,j)->symbol << "|";
                couterofZombiesandhuman++;
            }
            else
            {
                cout << " " << "|";
            }
        }
        cout << "" <<endl;
    }

    cout << couterofZombiesandhuman << endl;

    return  0;
}