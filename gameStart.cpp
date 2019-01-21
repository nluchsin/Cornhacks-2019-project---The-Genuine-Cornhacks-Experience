//Developed by 
//Nathan Luchsinger
//Rustin Haase
//Mike Senior
//Phoebe Sulistio
#include "gameStart.h"
#include <string>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <vector>
#include <fstream>
#include <sstream> 
using namespace std;


int main(void){
	gameStart();
	return 0;
}

int gameStart(void){
	int win = 0;
	int choose = 0;
	int location=1;
	int items[3];

		int energy = 0;
		int skill = 0;
		int hour = 0;
		int projectQuality = 0;
		int partners[7];
		int newGame = 0;
	for(int n=0; n < 3; n++){
		items[n]=0;
	}
	
	
	//Load setting
	cout << "Do you wish to load a previous save? Type 1 for yes and 2 for no\n";
	while(choose == 0){
		cin>>choose;
		if(choose < 0 || choose > 2){
			"Invalid Selection!\n";
			choose=0;
		}
	}
	if(choose==1){
	//http://www.cplusplus.com/doc/tutorial/files/
		string line;
		ifstream myfile ("save.txt");
		int type = 0;
		int icount=0;
		int pcount=0;
		if (myfile.is_open()){
		while (getline(myfile,line)){
			if(line == "Inventory"){
				type = 1;
			}
			else if(line == "Location"){
				type = 2;
			}
			else if(line == "Energy"){
				type = 3;
			}
			else if(line == "Skill"){
				type = 4;
			}
			else if(line == "Hour"){
				type = 5;
			}
			else if(line == "ProjectQuality"){
				type = 6;
			}
			else if(line == "Partners"){
				type = 7;
			}
			else if(line == "NewGame"){
				type = 8;
			}
			else if(line.size()==0){
				type = 0;
			}
			else if(type == 1){
				stringstream s(line);
				s >> items[icount];
				icount++;
			}
			else if(type == 2){
				stringstream s(line);
				s >> location;
			}
			else if(type == 3){
				stringstream s(line);
				s >> energy;
			}
			else if(type == 4){
				stringstream s(line);
				s >> skill;
			}
			else if(type == 5){
				stringstream s(line);
				s >> hour;
			}
			else if(type == 6){
				stringstream s(line);
				s >> projectQuality;
			}
			else if(type == 7){
				stringstream s(line);
				s >> partners[pcount];
				icount++;
			}
			else if(type == 8){
				stringstream s(line);
				s >> newGame;
			}	
		}
		myfile.close();
	}
	else{
		cout << "Unable to open file. Generating new save"; 
		location=1;
		for(int n=0; n < 3; n++){
			items[n]=0;
		}
		energy = 70;
		skill = 0;
		hour = 0;
		projectQuality = 0;
		for(int n=0; n < 7; n++){
			partners[n]=0;
		}
		newGame = 0;
	}	
	}
	else{
		location=1;
		for(int n=0; n < 3; n++){
			items[n]=0;
		}
		energy = 70;
		skill = 0;
		hour = 0;
		projectQuality = 0;
		for(int n=0; n < 7; n++){
			partners[n]=0;
		}
		newGame = 0;
	}



	choose = 0;
	cout << "Type 1 to start\n";
	 
	while(choose <=5){
		
			
		cin>>choose;

		if(choose == 1){
			int *ret;
			ret= quest(energy, skill, hour, projectQuality, items, partners, newGame);
			
				energy=ret[0]; //set this to reverse
				skill=ret[1];
				hour=ret[2];
				projectQuality=ret[3];
				items[0]=ret[4];
				items[1]=ret[5];
				items[2]=ret[6];
				partners[0]=ret[7];
				partners[1]=ret[8];
				partners[2]=ret[9];
				partners[3]=ret[10];
				partners[4]=ret[11];
				partners[5]=ret[12];
				partners[6]=ret[13];
				newGame=ret[14];

			
			
		}
		else if(choose == 2){
			printLocation(partners);
		}
		
		else if(choose == 3){
			printItems(items);
		}
		else if(choose == 4){
			saveFile(items, location, energy, skill, hour, projectQuality, partners, newGame);
		}
		else if(choose == 5){
			saveFile(items, location, energy, skill, hour, projectQuality, partners, newGame);
			break;
		}
	}
	return 0;
}

void printLocation(int partners[]){
	cout << "Partners:\n";
	if(partners[0]==1){
		cout<<"Ultimate Coding Genius Savior\n";
	}
	if(partners[1]==1){
		cout<<"Overworker\n";
	}
	if(partners[2]==1){
		cout<<"Night Owl\n";
	}
	if(partners[3]==1){
		cout<<"The Coffee Guy\n";
	}
	if(partners[4]==1){
		cout<<"Slap-Bros Champ\n";
	}
	if(partners[5]==1){
		cout<<"Gopher\n";
	}
	if(partners[6]==1){
		cout<<"Dan Smith\n";
	}
	return;
}

void printItems(int items[]){
	if(items[0] == 1){
		cout<<"A Gift Card\n";
	}
	if(items[1] == 1){
		cout<<"A Easy Button\n";
	}
	if(items[2] == 1){
		cout<<"A Strange Button\n";
	}
	if(items[0]==0 && items[1]==0 && items[2]==0){
		cout<<"No items!\n";
	}
	cout << "\n";
}


void saveFile(int items[], int location, int energy, int skill, int hour, int projectQuality, int partners[], int newGame){
  cout << "You are saving the game.\n";
  //http://www.cplusplus.com/doc/tutorial/files/
  ofstream myfile;
  myfile.open ("save.txt");
//Inventory
  myfile << "Inventory\n";
  for(int n = 0; n < 3; n++){
		myfile << items[n] << "\n";
	}
//Location
	myfile << "\n\nLocation\n";
	myfile << location<<"\n";
//Energy
	myfile << "\n\nEnergy\n";
	myfile << energy<<"\n";
//skill
	myfile << "\n\nSkill\n";
	myfile << skill<<"\n";
//hour
	myfile << "\n\nHour\n";
	myfile << hour<<"\n";
//projectQuality
	myfile << "\n\nProjectQuality\n";
	myfile << projectQuality<<"\n";
//partners
	myfile << "Partners\n";
  for(int n = 0; n < 7; n++){
		myfile << partners[n] << "\n";
	}
//newGame
	myfile << "\n\nNewGame\n";
	myfile << newGame<<"\n";
  myfile.close();
	cout << "Saved!\n\n";
}
