#include "Human.h"
#include "Zombie.h"
#include "City.h"
#include "Organism.h"
#include <string>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <windows.h>

//Create a city in memory with default constructor.
City *city = new City();

//Variables to initialize the city layout with human and zombie.
int gridleft1 = GRIDSIZE * GRIDSIZE / 4;
int humanleft1 = HUMAN_STARTCOUNT / 4;
int zombieleft1 = ZOMBIE_STARTCOUNT / 4;
int gridleft2 = gridleft1;
int humanleft2 = humanleft1;
int zombieleft2 = zombieleft1;

//Reset values for initial layout.
void resetgridinitializationvalues()
{
    gridleft1 = GRIDSIZE * GRIDSIZE / 4;
    humanleft1 = HUMAN_STARTCOUNT / 4;
    zombieleft1 = ZOMBIE_STARTCOUNT / 4;
    gridleft2 = gridleft1;
    humanleft2 = humanleft1;
    zombieleft2 = zombieleft1;
}


//Initialize the city plot with human and Zombie.
void initializecity()
{
    int probabilityratiohuman = 4;
    int probabilityratiozombie = 12;
    srand(time(NULL));

    for (int i = 0;i < GRIDSIZE;i++)
    {
        if (i == GRIDSIZE / 2)
        {
            resetgridinitializationvalues();
        }

        for (int j = 0;j < GRIDSIZE;j++)
        {
            if (j < GRIDSIZE / 2)
            {
                if (humanleft1 > 0)
                {
                    if (humanleft1 < gridleft1)
                    {
                        if ((rand() % probabilityratiohuman + 1) == 3)
                        {
                            city->setOrganism((Organism*)new Human(city, i, j), i, j);
                            humanleft1--;
                        }
                        else if (zombieleft1 > 0)
                        {
                            if ((rand() % probabilityratiozombie + 1) == 2)
                            {
                                city->setOrganism((Organism*)new Zombie(city, i, j), i, j);
                                zombieleft1--;
                            }
                        }
                    }
                    else
                    {
                        city->setOrganism((Organism*)new Human(city, i, j), i, j);
                        humanleft1--;
                    }
                }
                gridleft1--;
            }
            else
            {
                if (humanleft2 > 0)
                {
                    if (humanleft2 < gridleft2)
                    {
                        if ((rand() % probabilityratiohuman + 1) == 4)
                        {
                            city->setOrganism((Organism*)new Human(city, i, j), i, j);
                            humanleft2--;
                        }
                        else if (zombieleft2 > 0)
                        {
                            if ((rand() % probabilityratiozombie + 1) == 3)
                            {
                                city->setOrganism((Organism*)new Zombie(city, i, j), i, j);
                                zombieleft2--;
                            }
                        }
                    }
                    else
                    {
                        city->setOrganism((Organism*)new Human(city, i, j), i, j);
                        humanleft2--;
                    }
                }
                gridleft2--;
            }
        }
    }
}

//Move all the Zombies across the city.
void moveZombie()
{
    for (int i = 0; i < GRIDSIZE; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if (city->getOrganism(i, j) != nullptr)
            {
                if (!city->getOrganism(i, j)->moved && city->getOrganism(i, j)->symbol == "Z")
                {
                    city->getOrganism(i, j)->move(city);
                }
            }
        }
    }
}

//Move all the Humans across the city. 
void moveHuman()
{
    for (int i = 0; i < GRIDSIZE; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if (city->getOrganism(i, j) != nullptr)
            {
                if (!city->getOrganism(i, j)->moved && city->getOrganism(i, j)->symbol == "O")
                {
                    city->getOrganism(i, j)->move(city);
                }
            }
        }
    }
}

//Convert Zombies back to human.
void convertZombie()
{
    for (int i = 0; i < GRIDSIZE; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if (city->getOrganism(i, j) != nullptr)
            {
                if (city->getOrganism(i, j)->symbol == "Z" && city->getOrganism(i, j)->starvecount == ZOMBIE_STARVE)
                {
                    city->setOrganism((Organism *) new Human(city, i, j), i, j);
                }
            }
        }
    }
}

//Convert humans to Zombies. 
void addZombie()
{
    int newIposition = 0;
    int newJposition = 0;

    for (int i = 0; i < GRIDSIZE; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if (city->getOrganism(i, j) != nullptr)
            {
                if (city->getOrganism(i, j)->moved && city->getOrganism(i, j)->symbol == "Z" && city->getOrganism(i, j)->movecount >= ZOMBIE_BREED)
                {
                    city->getOrganism(i, j)->nextmovelocation(true);
                    newIposition = city->getOrganism(i, j)->x;
                    newJposition = city->getOrganism(i, j)->y;

                    if (newIposition != i || newJposition != j)
                    {
                        city->getOrganism(i, j)->x = i;
                        city->getOrganism(i, j)->y = j;

                        city->setOrganism((Organism *) new Zombie(city, newIposition, newJposition), newIposition, newJposition);
                        city->getOrganism(i, j)->movecount = 0;
                    }
                }
            }
        }
    }
}

//Add human to the city.
void addhuman()
{
    int newIposition = 0;
    int newJposition = 0;

    for (int i = 0; i < GRIDSIZE; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if (city->getOrganism(i, j) != nullptr)
            {
                if (city->getOrganism(i, j)->moved && city->getOrganism(i, j)->symbol == "O" && city->getOrganism(i, j)->movecount == HUMAN_BREED)
                {
                    city->getOrganism(i, j)->movecount = 0;
                    city->getOrganism(i, j)->nextmovelocation(true);

                    newIposition = city->getOrganism(i, j)->x;
                    newJposition = city->getOrganism(i, j)->y;

                    if (newIposition != i || newJposition != j)
                    {
                        city->getOrganism(i, j)->x = i;
                        city->getOrganism(i, j)->y = j;

                        city->setOrganism((Organism*)new Human(city, newIposition, newJposition), newIposition, newJposition);
                    }
                }
            }
        }
    }
}

//Change the moved status of all organism to false.
void clearmoved()
{
    for (int i = 0; i < GRIDSIZE; i++)
    {
        for (int j = 0; j < GRIDSIZE; j++)
        {
            if (city->getOrganism(i, j) != nullptr)
            {
                if (city->getOrganism(i, j)->moved)
                {
                    city->getOrganism(i, j)->moved = false;
                }
            }
        }
    }
}

//Function that handles color output to console.
void Col(int c)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,c);
}


//Main driver.
int main() {

    //Timer variables to delay the program.
    double counter = 0;
    double pauseInterval = PAUSE_SECONDS;
    clock_t startTime = clock();
    clock_t previousTime = startTime;

    //Initialize the city layout.
    initializecity();

    Col(7);
    cout << "Initial Setup of Layout" << endl;

    //Console output of city grid using a operator modifier.
    //cout << city << endl;

    int r = 1;
    int O = 1;
    int Z = 1;

    //while loop for the simulation.
    while (O > 0 && Z > 0 && r<ITERATIONS)
    {
        Col(7);

        startTime = clock();
        counter += startTime - previousTime;
        previousTime = startTime;

        //restrict the console output to delay action on screen.
        if (counter > pauseInterval * CLOCKS_PER_SEC)
        {
            counter -= pauseInterval * CLOCKS_PER_SEC;

            cout << "Round: " << r << endl;

            O = 0;
            Z = 0;

            for (int i = 0;i < GRIDSIZE;i++) {
                for (int j = 0; j < GRIDSIZE; j++)
                {
                    //if (j == 0)
                    //{
                    //	cout << "|";
                    //}

                    if (city->getOrganism(i, j) != nullptr)
                    {
                        if (city->getOrganism(i, j)->symbol == "O")
                        {
                            Col(HUMAN_COLOR);

                            cout << city->getOrganism(i, j)->symbol;

                            //Col(7);
                            //cout << "|";
                            cout << " ";

                            O++;
                        }
                        else if (city->getOrganism(i, j)->symbol == "Z")
                        {
                            Col(ZOMBIE_COLOR);

                            cout << city->getOrganism(i, j)->symbol;

                            //Col(7);
                            //cout << "|";
                            cout << " ";

                            Z++;
                        }
                    }
                    else
                    {
                        //Col(7);
                        //cout << " " << "|";
                        cout << "  ";
                    }
                }
                cout << "" << endl;
            }

            Col(6);

            cout << "O =" << O << "                           " << "Z =" << Z << endl;

            r++;

            moveZombie();

            moveHuman();

            convertZombie();

            addZombie();

            addhuman();

            clearmoved();
        }
    }
    return  0;
}