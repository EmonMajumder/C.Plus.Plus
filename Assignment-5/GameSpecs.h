//
// Created by W0411567 on 12/4/2019.
//

#ifndef NEWASSIGNMENT_5_GAMESPECS_H
#define NEWASSIGNMENT_5_GAMESPECS_H

#include <string>
using namespace std;

const int GRIDSIZE = 20; // size of the square grid
const int HUMAN_STARTCOUNT = 60; // inital Humans
const int ZOMBIE_STARTCOUNT = 12; //initial Zombie count
const int HUMAN_BREED = 3; // steps until an Human breeds
const int ZOMBIE_BREED = 8; // steps until an Zombie breeds
const int ZOMBIE_STARVE = 3; // steps until a Zombie starves and converts back
const string HUMAN_CH = "O";//79 "o"// ascii Human
const char SPACE_CH = 32; // " " ascii space
const string ZOMBIE_CH = "Z";//90 "Z"// ascii zombie
const double PAUSE_SECONDS = .09; // pause between steps
const int ITERATIONS = 1000; // max number of steps
const int INIHUMANCOUNT = 50;
const int INIZOMBIECOUNT = 50;

//Colors
//0  = black				//9  = bright blue
//1  = blue					//10 = bright green
//2  = green				//11 = bright turquoise
//3  = turquise				//12 = bright red
//4  = red					//13 = bright pink
//5  = pink					//14 = bright yellow
//6  = yellow				//15 = bright white
//7  = white regular		//16+ = solid blocks
//8  = white pale

const int HUMAN_COLOR = 3; // turquoise
const int ZOMBIE_COLOR = 14; // bright yellow

#endif //NEWASSIGNMENT_5_GAMESPECS_H
