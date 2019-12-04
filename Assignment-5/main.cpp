#include "Human.h"
#include "Zombie.h"
#include "City.h"
#include "Organism.h"
#include <string>
#include <time.h>

int main() {

    int gridleft1 = 25;
    int gridleft2 = 25;
    int humanleft1 = 4;
    int humanleft2 = 4;
    int zombieleft1 = 2;
    int zombieleft2 = 2;
    string s = "";

    City city;

    srand (time(NULL));

    for(int i=0;i<10;i++)
    {
        if(i == 5)
        {
            gridleft1 = 25;
            gridleft2 = 25;
            humanleft1 = 4;
            humanleft2 = 4;
            zombieleft1 = 2;
            zombieleft2 = 2;
        }

        for(int j=0;j<10;j++)
        {
            if(j<5)
            {
                if(humanleft1>0)
                {
                    if(humanleft1<gridleft1)
                    {
                        if((rand() % 5+1) == 2)
                        {
                            city.setOrganism((Organism*)new Human(i,j),i,j);
                            humanleft1--;
                        }
                        else if(zombieleft1 > 0)
                        {
                            if((rand() % 5+1) == 2)
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
                        if((rand() % 5+1) == 2)
                        {
                            city.setOrganism((Organism*)new Human(i,j),i,j);
                            humanleft2--;
                        }
                        else if(zombieleft2 > 0)
                        {
                            if((rand() % 5+1) == 2)
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
    int a =0;
    for(int i=0;i<20;i++) {
        for (int j = 0; j < 10; j++) {
            if(city.getOrganism(i, j) != NULL)
            {
                //s = city.getOrganism(i, j)->symbol;
                cout << "X"<< "|";
                a++;
            }
            else
            {
                cout << "O" << "|";
            }
        }
        cout << " " << endl;
    }

    cout << a << endl;
}
