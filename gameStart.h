//Developed by 
//Nathan Luchsinger
//Rustin Haase
//Mike Senior
//Phoebe Sulistio

#ifndef gameStart_H
#define gameStart_H
#include <string>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

int main(void);
int gameStart(void);
void help(void);
void printLocation(int partners[]);
void printItems(int items[]);
void saveFile(int items[], int location, int energy, int skill, int hour, int projectQuality, int partners[], int newGame);
int * quest(int energy, int skill, int hour, int projectQuality, int items[], int partners[], int newGame);
int choose1(void);
int choose2(void);
int choose3(void);
int energyCheck(int energy, int hours);
void harass(void);
void eldritch(int items[], int partners[]);
void finalSave(int items[], int newGame);
#endif

