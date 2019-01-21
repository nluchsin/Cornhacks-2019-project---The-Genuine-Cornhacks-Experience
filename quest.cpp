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

int * quest(int energy, int skill, int hour, int projectQuality, int items[], int partners[], int newGame){
cout << "This is the hour: " << hour << "\n";
	cout << "Energy: " << energy << "\nskill: " << skill << "\nProject Quality: " << projectQuality << "\n";
	int choose = 0;

		
		if(hour==1){ // 10 AM
		
		cout << "You arrive at Avery Hall. It’s really cold, but you’re happy you made the trek out here. You see a line for a breakfast buffet, but you could be using this time to brainstorm for the project. What do you do?\n";
		cout << "If you eat breakfast, press 1.\n";
		cout << "if you brainstorm for ideas, press 2.\n";
		choose=choose1();
			if(choose==1){
				cout<<"You got some free brain fuel. [+10 energy]\n";
				energy=energy+10;
			}
			else{
			cout<<"You try and get a head start on your project. [+5 Project Quality]\n";
			projectQuality=projectQuality+5;
			}
        }



		if(hour==2){//Choose teammates! 11 AM
			cout << "The opening statements are made regarding the rules of Cornhacks. Since you’ve been to a hackathon before, you know that you will have an extended amount of time to create a project with a team of up to four people, and said team is mandatory for participation. The organizer specifically mentions that harassment will not be tolerated and anyone who does so will be kicked out of the CornHack. You think about asking them to be your team members, but which ones?\n\n";
			cout << "Immediately, you recognize the Ultimate Coding Genius Savior of the World from his shrill voice proclaiming the fact that he seeks competent teammates. He was the one who continuously brought up practical applications and nonchalantly bragged about getting his assignments done early. You get the feeling that working with him will be taxing, as those around him are probably starting to pick up on.\n";
			cout << "Do you ask him to join your group? Type 1 for yes and 2 for no?\n";
			choose=choose1();
			int count=0;
			if(choose==1){
				cout << "He claps your back and congratulates you for being one of the first to ask him to be on his team. You sigh. [+2 Skill] [-10 Energy]\n";
				skill=skill+2;
				energy=energy-10;
				partners[0]=1;
				count++;
			}
			cout << "You have " << count << " of 3 possible teammates.\n";
			choose = 0;
			cout << "You spot the Overworker, who is taking notes fervently as usual, despite the lack of a lecturer. You recall that he has decent skill, but you did spot him passed out in the middle of an exam once. He seems to be very serious about putting 110% into his work, literally.\n";
			cout << "Do you ask him to join your group? Type 1 for yes and 2 for no?\n";
			choose=choose1();
			if(choose==1){
				cout << "The Overworker looks up, frustrated at first, but the perking up as you ask him to be your teammate. [+10 Project Quality]\n";
				projectQuality=projectQuality+10;
				partners[1]=1;
				count++;
			}
			cout << "You have " << count << " of 3 possible teammates.\n";
			choose=0;

			cout << "Speaking of passing out, the Night Owl is hanging around the back corner of the room. He looks to be half-asleep. He is one of your close friends however, and you are privy to his unusual sleep schedule--you know he can work hard, but for some reason it doesn’t kick in during the regular work hours.\n";
			cout << "Do you ask him to join your group? Type 1 for yes and 2 for no?\n";
			choose=choose1();
			if(choose==1){
				cout << "You prod the Night Owl on his shoulder to wake him. He sees you and nods, returning to his nap. [At midnight you will gain +3 Skill]\n";
				
				partners[2]=1;
				count++;
			}
			cout << "You have " << count << " of 3 possible teammates.\n";
			int test=0;
			if(count==3){
				cout<<"You have the maximum amount of teammates. It is time to get to work.\n";
				test=1;
			}
			choose=0;

			if(test==0){
				cout << "The Coffee Guy is sitting next to the Night Owl. You never really liked the Coffee Guy, but he seems to be a decent enough person, with a normal amount of skill for a CS major. Just a little too much fervor on the caffeine front, even by your standards. He totes around a large thermos of coffee though, and he isn’t shy about sharing it.\n";
				cout << "Do you ask him to join your group? Type 1 for yes and 2 for no?\n";
				choose=choose1();
				if(choose==1){
					cout << "You sit next to the Coffee Guy and he cheerfully greets you before asking if you have a team yet. You say “welcome aboard” and he bounces a little in his seat before offering you his newest blend. [+20 energy]\n";
					energy=energy+20;
					partners[3]=1;
					count++;
				}
				cout << "You have " << count << " of 3 possible teammates.\n";
				int test=0;
				if(count==3){
					cout<<"You have the maximum amount of teammates. It is time to get to work.\n";
					test=1;
				}
				choose=0;
			}

			if(test==0){
				cout << "Your buddy the Slap-Bros Champ is here. Why is he here? you wonder. He has very rudimentary interest in coding, being in the CS major mainly to appease his parents’ worries. You take a look at the brochure displaying the CornHacks schedule and you spot it; a Slap-Bros tournament at the end of the first day. It’s likely he is only here to take part in that.\n";
				cout << "Do you ask him to join your group? Type 1 for yes and 2 for no?\n";
				choose=choose1();
				if(choose==1){
					cout << "The Slap-Bros Champ turns to look at you, and attempts to greet you in Japanese. You cringe internally, then ask if he wants to be in your team. He refuses until you acquiesce and call him your “nakama.” [Their skill in Slap-Bros is unparalleled] \n";
					partners[4]=1;
					count++;
				}
				cout << "You have " << count << " of 3 possible teammates.\n";
				int test=0;
				if(count==3){
					cout<<"You have the maximum amount of teammates. It is time to get to work.\n";
					test=1;
				}
				choose=0;
			}

			if(test==0){
				cout << "The Gopher is busily running around outside, helping the volunteers with setting up. He has always been very eager to help, and has a low amount of skill but is usually willing to do any legwork to make up for his lack of contribution.\n";
				cout << "Do you ask him to join your group? Type 1 for yes and 2 for no?\n";
				choose=choose1();
				if(choose==1){
					cout << "The Gopher takes a break from the errands, and remembers he still doesn’t have a team. He gratefully accepts your offer. [They will get meals for you] \n";
					partners[5]=1;
					count++;
				}
				cout << "You have " << count << " of 3 possible teammates.\n";
				int test=0;
				if(count==3){
					cout<<"You have the maximum amount of teammates. It is time to get to work.\n";
					test=1;
				}
				choose=0;
			}

			if(test==0 && newGame>=1){
				cout << "Someone entered last minute. You don’t recall ever seeing him anywhere before, but he gives you the heebie-jeebies.\n";
				cout << "Do you ask him to join your group? Type 1 for yes and 2 for no?\n";
				choose=choose1();
				if(choose==1){
					cout << "He nods. He introduces himself as Dan Smith. He insists you work on a strange device for your project [+?????????????] \n";
					partners[6]=1;
					count++;
				}
				cout << "You have " << count << " of 3 possible teammates.\n";
				int test=0;
				if(count==3){
					cout<<"You have the maximum amount of teammates. It is time to get to work.\n";
					test=1;
				}
				choose=0;
			}
			if(test==0){
				cout<<"You look around the room. There is no one else available to join the group. You will have to work with what you have.\n";
			}
			
		}


		if(hour==3){ // 12 PM
		cout << "After settling on a team and listening to the opening words, you can begin working. There is also a workshop going on, titled “Like, Comment, and Smash That Merge Button” led by Spritaly, a company that specializes in ecommerce. What do you want to do?\n";
		cout << "If you want to work on project, type 1.\n";
		cout << "if you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";
		cout << "If you decide to attend the workshop, type 3.\n";
		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else{
				cout << "You gain some potential button based ideas for your project. [+1 Skill]\n";
				if(partners[1]==1){
					cout<< "The presenter recognizes one of your teammates. “You’ve been taking the hard road for too long friend. Here, take this.” He hands your team an Easy Button. [Easy Button added to inventory]\n";
					items[1]=1;
				}
			}
			hour=energyCheck(energy,hour);
		}
		
		if(hour==4){ // 1 PM
		cout << "You return to your work room. The other teams are already chattering excitedly about their ideas. \n";
		if(partners[5]==1){
			cout<<"The gopher delivers lunch to you [+10 energy]\n";
			energy=energy+10;
		}
		cout << "If you want to work on project, type 1.\n";
		cout << "if you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";
		if(partners[5]==0){
			cout << "If you decide to go to lunch, type 3.\n";
		}
		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else if(partners[5]==0){
				cout<<"You get a nice and filling lunch [+10 energy]";
				energy=energy+10;
			}
			hour=energyCheck(energy,hour);
		}
	
		if(hour==5){ // 2 PM
		cout << "You return to your work room. Your teammates want to try and discuss the project with the other teams. What do you want to do? \n";
		cout << "If you want to work on project, type 1.\n";
		cout << "if you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";
		cout << "If you wish to discuss with the other team, type 3.\n";
		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else{
				cout<<"You gain some ideas from the discussion [+1 skill]\n";
				energy=energy+10;
			}
			hour=energyCheck(energy,hour);
		}

		if(hour==6){ // 3 PM
		cout << "Another workshop is about to take place, this time conducted by Buildabend, a construction project management software company. It is titled, “How a simple Chrome extension can make you a better gamer.” How will you spend this time?\n";
		cout << "If you want to work on project, type 1.\n";
		cout << "If you want to harass a fellow member press 2.\n";
		cout << "Accept their help? press 3.\n";
		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else{
				cout<<"You learn some information about developing extensions [+1 skill]\n";
				skill = skill + 1;
				if(partners[3]==1){
					cout<<" Your coffee addicted teammate seems especially engaged with the presentation and applied it to the project. [+5 game quality]\n";
					projectQuality = projectQuality + 5 + skill;
					
				}
				else if(partners[3]==0){
					cout<<"You notice that one of the students seems to be especially engaged with the project, they are holding two cups of coffee in their hands.\n";
				}
			
		}
		hour=energyCheck(energy,hour);
	}	

		if(hour==7){ // 4 PM
		cout << "There is a workshop called “From Me to We” that is about to start, led by XD Astrolade, an online broker used to trade stocks, plan for retirement, and investment. \n";
		cout << "If you want to work on project, type 1.\n";
		cout << "If you want to harass a fellow member, type 2.\n";
		cout << "If you want to go to the workshop, type 3.\n";
		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else{
				cout<<"You learn some information about developing extensions [+1 skill]\n";
				skill = skill + 1;
				if(partners[0]==1){
					cout<<" Your coding genius teammate is enraged by this workshop and starts shouting about how he shouldn’t have to work with incapable people, he is promptly escorted out of the building. It's a relief he is no longer on your team [+20 energy] but it is a shame he is not going to be able to help with your project anymore [+20 energy][-2 skill]\n";
					energy=energy+20;
					skill=skill-2;
					partners[0]==0;
					
				}
				else if(partners[0]==0){
					cout<<"You notice that one of the students seem very annoyed by this presentation and starts shouting about how they shouldn’t have to work with idiots, they are promptly escorted out.\n";
				}
			
			}
			hour=energyCheck(energy,hour);
		}
		if(hour==8){ // 5 PM
		cout << "It’s dinner time!. \n";
		if(partners[5]==1){
			cout<<"The gopher gets dinner for you.[+10 energy]\n";
			energy=energy+10;
		}
		cout << "If you want to work on project, type 1.\n";
		cout << "If you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";
		if(partners[5]==0){
			cout << "If you decide to go get dinner, type 3.\n";
		}
		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else if(partners[5]==0){
				cout<<"You got some free dinner, nothing beats pizza and soup! [+10 energy]";
				energy=energy+10;
			}
			hour=energyCheck(energy,hour);
		}
		if(hour==9){ // 6 PM
		cout << "A fellow team wants to compare their project to yours. This could be a good learning experience. If you have a superior product so far it may motivate your team. \n";
		
		cout << "If you want to work on project, type 1.\n";
		cout << "If you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";
		cout << "if you would like to compare projects, type 3,\n";

		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else{
				cout << "You gain some ideas from looking at their project. [+1 Skill]\n";
				skill = skill + 1;
				if(projectQuality >= 20){
					cout << "So far your project seems to be farther along than theirs, this motivates your team [+10 energy]\n";
					energy = energy + 10; 
				}
				else{
					cout << "They seem to be farther along with their project, your team feels like they are not making significant progress, demotivating them. [-10 energy] \n";
					energy = energy - 10;
				}
			}
			hour=energyCheck(energy,hour);
		}
		if(hour==10){  // 7 PM
		cout << "One of the systems in your project is turning out to be far more complex than you thought it would be, it will give you some time to rest if you give up on it. \n";
		
		cout << "If you want to work on project, type 1.\n";
		cout << "If you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";
		cout << "If you would like to give up on the system, type 3,\n";

		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else{
				
				cout << "You give up on the system and spend the hour relaxing. The lack of the system limits what you can do for your project, however. [+20 energy] [-5 product quality]\n";
				energy = energy + 20;
				projectQuality = projectQuality -5;
			}
			hour=energyCheck(energy,hour);
		}
		if(hour==11){ // 8 PM
		cout << "You see the CORNHACKS corn suit man outside the room.\n";
		
		cout << "If you want to work on project, type 1.\n";
		cout << "If you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";
		cout << "If you would like hang out with the corn suit man, type 3,\n";

		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else{
				
				cout << "You feel re-energized after stretching with this legendary individual. [+10 energy]\n";
				energy = energy + 10;
			}
			hour=energyCheck(energy,hour);
		}
		if(hour==12){ // 9 PM
		cout << "The Slap Bros. Tournament is about to begin. Will you participate?\n";
		if(items[1] == 1){
			cout << "You think you could use the easy button as a controller for the tournament.\n";
		}
		
		cout << "If you want to work on project, type 1.\n";
		cout << "If you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";
		cout << "If you would like to participate in the tournament, type 3,\n";
		if(items[1] == 1){
			cout << "If you would like to participate in the tournament, using the easy button, type 4\n";
		}

		choose=choose3();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==4){
				cout<<"By mashing on the easy button you crush all your competition with ease. Unfortunately the easy button is destroyed in the process. [Gain Gift Card] [+10 energy] [Lose Easy Button]\n";
				items[0] = 1;
				energy = energy + 10;
				items[1] = 0;
			}
			else if(choose==2){
				harass();
			}
			else{
				if(partners[4] == 1){
					cout << "Thankfully the slap bros guy is on your team, and he shares the Gift Card of the Amazonians with you. [Gain Gift Card] [+10 energy] \n";
					items[0] = 1;
					energy = energy + 10;
				} else {
					energy = energy + 10;
					cout << "You do pretty well and end up earning second place, the slap bros guy getting first.\n";
				}	
				
			}
			hour=energyCheck(energy,hour);
		}
		if(hour==13){  //10 PM
		if(projectQuality < 30){
			cout << "Your team is dissapointed about the lack of progress they've made [-10 energy].\n";
			energy = energy -10;
		} else{
			cout << "Your team seems happy with the progress made so far.\n";
		}
		
		
		cout << "If you want to work on project, type 1.\n";
		cout << "If you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";

		choose=choose1();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else{
				harass();
			}
			hour=energyCheck(energy,hour);
		}
		if(hour==14){ // 11 PM
		cout << "The same team from earlier seeks to compare their project with you again. They seem to be pretty far along with their project. \n";
		cout << "If you want to work on project, type 1.\n";
		cout << "If you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";
		cout << "if you would like to compare projects, type 3,\n";

		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else{
				cout << "You gain some ideas from looking at their mostly finished project. [+1 Skill]\n";
				skill = skill + 1;
				if(projectQuality >= 40){
					cout << "So far your project seems to be farther along than theirs, this motivates your team [+10 energy]\n";
					energy = energy + 10; 
				}
				else{
					cout << "They seem to be farther along with their project, your team feels like they are not making significant progress, demotivating them. [-10 energy] \n";
					energy = energy - 10;
				}
			}
			hour=energyCheck(energy,hour);
		}
			
		if(hour==15){  //Eldritch STORYLINE 12 AM
			
			if (partners[6] == 1 && items[2] == 1){
				cout << "Dan pulls you towards the Faculty Room. Strangely, you feel compelled to follow him despite not having much justification for doing so.\n";
				
			} else{
				
				cout << "It is midnight and getting late.\n";
				energy = energy - 5;
				if (partners[2] == 1) { //NIGHT OWL
					cout << "It is midnight, the night owl seems fully ready to work [+3 skill]\n";
					skill = skill + 3;
				}
				cout << "If you want to work on project, type 1.\n";
				cout << "If you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";
				if (partners[6] == 1 && items[2] == 1){
					cout << "If you wish to follow Dan, type 3\n";
				}
			choose=choose3();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else if(choose==3){
				eldritch(items, partners);
			}
			hour=energyCheck(energy,hour);
		}
			}
			
		if(hour == 16){ // 1 AM
			
				energy = energy - 5;
				cout << "It’s getting late and you are getting tired [-5 energy]\n";
				cout << "If you want to work on project, type 1.\n";
				cout << "If you decide to harass some fellow members of Cornhacks, type 2.\n";
		
		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			hour=energyCheck(energy,hour);
		}
		
		
		if(hour == 17){ // 2 AM
			
				energy = energy - 5;
				cout << "You start to doubt whether it is worth it to continue working. [-5 energy]\n";
				cout << "If you want to work on project, type 1.\n";
				cout << "If you decide to harass the night owls at Cornhacks, type 2.\n";
		
		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			hour=energyCheck(energy,hour);
		}
		
		
		if(hour == 18){ // 3 AM -- TODO!!!!!!!!!!!!!!!!!!!!!!
			
				cout << "It’s 3 AM, the most haunted hour. As is CornHacks tradition, a ghost rises from the depths of Avery Hall.\n";
				if(items[0] == 1){
					cout << "Continuing with CornHacks tradition, you bribe the ghost using your amazonian gift card. They help out with your project and teach you about boo-leans [+1 Skill] [+5 Project quality]\n";
					skill = skill + 1;
					projectQuality = projectQuality + 5 + skill;
				}else if(partners[2] == 1){
					cout << "The night owl, at full power, punches the ghost away, stopping them from interfering with the project.\n";
				}else {
					cout << "You have no protection, The ghost haunts your project, which has the potential to be inspirational--unfortunately, you aren’t making a horror game. [-10 project quality]\n";
					projectQuality = projectQuality - 10;
				}
		
		}
		
		
		if(hour == 19){ // 4 AM
			
				energy = energy - 5;
				cout << "You struggle to keep yourself awake. [-5 energy]\n";
				cout << "If you want to work on project, type 1.\n";
				cout << "Harass the night owls at Cornhacks, type 2.\n";
		
		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			hour=energyCheck(energy,hour);
		}
		
		if(hour == 20){ // 5 AM
			
				energy = energy - 5;
				cout << "You are tired, but feel determined to make it through the night. [-5 energy]\n";
				cout << "If you want to work on project, type 1.\n";
				cout << "Harass somebody that still moves, type 2.\n";
		
		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			hour=energyCheck(energy,hour);
		}
		
		if(hour == 21){ // 6 AM
			
				energy = energy - 5;
				cout << "It is almost morning time. It is almost over. [-5 energy]\n";
				cout << "If you want to work on project, type 1.\n";
				cout << "Harass the early comers, type 2.\n";
		
		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			hour=energyCheck(energy,hour);
		}
			
		if(hour == 22){ // 7 AM
			
				energy = energy - 5;
				cout << "A volunteer has shown up early and offers to help your group.\n";
				cout << "If you want to work on project, type 1.\n";
				cout << "Harass the early comers, type 2.\n";
				cout << "A volunteer has shown up early and offers to help, type 3.\n";
		
		choose=choose3();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else if(choose==3){
				skill = skill + 1;
				projectQuality = projectQuality + 10;
			}
			hour=energyCheck(energy,hour);
		}
			
			
		
		if(hour==23){ // 8 AM
		cout << "You enter your work room. The other teams are already chattering excitedly about their nearly completed ideas. \n";
		if(partners[5]==1){
			cout<<"The gopher delivers breakfast to you [+10 energy]\n";
			energy=energy+10;
		}
		cout << "If you want to work on project, type 1.\n";
		cout << "if you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";
		if(partners[5]==0){
			cout << "If you decide to go to breakfast, type 3.\n";
		}
		choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else if(partners[5]==0){
				cout<<"You get a heart-healthy breakfast [+10 energy]\n";
				energy=energy+10;
			}
			hour=energyCheck(energy,hour);
		}
		
if(hour==24){ // 9 AM
		cout << "You enter your work room. For the last time! \n";
		cout << "If you want to work on project, type 1.\n";
		cout << "If you decide to break Cornhack's rules and harass your fellow members of Cornhacks, type 2.\n";
		if(energy >= 30){
		cout << "You can expend a lot of energy to push your project to the limit!, type 3\n";
		}
	choose=choose2();
			if(choose==1){
				cout<<"You work hard on your project\n";
				energy=energy-10;
				projectQuality=projectQuality+5+skill;
			}
			else if(choose==2){
				harass();
			}
			else if(energy >= 30){
				cout<<"You go MAXIMUM OVERDRIVE!!!!! [-30 energy][+20 Product Quality]\n";
				energy=energy+10;
			}
			hour=energyCheck(energy,hour);
		}		
		
	if (hour == 25) {
		cout << "It’s time for the awards ceremony, and you and your team wait for the announcements. You feel like you’ve put your best foot forward with this project, and regardless of how you did in\n";
		cout << "the actual project, you know you’ve learned a lot about the process of planning, creating, fine-tuning, and debugging a program you created from scratch. You look around at your team\n";
		cout << "members and recall the lessons on teamwork that you’d learned from working with people you usually don’t work with.\n";
		cout << "The awards are read out and you discover your team has:\n";
		
		if(projectQuality >= 100){
			cout << "You won second place! Your team is very happy with this result and everyone gets their GPS 1080P HD wi-fi-enabled drones. Afterwards a strangeYour team rejoices and you get your Not-tendo Switch as a prize. Afterwards a strange individual";
			cout << " with a cloak hands you a strange device. You have truly done excellently in this challenge. Your project will go down as one of the greatest in CornHacks history.\n";
			cout << "BEST END!!!\n";
			finalSave(items, newGame);
		}else if(projectQuality < 100 && projectQuality >= 90){
			
			cout << "You won second place! Your team is very happy with this result and everyone gets their GPS 1080P HD wi-fi-enabled drones. Afterwards a strange\n";
			cout << "individual with a cloak hands you a strange device. You have truly done well, but there is potential to do even better.\n";
			cout << "THE END";
			finalSave(items, newGame);
		}else if(projectQuality < 90 && projectQuality >=80){
			cout << "You won second place! Your team is very happy with this result and everyone gets their GPS 1080P HD wi-fi-enabled drones. Afterwards a strange \n";
			cout << "individual with a cloak hands you a strange device. You have truly done well, but there is potential to do even better.\n ";
			cout << "THE END";
			finalSave(items, newGame);
		}else if(projectQuality < 80 && projectQuality > 40){
			cout << "You won third place! Your team is rather pleased with this result and everyone gets their Bose Soundlink II speakers. Afterwards a strange individual with\n";
			cout << "a cloak hands you a strange device. You’re pretty good, but it is possible to do even better.\n ";
			cout << "THE END";
			finalSave(items, newGame);
		}else if(projectQuality < 40) {
			cout << "You have  not placed in the top 3, but you have gained a valuable experience in creating a product. Perhaps these skills will allow you to thrive in life and the next cornhack.\n";
			cout << "THE END";
			finalSave(items, newGame);
		}
	}
				
			
		
		
		
		
		
		

		
		
//Dont touch anything below this line under any circumstances.
cout<<"\n1 = Next Hour\n2=Partners\n3=Inventory\n4=save\n5=save & exit\n";
hour = hour + 1;
static int ret[15];
	ret[0]=energy;
	ret[1]=skill;
	ret[2]=hour;
	ret[3]=projectQuality;
	ret[4]=items[0];
	ret[5]=items[1];
	ret[6]=items[2];
	ret[7]=partners[0];
	ret[8]=partners[1];
	ret[9]=partners[2];
	ret[10]=partners[3];
	ret[11]=partners[4];
	ret[12]=partners[5];
	ret[13]=partners[6];
	ret[14]=newGame;

return ret;
}

int choose1(void){
	int choose=0;
	while(choose == 0){
		cin>>choose;
		if(choose < 0 || choose > 2){
			"Invalid Selection!\n";
			choose=0;
		}
	}
return choose;
}

int choose2(void){
	int choose=0;
	while(choose == 0){
		cin>>choose;
		if(choose < 0 || choose > 3){
			"Invalid Selection!\n";
			choose=0;
		}
	}
return choose;
}

int choose3(void){
	int choose=0;
	while(choose == 0){
		cin>>choose;
		if(choose < 0 || choose > 4){
			"Invalid Selection!\n";
			choose=0;
		}
	}
return choose;
}

int energyCheck(int energy, int hours){
	int hour=hours;
	if(energy<=0){
		cout<<"You are out of energy. You wrap up your project and go home to rest.\n";
		hour=25;
	}
	else{
		hour=hours;
	}
return hour;
}

void harass(void){
	cout<<"You make the eternal mistake of harassing the other members of Cornhacks. As a result, you are ejected and banned for life from Cornhacks.\n";
		if (remove("save.txt") == 0){
		}
exit(0);
}

void eldritch(int items[], int partners[]){
	int choose = 0;
	cout<<"Whenever you felt like stopping, he would keep going, to the point of almost bumping into you, and you would instinctively try to distance yourself from how physically close you were to this… being. [Keep walking]\n";
	cout<<"Whoever he is--whatever he is, Dan does not feel very normal at all right now. You start to feel unease, walking down this hallway. Hallway? Since when did the Faculty Room have a hallway? Dan is still behind you. \n";
	cout<<"As you walk, you try to pay more attention to the hallway around you, to see if you could figure out where on Earth you are, but you can’t seem to recall any details you try to focus on.\n";
	cout<<"The walls start to melt away.\n";
	cout<<"'We’re here.'\n";
	cout<<"The voice that sounded like Dan’s seemed to hold a finality to it. You turn around, but you don’t see Dan anywhere. Your other teammates stared straight ahead, glassy-eyed. No matter how much you try to shake them, you can’t get them to respond to you. The door to your left swung open.\n";
	cout<<"To go through the door, type 1\n";
	while(choose !=1){
		cin>>choose;
	}
	choose=0;
	cout<<"Dan was already inside, standing in the center of the room. The deep green splotches on the walls completely saturated your vision. The ground felt like it would give way if you set foot anywhere you shouldn’t. Suffice it to say you should not try to step outside now that you have come in.\n";
	cout<<"To take your place as an offering, type 1\n";
	
	choose=0;
	cout<<"You realize that you about to die. You consider your options:\n";
	cout<<"If you wish to become the sacrifice, type 1.\n";
	if(items[1]==1){
	cout<<"You have the easy button, a potentially dangerous artifact in its own right. It may be powerful enough to save you and you have nothing to lose. If you want to try it, type 1.\n";
	}
	if(partners[3]==1){
	cout<<"Coffee Guy's thermos of coffee is present. It might give you enough energy to defeat Dan. To drink the coffee, type 3.\n";
	}
	if(items[2]==1){
	cout<<"The strange artifact that has followed you for so very long begins to whisper in your mind, giving you ways to use the device and its currently unknown uses. To try the device, type 4\n";
	}
	while(choose !=1){
		cin>>choose;
	}
	if(choose==1){
		cout<<"You have nothing in your arsenal to help you conquer this abomination. Helpless to escape the clutches of the sacrificial circle, you are absorbed into the mass of hands before you. [Death by Dan]\n";
		if (remove("save.txt") == 0){
		}
	}
	else if(choose==2){
		cout<<"You pull out the easy button, mashing it as hard as you can. The chanting stops, replaced by a blood-curdling scream of horror. The easy button absorbs what used to be Dan, and you pop back out the other side of the Faculty Room door. Harrowed by the events of tonight, you decide to head home and call to see about arranging appointments with a therapist.\n";
		cout<<"The next day, you and your two teammates submitted the Easy Button, which you remembered had saved you the night before. Upon explanation, you received the second place prize, and you were sent home to tend to your newfound paranoia. The Faculty Room was shut down indefinitely for “renovations.” [Survival]\n";	
	}
	else if(choose==3){
		cout<<"You spot the thermos of Coffee Guy’s special blend, and chug down what little remained of it to give yourself the strength to tackle Dan. Succeeding, your teammates snapped out of it, and you desperately yelled at them to help you take him down. You beat the unliving daylights out of Dan, and are teleported out of the Faculty Hallway before promptly passing out.\n";
		cout<<"When you come to, you notice that it is well past noon the next day. What’s more, you appear to be in a hospital. It looks like you went through quite the experience, but at least you’ve saved all three of your teammates. Thank goodness Dan managed to turn something in, earning you all a second place prize. [Survival]\n";
	}
	else if(choose==4){
		cout<<"The strange device that you had received at the last Cornhacks blazed with eldritch fire as a strange voice whispered in your head to aim it at Dan and press a button on the device. As you did, the strange device disintegrated Dan, before dragging the resulting wreckage and energy back into the device. The fire from the device consumed your body and mortality in a blaze of light, and you ceased to be something even remotely human.\n";
		cout<<"Your new ascendent self, perhaps a newborn god, perhaps something else, reached back through time with its new self. At the Cornhacks so long ago, you disguise yourself in human form and gift the strange device to your younger self, as well as whisper in your ear during your confrontation with Dan. With this completed and your ascension assured in all timelines and all realities, you travel out into the universe, where other gods lie in wait. [Ascension]\n";
		if (remove("save.txt") == 0){
		}
	}
}

void finalSave(int items[], int newGame){
  cout << "You are saving the game.\n";
  //http://www.cplusplus.com/doc/tutorial/files/
  ofstream myfile;
  myfile.open ("save.txt");
//Inventory
  myfile << "Inventory\n";
  myfile<< "0\n";
	
	myfile<< "0\n";
	myfile << items[2] << "\n";
//Location
	myfile << "\n\nLocation\n";
	myfile<< "0\n";
//Energy
	myfile << "\n\nEnergy\n";
	myfile<< "0\n";
//skill
	myfile << "\n\nSkill\n";
	myfile<< "0\n";
//hour
	myfile << "\n\nHour\n";
	myfile<< "0\n";
//projectQuality
	myfile << "\n\nProjectQuality\n";
	myfile<< "0\n";
//partners
	myfile << "Partners\n";
  for(int n = 0; n < 7; n++){
		myfile<< "0\n";
	}
//newGame
	myfile << "\n\nNewGame\n";
	myfile << newGame+1<<"\n";
  myfile.close();
	cout << "New Game+ save available. Restart game with save to go around again!\n\n";
	
}