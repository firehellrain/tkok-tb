#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <array>
#include "ConsoleColor.h"
#include "DiceRolls.h"

using namespace std;

/// Text Functions

void cevent(int a, Player& p, Monster& m, Game& g){                 /// Combat Event Carried Out
    switch(a){
        case 1: cout << "You dealt " << p.damage << " dmg and left the monster with " << m.health << " HP, killing it!" << endl; break;
        case 2: if(!p.dog) cout << "You dealt " << p.damage << " dmg and left the monster with " << m.health << " HP!" << endl;
                else cout << "You dealt " << p.damage << " dmg and left the monster with " << m.health+p.dogAttack << " HP!" << endl; break;
        case 3: cout << "The monster attacked you, dealing "<<m.damage<<" damage and leaving you with " << p.health << " HP, killing you!" << endl; break;
        case 4: cout << "The monster threw a "<<red<<"fireball"<<white<<" spell, dealing "<<m.damage<<" damage and leaving you with " << p.health << " HP!" << endl; break;
        case 5: cout << "The monster attacked you, dealing "<<m.damage<<" damage and leaving you with " << p.health << " HP!" << endl; break;
        case 6: cout << "The monster stole "<<(m.damage/2)<<" HP from you!"<<endl; break;
        case 7: cout << "You used a "<<red<<"fireball"<<white<<" spell, dealing " << p.damage << " dmg and leaving the monster with " << m.health << " HP, killing it!" << endl; break;
        case 8: if(!p.dog) cout << "You used a "<<red<<"fireball"<<white<<" spell, dealing " << p.damage << " dmg and leaving the monster with " << m.health << " HP!" << endl;
                else cout << "You used a "<<red<<"fireball"<<white<<" spell, dealing " << p.damage << " dmg and leaving the monster with " << m.health+p.dogAttack << " HP!" << endl; break;
        case 9: cout << "You "<<green<<"healed"<<white<<" yourself for "<< p.damage << " HP!" << endl; break;
        case 10:cout << red <<"You heal spell failed! You didn't recover any health." << white << endl; break;
        case 11:cout << red <<"Your fireball spell failed! You didn't deal any damage." << white << endl; break;
        case 12:cout << yellow << "Monster HP: " << white << m.health << endl;
                cout << green << "Your HP: " << white << p.health << endl; break;
        case 13:cout << "(A)ttack/(H)eal: "; break;
        case 14:cout << "(A)ttack/(H)eal/(S)pell: "; break;
        case 15:cout << "The monster threw a "<<red<<"fireball"<<white<<" spell, but you blocked it with your " << blue << "Frost Shield!" << white << endl; break;
        case 16:cout << "The dog attacked the monster for " << p.dogAttack << " damage and left the monster with " << m.health << " HP, killing it!"<<endl; break;
        case 17:cout << "The dog attacked the monster for " << p.dogAttack << " damage and left the monster with " << m.health << " HP!"<<endl; break;
        case 18:cout << "You used an "<<blue<<"ice scorch"<<white<<" spell, dealing " << p.damage << " dmg and leaving the monster with " << m.health << " HP, killing it!" << endl; break;
        case 19:if(!p.dog) cout << "You used an "<<blue<<"ice scorch"<<white<<" spell, dealing " << p.damage << " dmg and leaving the monster with " << m.health << " HP!" << endl;
                else cout << "You used an "<<blue<<"ice scorch"<<white<<" spell, dealing " << p.damage << " dmg and leaving the monster with " << m.health+p.dogAttack << " HP!" << endl; break;
        case 20:cout << red <<"Your ice scorch spell failed! You didn't deal any damage." << white << endl; break;
    }
}


void monsterType(char f){                                           /// Monster Name

	switch(f){
        case 'A': cout<<yellow<<"Army of Bloodthirsty Bats"<<white; break;
        case 'B': cout<<yellow<<"Guardian of the Vampires"<<white; break;
        case 'C': cout<<yellow<<"Hecuba, Mistress of the Vampires"<<white; break;
        case 'D': cout<<red<<"Drakar, Lord of the Vampires"<<white; break;
        case 'E': cout<<blue<<"Undead Shapeshifter"<<white; break;
	}
}

void displayEncounter(Player& p, Monster& m, Game& g){              /// Combat Initialization

    cout << "A random ";
    monsterType(m.name);
    cout << " has appeared!" << endl;
    cout << "Monster HP: " << m.health << endl;
    cout << "Your HP: " << p.health << endl;
    cout << "What do you want to do?" << endl;

    if(p.spells) cout << "(A)ttack/(H)eal/(S)pells: ";
    else cout << "(A)ttack/(H)eal: ";
}

void monsterEncounter(Player& p, Monster& m, Game& g){              /// Monster Turn Carried Out

    bool attack;

    if (p.health <=0 ){
        g.win = false;
		cevent(3, p, m, g);
		cout << " " << endl;
    } else if((m.fireball==true && m.damage>0)&& m.health>0){
		cevent(4, p, m, g);
		cout << " " << endl;
		attack = true;
    } else if(m.damage==0 && m.health>0){
		cevent(15, p, m, g);
		attack = true;
    }

    if((m.name=='C' || m.name=='D') && ((!m.fireball && p.health>0)&& m.health>0)){
        cevent(5, p, m, g);
        cevent(6, p, m, g);
        cout << " " << endl;
        cevent(12, p, m, g);
    } else if(m.health>0 && p.health>0){
        if(!attack){
            cevent(5, p, m, g);
            cout << " " << endl;
        }
        cevent(12, p, m, g);
    }
    if((m.health>0 && p.health>0)&& p.spells) cevent(14, p, m, g);
    else if(m.health>0 && p.health>0) cevent(13, p, m, g);
}

void attackEncounter(Player& p, Monster& m, Game& g){               /// Attack Turn Carried Out

        if(m.health + p.dogAttack <= 0){
            g.win = true;
            cout << " " << endl;
            cevent(1, p, m, g);
            cout << " " << endl;
        } else if(m.health <= 0 && p.dog){
            g.win = true;
            cout << " " <<endl;

            cevent(16, p, m, g);
            cout << " " <<endl;
        } else if (p.dog){
            cout << " " << endl;
            cevent(2, p, m, g);
            cevent(17, p, m , g);
        } else {
            cout << " " <<endl;
            cevent(2, p, m, g);
        }

       monsterEncounter(p, m, g);
}

void fireEncounter(Player& p, Monster& m, Game& g){                 /// Fireball Turn Carried Out

        if(m.health + p.dogAttack <= 0){
            g.win = true;
            cout << " " << endl;
            cevent(7, p, m, g);
            cout << " " << endl;
        } else if (p.damage == 0 && m.health <= 0 && p.dog){
            cout << " " << endl;
            cevent(11, p, m, g);
            cevent(16, p, m, g);
            cout << " " <<endl;
		} else if (p.dog && p.damage == 0){
		    cout << " " << endl;
		    cevent(11, p, m, g);
		    cevent(17, p, m, g);
		} else if (p.dog){
            cout << " " << endl;
            cevent(8, p, m, g);
            cevent(17, p, m, g);
        } else if (p.damage == 0) {
            cout << " " << endl;
            cevent(11, p, m, g);
        } else {
            cout << " " << endl;
            cevent(8, p, m, g);
        }

        monsterEncounter(p, m, g);
}

void healEncounter(Player& p, Monster& m, Game& g){                 /// Heal Turn Carried Out

        if(p.damage != 0){
            cout << " " << endl;
            cevent(9, p, m, g);
        } else {
            cout << " " << endl;
            cevent(10, p, m, g);
        }

        if(m.health <= 0 && p.dog){
            cevent(16, p, m, g);
            cout << " " << endl;
        } else if (p.dog) cevent(17, p, m, g);

        monsterEncounter(p, m, g);

}

void iceScorchEncounter(Player& p, Monster& m, Game& g){            /// Ice Scorch Turn Carried Out

        if(m.health + p.dogAttack <= 0){
            g.win = true;
            cout << " " << endl;
            cevent(18, p, m, g);
            cout << " " << endl;
        } else if (p.damage == 0 && m.health<=0 && p.dog){
            cout << " " << endl;
            cevent(20, p, m, g);
            cevent(16, p, m, g);
            cout << " " <<endl;
		} else if (p.dog && p.damage == 0){
		    cout << " " << endl;
		    cevent(20, p, m, g);
		    cevent(17, p, m, g);
		} else if (p.dog){
            cout << " " << endl;
            cevent(19, p, m, g);
            cevent(17, p, m, g);
        } else if (p.damage == 0) {
            cout << " " << endl;
            cevent(20, p, m, g);
        } else {
            cout << " " << endl;
            cevent(19, p, m, g);
        }

        monsterEncounter(p, m, g);
}

/// Game Functions

void spellChoice(Player& p, Game& g){                               /// Spell Choice Interface

    cout<<"\nWhich spell do you want to use? -";

    if(p.fireball) cout<<" (F)ireball";
    if(p.icescorch) cout<<" (I)ce Scorch";

    cout<<": ";

    while((g.choice!='f' && g.choice!='F')&&(g.choice!='i' && g.choice!='I')) cin>>g.choice;

    if(g.choice == 'f' || g.choice == 'F'){
        if(p.fireballs>0) g.choice = 'f';
        else {
            cout<<"\nYou don't have any fireball spells left. You do an attack instead.";
            g.choice = 'a';
        }
    } else g.choice = 'i';
}

void checkChoice(Game& g, Player& p){                               /// Checks Player Combat Choice

    if(g.choice=='a' || g.choice=='A') g.choice = 'a';
    else if (g.choice=='s' || g.choice=='S') spellChoice(p, g);
    else if (g.choice=='h' || g.choice=='H'){
        if(p.heals>0) g.choice = 'h';
        else if(p.medicine){
            g.choice = 'h';
            cout<<"\nYou don't have any healing spells left, but you use your "<<green<<"Medical Herbs"<<white<<" instead";
            p.medicine = false;
        } else {
            cout<<"\nYou don't have any healing spells left. You do an attack instead.";
            g.choice = 'a';
        }
    }
}

void getAction(Game& g, Player& p){                                 /// Player Combat Choice Input

    if(!p.spells) do cin>>g.choice; while((g.choice!='a' && g.choice!='A')&&(g.choice!='h' && g.choice!='H'));
    else do cin>>g.choice; while(((g.choice!='a' && g.choice!='A')&&(g.choice!='s' && g.choice!='S'))&&(g.choice!='h' && g.choice!='H'));

}

void doStep(Player& p, Monster& m, Game& g){                        /// Player Choice Action

    if (g.choice=='h'){
        p.damage = hG(p);
        p.health += p.damage;
    } else {
        if(g.choice=='a') p.damage = aG(p);
        else if (g.choice=='f') p.damage = fG(p);
        else p.damage = iG(p);
        m.health -= p.damage;
    }

    if (p.health>50) p.health = 50;
    else if (p.health<0) p.health = 0;
    else if (m.health<0) m.health = 0;
    else if (m.health>60) m.health = 60;
}

void mStep(Player& p, Monster& m){                                  /// Monster Action

    m.damage = mG(m, p);
    p.health -= m.damage;

    if((m.name=='C' || m.name=='D') && !m.fireball) m.health += (m.damage/2);

    if (p.health<0) p.health = 0;
    else if (m.health>60) m.health = 60;

}

void encounter(Player& p, Monster& m, Game& g){                     /// Choice Encounter Output

    switch(g.choice){
        case 'a': attackEncounter(p, m, g); break;
        case 'f': fireEncounter(p, m, g); break;
        case 'h': healEncounter(p, m, g); break;
        case 'i': iceScorchEncounter(p, m, g); break;
    }
}

void battle(Player& p, Monster& m, Game& g){                        /// Combat Loop

    while(m.health>0 && p.health>0){
        if(p.health>0){
            getAction(g, p);
            checkChoice(g, p);
            doStep(p, m, g);
        }

        if(p.dog && p.health>0){
            p.dogAttack = dG(p);
            m.health -= p.dogAttack;
        }

        if(m.health>0) mStep(p, m);
        encounter(p, m, g);

        if(p.health <= 0 && p.revive){
            p.health = 1+rand()%20+rand()%20;
            cout<<"\nThe blessed coin that you obtained from the box starts shining as it seems to "<<green<<"revive you"<<white<<", "
            <<"\nleaving you with "<<p.health<<" HP. It seems to banish after healing you."<<endl;
            p.revive = false;
        }
    }
}
