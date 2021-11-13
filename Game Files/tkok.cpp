#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <array>
#include "ConsoleColor.h"
#include "GameEvents.h"
#include "CombatEvents.h"

using namespace std;

const int EVENTS = 11;

typedef array<bool, EVENTS> Events;

/// Text Functions

void intro(Game& g){                                            /// Introduction Text

    cout<<"In the vast lands of "<<green<<"Kyura"<<white<<", the light had brought peace to the world and everything had been balanced. "
    <<"\n\nThe queen of the region, "<<blue<<"Aurora"<<white<<", was the beloved ruler of the reigns and the priest who spoke directly to the gods. "
    <<"\nHowever, the vampires had been planning an attack to take over the lands of "<<green<<"Kyura"<<white<<". "
    <<"\n\nGuided by "<<red<<"Drakar, Lord of the Vampires"<<white<<", they took over the lands of light and kidnapped the queen "<<blue<<"Aurora"<<white<<", "
    <<"\nkilling anyone whose will was against "<<red<<"Drakar's"<<white<<" reign. "
    <<"\n\nYou are the only hope for "<<blue<<"Aurora"<<white<<" and the citizens to restore the light once again and bring back peace and balance. "<<endl;

	cout<<yellow<<" _____ _              _   __      _       _     _              __     _   __                       "<<endl;
	cout<<"|_   _| |            | | / /     (_)     | |   | |            / _|   | | / /                       "<<endl;
	cout<<"  | | | |__   ___    | |/ / _ __  _  __ _| |__ | |_      ___ | |_    | |/ / _   _ _   _ _ __ __ _  "<<endl;
	cout<<"  | | | '_ \\ / _ \\   |    \\| '_ \\| |/ _` | '_ \\| __|    / _ \\|  _|   |    \\| | | | | | | '__/ _` | "<<endl;
	cout<<"  | | | | | |  __/   | |\\  \\ | | | | (_| | | | | |_    | (_) | |     | |\\  \\ |_| | |_| | | | (_| | "<<endl;
	cout<<"  |_| |_| |_|\\___|   |_| \\_/_| |_|_|\\__, |_| |_|\\__|    \\___/|_|     |_| \\_/\\__, |\\__,_|_|  \\__,_| "<<endl;
	cout<<"                                     __/ |                                   __/ |                 "<<endl;
	cout<<"                                    |___/                                   |___/                  "<<white<<endl;
	cout<<"\nWelcome to the game. Do you want to start your journey?";

	do{
        cout<<"\n(Y)es/(N)o: ";
        cin>>g.step;
	}while(((g.step!='Y')&&(g.step!='N'))&&((g.step!='y')&&(g.step!='n')));

}

void text(int t){                                               /// ASCII Text Function
    switch(t){
        case 0: cout<<yellow<<" _____                           _____                "<<endl;
                cout<<"|  __ \\                         |  _  |               "<<endl;
                cout<<"| |  \\/ __ _ _ __ ___   ___     | | | |_   _____ _ __ "<<endl;
                cout<<"| | __ / _` | '_ ` _ \\ / _ \\    | | | \\ \\ / / _ \\ '__|"<<endl;
                cout<<"| |_\\ \\ (_| | | | | | |  __/    \\ \\_/ /\\ V /  __/ |   "<<endl;
                cout<<" \\____/\\__,_|_| |_| |_|\\___|     \\___/  \\_/ \\___|_|   "<<endl;
                cout<<"                                                      "<<endl;
                cout<<"                                                      "<<white<<endl;
                break;
        case 1: cout<<green<<" __     __                    _       "<<endl;
                cout<<" \\ \\   / /                   (_)      "<<endl;
                cout<<"  \\ \\_/ /__  _   _  __      ___ _ __  "<<endl;
                cout<<"   \\   / _ \\| | | | \\ \\ /\\ / / | '_ \\ "<<endl;
                cout<<"    | | (_) | |_| |  \\ V  V /| | | | |"<<endl;
                cout<<"    |_|\\___/ \\__,_|   \\_/\\_/ |_|_| |_|"<<endl;
                cout<<"                                      "<<endl;
                cout<<"                                      "<<white<<endl;
                break;
    }

    cout<<green<<"\nLeaving the game... Thanks for playing!";
    cout<<"\nGame developed by "<<red<<"firehellrain"<<white<<endl;
}

void checkStep(Game& g){                                        /// Outputs Text depending on Game Status

    if((g.step=='N')||(g.step=='n')){
        if(!g.win){
            g.endGame = true;
            system("cls");
            cout<<"You got "<<red<<"killed"<<white<<" during a fight and your soul perished in hell. \nWithout their only saviour, the fate of "<<green<<"Kyura"<<white<<" had been condemned."
            <<"\nQueen "<<blue<<"Aurora"<<white<<" was executed in public and the vampires took over the realm."<<endl;
            text(0);
        } else {
            g.endGame = true;
            system("cls");
            cout<<"You abandon the lands of "<<green<<"Kyura"<<white<<" and leave the people to their own fate. \nQueen "<<blue<<"Aurora"<<white<<" was executed in public and the vampires"
            <<"took over the realm. \nSome weeks later, you "<<red<<"die"<<white<<" assaulted by a bunch of bandits in the outskirts of the reign."<<endl;
            text(0);
        }
    } else if((g.step=='Y')||(g.step=='y')) system("cls");
    else if(g.step=='w'){
        g.endGame = true;
        cout<<"\nYou have killed the final boss! You rescued queen "<<blue<<"Aurora"<<white<<" and brought back peace to the lands of Kyura."<<endl;
        text(1);
    }
}

/// Game Functions

void startGameVars(Player& p, Monster& m, Game& g){             /// Declaration of Game Variables

    // Monster Vars
    m.health = 15;
    m.name = 'A';
    m.fireball = false;

    // Player Vars
    p.health = 50;
    p.heals = 5;
    p.fireballs = 0;
    p.dogAttack = 0;

    p.spells = false;
    p.fireball = false;
    p.box = false;
    p.cursed = false;
    p.hbonus = false;
    p.key = false;
    p.ring = false;
    p.shield = false;
    p.sword = false;
    p.vampire = false;
    p.dog = false;
    p.food = false;
    p.lube = false;
    p.revive = false;
    p.medicine = false;
    p.icescorch = false;
    p.healboost = false;

    // Game Vars
    g.round = 1;
    g.win = true;
    g.endGame = false;
    g.terminal = false;
}

void newRound(Game& g, Monster& m){                             /// Next Round Choice Input
    if (m.name!='D'){
        do{
            cout<<"\nContinue to the next zone! (Y/N): ";
            cin>>g.step;
        }while(((g.step!='Y')&&(g.step!='N'))&&((g.step!='y')&&(g.step!='n')));
    } else  g.step = 'w';
}

void restartGame(Player& p, Monster& m, Game& g, Events& e){    /// Restarts the Game Variables and Events

    startGameVars(p, m, g);
    for(int i = 0; i<EVENTS; i++) e[i] = false;
    system("cls");

}

void replay(Player& p, Monster& m, Game& g, Events& e){         /// New Game Choice Input

    do{
        cout<<"Replay? (Y/N): ";
        cin>>g.step;
    }while(((g.step!='Y')&&(g.step!='N'))&&((g.step!='y')&&(g.step!='n')));

    if(g.step=='Y' || g.step=='y') restartGame(p, m, g, e);
    else checkStep(g);

}

void updateGame(Player& p, Monster& m, Game& g){                /// Updates Game Variables Each Round

    if(!g.endGame){
        if(g.win){
            switch(g.round){
                case 2: m.health = 30;
                        break;
                case 3: m.name = 'B';
                        p.heals = 5;
                        cout<<"Your "<<green<<"healing"<<white<<" spells have been refilled."<<endl;
                        g.terminal = false;
                        break;
                case 4: m.health = 45; break;
                case 5: g.terminal = false; break;
                case 6: m.name = 'C';
                        p.spells = true;
                        p.fireballs = 5;
                        p.heals = 5;
                        p.fireball = true;
                        g.terminal = false;
                        cout<<"You have unlocked the "<<red<<"fireball"<<white<<" spell! You only have 5 uses until the end of the game.";
                        cout<<"\nYour "<<green<<"healing"<<white<<" spells have been refilled."<<endl;
                        break;
                case 7: m.health = 60; break;
                case 8: g.terminal = false; break;
                case 9: m.health = 60;
                        g.terminal = false;
                        m.name = 'D';
                        p.heals = 5;
                        cout<<"Your "<<green<<"healing"<<white<<" spells have been refilled."<<endl;
                        break;
            }
        }
    }
}

void suceso(Game& g, Events& e){                                /// Random Event Selector

    int dado = 1+rand()%85;

    if (g.round==1){
        g.event = 0;
        g.round++;
    } else if (g.round%3==0){   // First Event and Each 3 events will be a combat
        g.event = 0;
        g.round++;
    } else {                    // Chooses a new event which hasn't happened yet
        switch(dado){
            case 1 ... 20: if(!e[0]){g.event = 20; e[0] = true;} else{suceso(g, e);};  break;
            case 21 ... 30: if(!e[1]){g.event = 30; e[1] = true;} else {suceso(g, e);}; break;
            case 31 ... 40: if(!e[2]){g.event = 40; e[2] = true;} else{suceso(g, e);};break;
            case 41 ... 59: if(!e[3]){g.event = 50; e[3] = true;} else{suceso(g, e);};break;
            case 60: g.event = 60; g.round = 9; break;
            case 61 ... 68: if(!e[4]){g.event = 65; e[4] = true;} else{suceso(g, e);};break;
            case 69: if(!e[5]){g.event = 69; e[5] = true;} else{suceso(g, e);};break;
            case 70 ... 78: if(!e[6]){g.event = 72; e[6] = true;} else{suceso(g, e);};break;
            case 79 ... 85: if(!e[7]){g.event = 80; e[7] = true;} else{suceso(g, e);};break;
            case 86 ... 99: if(!e[8]){g.event = 90; e[8] = true;} else{suceso(g, e);};break;
            case 100: if(!e[9]){g.event = 100; e[9] = true;} else{suceso(g, e);};break;
            case 101 ... 115: if(!e[10]){g.event = 110; e[10] = true;} else{suceso(g, e);};break;
        }
    }
}

void gameRound(Player& p, Monster& m, Game& g){                 /// Starts Event after Random Selection

    switch(g.event){
        case 0:  battle(p, m, g); break;
        case 20: paths(p, g); break;        // Ice Shield
        case 30: hauntedHouse(p, g); break; // Pink and Golden Box
        case 40: wanderer(p, g); break;     // Magical Ring
        case 50: chest(p, g); break;        // Chest
        case 60: battle(p, m, g); break;    // Early Boss Battle
        case 65: dog(p, g); break;          // Dog Companion
        case 69: stripclub(p, g); break;    // Lube
        case 72: granny(p, g); break;       // Food
        case 80: trader(p, g); break;       // Pink and Golden Key
        case 90: nymph(p, g); break;        // Healing Boost
        /*case 100: vampire(p, g); break;     /// Life Steal
        case 110: curse(p, g); break;       /// Curse*/
    }
}

int main(){

    srand(time(NULL));  // Generates seed for random numbers

	/// Game Variables Declaration

    Player p;
    Monster m;
    Game g;
    Events e = {{false}};

	/// Game Starts

    intro(g);
    startGameVars(p, m, g);
	checkStep(g);

    while(!g.endGame){

        suceso(g, e);
        if(g.event!=0 && g.event!=60) g.round++;
        else {
            if(g.event==60){
                g.win = true;
                updateGame(p, m, g);
                sevent(60);
            }

            displayEncounter(p, m, g);
        }

        while(((m.health>0)&&(p.health>0))&&(!g.terminal)) gameRound(p, m, g);;

        if(g.win){
            if(m.name == 'D'){
                newRound(g, m);
                checkStep(g);
                if (p.health>50) p.health = 50;
            } else {
                newRound(g, m);
                checkStep(g);
                updateGame(p, m, g);
            }
        } else if (!g.win) replay(p, m, g, e);
    }

    return 0;
}
