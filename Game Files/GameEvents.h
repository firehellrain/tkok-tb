#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <array>
#include "ConsoleColor.h"

using namespace std;

struct Player {

    int health; //x
    int heals; //x
    int damage; //x
    int fireballs; //x
    int dogAttack; //x
    bool spells; //x
    bool hbonus;

    bool revive;
    bool cursed;
    bool vampire;
    bool healboost;
    bool dog;

    bool shield;
    bool sword;
    bool ring;
    bool food;
    bool lube;
    bool medicine;
    bool box;
    bool key;

    bool fireball;
    bool icescorch;
};

struct Monster {
    int health;
    int damage;
    char name;
    bool fireball;
};

struct Game {
    int round;
    int event;
    bool win;
    char step;
    char choice;
    bool endGame;
    bool terminal;
};

void sevent(int a){

    switch(a){
        case 21:cout<<"\nYou decide to walk through the "<<yellow<<"caves."<<white; break;
        case 22:cout<<"\nSome "<<yellow<<"bats"<<red<<" attacked"<<white<<" you while you were crossing the dark and humid cave. \nYou try to fight them back but you have to run away from them as they are too many."<<endl; break;
        case 23:cout<<"\nYou move slowly through the dark cave. You hear some bats flying around the roof, but you move stealthy\nand they don't get alerted by your pressence. You reach the exit of the cave."<<endl; break;
        case 24:cout<<"\nYou decide to cross the "<<blue<<"frozen mountain"<<white<<". You nearly die due to the low temperatures, \nbut you find a small cave where you can rest."<<endl;
                cout<<"Inside the cave you find a little tent and a "<<blue<<"frozen shield"<<white<<" by the side of it. Do you want to take it? (Y/N): "; break;
        case 25:cout<<"\nYou pick up the shield and rest on the tent. Once you wake up and recover from the hypothermia,\nyou leave the cave and walk through the mountain until you finally reach the other side."<<endl; break;
        case 26:cout<<"\nYou leave the shield where you found it and rest on the tent. Once you wake up and recover from the hypothermia, \nyou leave the cave and walk through the mountain until you finally reach the other side."<<endl; break;
        case 27:cout<<"You caught a severe fever and fell unconscious. Due to the low temperatures of the night and the illness, you"<<red<<" die"<<white<<" some minutes later in the middle of the roads."<<endl; break;
        case 28:cout<<"\nYou decide to cross the "<<blue<<"frozen mountain"<<white<<". As you were not prepared for the low temperatures, \nyou faint due to the hypothermia and "<<red<<"die"<<white<<" as your body gets buried down by the snow."<<endl; break;

        case 30:cout<<"\nYou decide to walk past the house and continue your path." << endl; break;
        case 31:cout<<"\nYou bust the front door open and get inside the house. It has been unused for a long period of time. \nYou can see spider webs everywhere, there isn't much light coming in through the windows."<<endl;
            cout<<"\nYou go upstairs and check all the rooms. In the main bedroom you find a pink and golden box hidden under the nightstand. \nIt seems to be locked with a key. Do you take it with you? (Y/N): ";
            break;
        case 32:cout<<"\nYou take the box with you and leave the haunted house. You can hear some wood cracking while you're going through\nthe hallways, like if someone was slowly stepping behind you."<<endl; break;
        case 33:cout<<"\nYou leave the box where you found it and keep searching. You didn't find anything interesting, so you decide to leave the house and continue your path."<<endl; break;
        case 34:cout<<"\nYou take the box with you and leave the haunted house. When you are walking through the hallways, \na "<<red<<"vampire"<<white<<" jumps from the darkness and attacks you. You "<<green<<"manage to kill him"<<white<<" and you run away from the house to never come back again."<<endl; break;
        case 35:cout<<"\nYou take the box with you and leave the haunted house. When you are walking through the hallways, \na "<<red<<"vampire"<<white<<" jumps from the darkness and attacks you. You didn't have time to react as he "<<red<<"bites your neck"<<white<<" and sucks the blood out of your veins, \nleaving your deceived body inside the house."<<endl; break;

        case 41:cout<<"\nYou decide to "<<red<<"ignore"<<white<<" the "<<yellow<<"old man"<<white<<" and continue your way. You can hear him screaming while he's being eaten alive by the wolves."<<endl; break;
        case 42:cout<<"\nYou decide to stay with the old man. The wolves try to attack you and the old man but you "<<green<<"achieve"<<white<<" to kill them all.\nYou got injured in the process."<<endl; break;
        case 43:cout<<"\nYou decice to stay with the old man. The wolves come to attack you and you can't hold them as they "<<red<<"eat you alive"<<white<<".\nYou "<<red<<"die"<<white<<" seconds later after you've lost too much blood."<<endl; break;
        case 44:cout<<"\nYou decide to stay with the old man. You treat his wounds and guard him until the wolves leave the area."<<endl; break;
        case 45:cout<<"The old man seems very grateful. 'Thank you, young hero. I wouldn't be alive now if it wasn't for your bravery.\nTake this ring as a reward, it was enchanted by a powerful mage.'\nThe old man hands you the ring and continues his way."<<endl; break;
        case 46:cout<<"\nYou decide to stay with the old man. The wolves attack you and the old man. You achieve to kill the wolves, but the "<<yellow<<"old man"<<red<<" dies"<<white<<" in the process. You leave the corpse in the road and continue your path."<<endl; break;

        case 51:cout<<"You opened the chest and found inside a "<<yellow<<"Golden Sword"<<white<<".\nYou take it with you and swing it in the air while you get used to it."<<endl; break;
        case 52:cout<<"The chest was a mimic, and you woke him up. You didn't have time to react before the mimic "<<red<<"ate you alive"<<white<<"."<<endl; break;
        case 53:cout<<"You found a healing spell inside the chest which "<<green<<"healed"<<white<<" you for 15 HP!"<<endl; break;

        case 60:cout<<"Darkness starts surrounding you as your lungs feel heavier. Your arms and legs lose strength as you see a shadow \nfly before you. When the shadow becomes a person, you can't believe what your eyes are seeing..."<<endl; break;

        case 65:cout<<"\nWhen you try to get near the "<<yellow<<"dog"<<white<<", he barks at you before running away, scared from your presence. \nYou see him hide beneath a house to never see him again in your life. You leave the village while thinking \nabout the poor dog."<<endl; break;
        case 66:cout<<"\nWhen you try to get near the "<<red<<"dog"<<white<<", he barks angrily before jumping at you, dropping you to the floor. \nDefenseless, all you can do is scream as the dog "<<red<<"eats you alive"<<white<<"."<<endl; break;
        case 67:cout<<"\nWhen you try to get near the "<<red<<"dog"<<white<<", he barks angrily before jumping at you, dropping you to the floor. \nYou "<<green<<"manage to kill"<<white<<" the dog before he eats you alive, but you get bit in the process. You leave the body aside \nand run away from the cursed village."<<endl; break;
        case 68:cout<<"As you get near the "<<yellow<<"dog"<<white<<", he seems a little nervous, but remains still. He sniffs you from a distance, like he was \ndetecting something you have with you. You remember that you had found a "<<green<<"food can"<<white<<" before, which remains unused..."<<endl; break;
        case 69:cout<<"\nYou decide to open the can and you give the "<<green<<"dog"<<white<<" your food. He seems very happy, eating all of it in a second. \nHe later starts barking at you in a friendly way as he decides to follow you on your path."<<endl; break;
        case 70:cout<<"\nYou decide to open the can and you give the "<<yellow<<"dog"<<white<<" your food. He seems very happy, eating all of it in a second. \nAfter that, he runs away from you and hides beneath a house to never see him again in your life. You leave the village with the knowledge you had saved that dog's life for another day..."<<endl; break;

        case 691:cout<<"When you get inside the building you find yourself in a very weird "<<red<<"strip-club full of vampires and misstresses."<<white<<" \nFor your own safety, you try to remain unnoticed as you walk inside. You go to the bar and a female bartender offers you a drink as she says 'This one's on me'"<<endl;break;
        case 692:cout<<"\nYou reject to drink the liquid that the bartender offers you. Trying to search for the exit, "<<red<<"two misstresses"<<white<<" \nblock you as they ask you 'Do you want to come with us, sweetheart?' while they keep getting closer to you."<<endl;break;
        case 693:cout<<"\nAfter some hours you wake up in a bed with three naked misstresses. You seem not to remember what happened, but you \ntry to leave as silently as you can from the room without them noticing. You try not to look back as you take the road where you came from."<<endl;break;
        case 694:cout<<"\nAlthough they seem very disappointed, they end up "<<green<<"leaving you"<<white<<" as they walk away, searching for \nanother prey. You get to the exit and take the road where you came from."<<endl;break;

        case 71:cout<<"\nYou get closer to the house and knock on the door. An "<<yellow<<"old woman"<<white<<" recieves you with a weird smile. 'Hello, young hero. Come in, come in...'\nYou enter inside the house, which seems very comfy and warm. 'What has brought you here? Where are you going?'"<<endl; break;
        case 72:cout<<"\nThe woman seems to ignore everything you've said. 'I see, I see... I have prepared lunch some minutes ago. Do you want to have some of the food I've prepared?'"<<endl; break;
        case 73:cout<<"\nThe "<<yellow<<"old woman"<<white<<" starts laughting as she grows in size. Some dark wings start growing on her back,\n as the house catches on"<<red<<" fire."<<white<<endl; break;
        case 74:cout<<"\nShe tries to attack you but you "<<green<<"achieved"<<white<<" to kill her, although you took some damage in the process. \nYou decide to leave the house, which is now burning at a very fast rate."<<endl;break;
        case 75:cout<<"\nShe jumps right at you and you scream as she starts "<<red<<"reaping"<<white<<" your chest appart and eating your internal organs,\n"<<red<<"killing you "<<white<<"in the process."<<endl;break;
        case 76:cout<<"\nYou decide to keep the food to eat it later. The granny invites you to leave the house, and you walk past it as she stares at you from the window."<<endl;break;
        case 77:cout<<"\nYou decide to eat the food. It is very tasty indeed. The granny invites you to leave the house, \nand you walk past it as she stares at you from the window."<<endl;break;
        case 78:cout<<"\nYou decide to reject the food, which seems to make the granny very angry. You then leave the house while she is screaming at you."<<endl;break;

        case 81:cout<<"\nYou "<<red<<"reject the offer"<<white<<" from the merchant and decide to continue walking. He seems a bit dissapointed but he doesn't stop you,\npicking up his things again and walking away."<<endl;break;
        case 82:cout<<"\nThe merchant shows a warm smile as he jumps off his horse. As he's opening one of the many pouches that the saddle has, he says:\n'Perhaps you are interested on this "<<yellow<<"exotic key"<<white<<"... It must belong to a box, although I'm not really sure for which one it is.'"<<endl;break;
        case 83:cout<<"\nThe merchant looks at you, almost "<<red<<"offended"<<white<<" by the perk that you show him: 'Are you kidding me? Trying to scam me?'\nYou decide to leave him alone before he gets any angrier, and continue your way through the path you were following."<<endl;break;
        case 84:cout<<"\nThe merchant seems to be "<<green<<"very interested"<<white<<" in the perk that you show him: \n'That's an impressive piece that you have. I definitely want to trade it for the key.' He accepts the item that you give him and trade it for the key.\n'Have a good day sir', he says as he climbs to his horse and gallops away from you after the trade."<<endl;break;
        case 85:cout<<"\nYou show all of your perks to the merchant but he seems "<<red<<"not to like"<<white<<" any of them. \n'I'm sorry, but I won't take any of that garbage as a trade. Have a nice day sir.' He climbs to his horse again and gallops away from you."<<endl;break;

        case 91:cout<<"\nYou decide to cross the woods and start walking around the bushes. After walking for some minutes you end up finding a \n"<<blue<<"waterfall with a lake beneath it."<<white<<" In the shore, there is a small "<<blue<<"water nymph"<<white<<" which is looking at you."<<endl;break;
        case 92:cout<<"\n"<<endl;break;
        case 93:cout<<"\n"<<endl;break;
        case 94:cout<<"\n"<<endl;break;
        case 95:cout<<"\n"<<endl;break;
        case 96:cout<<"\n"<<endl;break;
    }

}

/// Game Events

// Nymph Event

void nymphHeal(Player& p, Game& g){

    string answer;

    if(g.choice == 'Y' || g.choice == 'y') {
        sevent(93);

        cout<<"Write your answer on lower case: ";
        cin>>answer;

        if(answer=="water"){

            sevent(96);
            p.healboost = true;

            cout<<"Spell Obtained: "<<green<<"Heal Boost"<<white<<endl;

        } else sevent(95);
    } else sevent(94);
}

void nymphNext(Player& p, Game& g){

    if(g.choice == 'Y' || g.choice == 'y'){

        sevent(91);

        do{
            cout<<"Do you want to listen to the riddle? (Y/N): ";
            cin>>g.choice;
        }while((g.choice!='Y' && g.choice!='N')&&(g.choice!='y' && g.choice!='n'));

        nymphHeal(p, g);
    } else sevent(92);

    g.terminal = true;
}

void nymph(Player& p, Game& g){

    cout<<"You hear the sound of a "<<blue<<"waterfall"<<white<<" coming from a near "<<green<<"forest"<<white<<", which seems to be calling you with it's mystic sound. "
    <<"\nThe tall trees stand in front of you as you watch some creatures cross the leafy woods."<<endl;

    do{
        cout<<"Do you want to cross the woods? (Y/N): ";
        cin>>g.choice;
    }while((g.choice!='Y' && g.choice!='N')&&(g.choice!='y' && g.choice!='n'));

    nymphNext(p, g);
}

// Antique Shop Event

void openBox(Player& p, Game& g){

    int dado = 1+rand()%20;
    string content;

    cout<<"You check if the key that you obtained fits on the lock of the Pink and Golden Box, and you decide to open it";
    for(int i = 0; i<3; i++){
        cout<<".";
        Sleep(1500);
    }

    switch(dado){
        case 1 ... 10: p.medicine = true; content = "Medical Herb"; break;
        case 11 ... 16: p.icescorch = true; p.spells = true; content = "Ice Scorch Spell Scroll"; break;
        case 17 ... 20: p.revive = true; content = "Blessed Coin"; break;
    }

    cout<<"\nInside the box you find a "<<yellow<<content<<white<<", and you store it inside your backpack."<<endl;
}

void traderBargain(Player& p, Game& g){

    int dado = 1+rand()%20;

    cout<<"What do you want to bargain with? - ";
    if(p.ring) cout<<" (R)ing";
    if(p.shield) cout<<" S(h)ield";
    if(p.sword) cout<<" S(w)ord";
    cout<<" (C)ancel";

    do{
        cin>>g.choice;
    }while(((g.choice!='R')&&(g.choice!='r'))&&((g.choice!='H')&&(g.choice!='h'))&&((g.choice!='W'&&g.choice!='w')||(g.choice!='C'||g.choice!='c')));

    if(g.choice!='R'&&g.choice!='r'){

        switch(dado){
            case 1 ... 8: sevent(83); break;                                                                                                            // Failure
            case 9 ... 20: sevent(84); p.ring = false; p.key = true; cout<<"Item Obtained: "<<yellow<<"Gold and Pink Key"<<white<<endl; break;          // Success
        }

    } else if(g.choice!='H'&&g.choice!='h'){

        switch(dado){
            case 1 ... 12: sevent(83); break;                                                                                                           // Failure
            case 13 ... 20: sevent(84); p.shield = false; p.key = true; cout<<"Item Obtained: "<<yellow<<"Gold and Pink Key"<<white<<endl;break;        // Success
        }

    } else if(g.choice!='W'&&g.choice!='w'){

        switch(dado){
            case 1 ... 10: sevent(83); break;                                                                                                           // Failure
            case 11 ... 20: sevent(84); p.sword = false; p.key = true; cout<<"Item Obtained: "<<yellow<<"Gold and Pink Key"<<white<<endl;break;         // Success
        }
    } else sevent(81);

}

void traderShow(Player& p, Game& g){

    if(g.choice=='Y' || g.choice=='y'){

        sevent(82);

        do{
            cout<<"Do you want to bargain for it? (Y/N):";
            cin>>g.choice;
        }while(((g.choice!='Y')&&(g.choice!='N'))&&((g.choice!='y')&&(g.choice!='n')));

        if((g.choice=='Y'||g.choice=='y')&&((p.ring||p.shield)||p.sword)) traderBargain(p, g);
        else if (g.choice=='Y'||g.choice=='y') sevent(85);
        else sevent(81);

    } else sevent(81);

    g.terminal = true;
}

void trader(Player& p, Game& g){

    cout<<"Walking through the plains of Kyura you come across a mid-aged man who is riding a carriage. He talks to you as he starts braking his ride: \n'Hello young man, will thou be interested in any of my goods?'"<<endl;

    do{
        cout<<"Do you want to check his perks? (Y/N): ";
        cin>>g.choice;
    }while(((g.choice!='Y')&&(g.choice!='N'))&&((g.choice!='y')&&(g.choice!='n')));

    traderShow(p, g);

}

// Granny Event

void grannyFood(Player& p, Game& g){

    int dado = 1+rand()%20;

    if(g.choice=='K' || g.choice=='k') p.food = true;

    if(dado<=5){
        sevent(73);
        p.health -= 10-dado;
        if(p.health > 0) sevent(74);
        else sevent(75);
    } else {
        if(p.food){
            sevent(76);
            cout<<"Item Obtained: "<<yellow<<"Food"<<white<<endl;
        } else if(g.choice=='E' || g.choice=='e') sevent(77);
        else sevent(78);
    }

    g.terminal = true;
}

void grannyHouse(Player& p, Game& g){

    char ignore;

    if(g.choice=='Y' || g.choice=='y'){

        sevent(71);
        cout<<"Answer to the Old Woman (end with a dot): ";
        while(ignore!='.') cin>>ignore;
        sevent(72);

        do{
            cout<<"Do you want to (e)at, (k)eep or (r)eject the food?: ";
            cin>>g.choice;
        }while(((g.choice!='E' && g.choice!='e')&&(g.choice!='K' && g.choice!='k')) && (g.choice!='R' && g.choice!='r'));

        grannyFood(p, g);

    } else {
        cout<<"You decide to ignore the weird house you've just walked by. The person on the window keeps staring at you, \neven after you have stopped looking at the house."<<endl;
        g.terminal = true;
    }

}

void granny(Player& p, Game& g){

    cout<<"In a gentle hill you can see a little house. It has a chimney that is throwing smoke outside, \nas if a fire was being casted inside of the house. a "<<yellow<<"weird figure"<<white<<" stares at you from the window of the house."<<endl;

    do{
        cout<<"Do you want to check the house? (Y/N): ";
        cin>>g.choice;
    }while(((g.choice!='Y')&&(g.choice!='N'))&&((g.choice!='y')&&(g.choice!='n')));

    grannyHouse(p, g);

}

// Strip-club Event

void stripDrink(Player& p, Game& g){

    bool consent = true;

    if(g.choice=='N' || g.choice=='n'){
        sevent(692);
        do{
            cout<<"Do you want to go with them? (Y/N): ";
            cin>>g.choice;
        }while((g.choice!='Y' && g.choice!='N')&&(g.choice!='y' && g.choice!='n'));

        if(g.choice=='N' || g.choice=='n'){
            consent = false;
            sevent(694);
        }
    } else {
        cout<<"\nYour vision starts "<<yellow<<"blurring"<<white<<" as you feel very dizzy. You shouldn't have drinked that";
        for(int i = 0; i<3; i++){
            cout<<".";
            Sleep(1500);
        }
    }

    if(consent){
        sevent(693);
        p.lube = true;
        cout<<"Item Obtained: "<<green<<"Lube"<<white;
    }

    g.terminal = true;
}

void stripNext(Player& p, Game& g){

    if(g.choice=='Y' || g.choice=='y'){
        sevent(691);
        do{
            cout<<"Do you drink what she offers you? (Y/N): ";
            cin>>g.choice;
        }while((g.choice!='Y' && g.choice!='N')&&(g.choice!='y' && g.choice!='n'));
        stripDrink(p, g);
    } else {
        cout<<"You decide not to go inside the building and you walk past it while moving at the rhythm of the music."<<endl;
        g.terminal = true;
    }
}

void stripclub(Player& p, Game& g){

    cout<<"While crossing one of the many villages of Kyura you find a very "<<yellow<<"weird house"<<white<<", with lights coming from inside. "
    <<"\nThere seems to be some music playing behind the door."<<endl;

    do{
        cout<<"Do you want to go inside and have a look? (Y/N): ";
        cin>>g.choice;
    }while((g.choice!='Y' && g.choice!='N')&&(g.choice!='y' && g.choice!='n'));

    stripNext(p, g);

}

// Dog Event

void dEnd(Player& p, Game& g){

    int dado = 1+rand()%20;

    if(g.choice=='Y' || g.choice=='y'){
        if(dado>5){
            p.dog = true;
            p.food = false;
            sevent(69);
            cout<<"Buddy Obtained: "<<yellow<<"Dog"<<white<<endl;
        } else {
            p.food = false;
            sevent(70);
        }
    } else cout<<"You decide not to give him the food and you walk past him as he barks at you. You can hear him running on the distance, "
    <<"\nas his barks get "<<red<<"weirdly darker"<<white<<". That probably wasn't a normal dog, and you start running away from the cursed village you had entered."<<endl;

    g.terminal = true;

}

void dNext(Player& p, Game& g){

    int dado = 1+rand()%20;
    if(g.choice=='Y' || g.choice=='y'){
        if(p.food){
            sevent(68);
            do{
                cout<<"Do you want to give him your food? (Y/N): ";
                cin>>g.choice;
            }while((g.choice!='Y' && g.choice!='N')&&(g.choice!='y' && g.choice!='n'));
            dEnd(p, g);
        } else if (dado>5){
            sevent(65);
            g.terminal = true;
        } else if (dado>1){
            p.health -= (10-dado);;
            if(p.health>0){
                sevent(67);
                g.terminal = true;
            }
        } else {
            sevent(66);
            g.win = false;
            g.terminal = true;
        }
    } else {
        cout<<"You walk past the "<<yellow<<"dog"<<white<<" as he barks at you. You can hear him running on the distance, as his barks get "<<red<<"weirdly darker"<<white<<". "
        <<"\nThat probably wasn't a normal dog, and you start running away from the cursed village you had entered."<<endl;
        g.terminal = true;
    }

}

void dog(Player& p, Game& g){

    cout<<"Near an abandoned road, crossing through a lost village, you come across a "<<yellow<<"huge dog"<<white<<" who seems to be very hungry. "
    <<"\nHe stares at you, frightened but ready to attack if needed."<<endl;

    do{
        cout<<"Do you want to get close to him? (Y/N): ";
        cin>>g.choice;
    }while((g.choice!='Y' && g.choice!='N')&&(g.choice!='y' && g.choice!='n'));

    dNext(p, g);

}

// Chest Event

void coutcome(Player& p, Game& g){

    int random = 1+rand()%20;

    switch(random){
        case 1 ... 7: p.sword = true; sevent(51); cout<<"Item Obtained: "<<yellow<<"Golden Sword"<<white<<endl; break;
        case 8: g.win = false; sevent(52); break;
        case 9 ... 20: p.health += 15; if(p.health>50) p.health = 50; sevent(53); break;
    }

}

void chest(Player& p, Game& g){

    cout<<"After running away from a bunch of vampires you end up inside a "<<yellow<<"dungeon"<<white<<". "
    <<"\nIn one of the rooms you can see a "<<yellow<<"chest"<<white<<" which seems to be "<<red<<"breathing"<<white<<"..."<<endl;
    do{
        cout<<"Do you want to open it (Y/N): ";
        cin>>g.choice;
    }while((g.choice!='Y' && g.choice!='N')&&(g.choice!='y' && g.choice!='n'));

    if(g.choice=='Y' || g.choice=='y') coutcome(p, g);

    g.terminal = true;

}

// Ring Event

void wHelp(Player& p, Game& g){

    int lobos = 1+rand()%20;

    if(g.choice=='n' || g.choice=='N') sevent(41);
    else if(g.choice=='y' || g.choice=='Y'){
        if(lobos == 1){
            sevent(43);
            g.win = false;
        } else if (lobos == 2) sevent(46);
        else if (lobos<14){
            p.health -= (15-lobos);
             if(p.health<=0){
                sevent(43);
                g.win = false;
            } else {
                sevent(42);
                sevent(45);
                cout<<"Item Obtained: "<<yellow<<"Magical Ring"<<white<<endl;
                p.ring = true;
            }
        } else {
            sevent(44);
            sevent(45);
            cout<<"Item Obtained: "<<yellow<<"Magical Ring"<<white<<endl;
            p.ring = true;
        }
    }

    g.terminal = true;
}

void wanderer(Player& p, Game& g){

    cout<<"You find an "<<red<<"injured"<<yellow<<" old man"<<white<<" laying in the middle of your path. He looks at you, desperately. "<<endl;
    cout<<"'"<<yellow<<"Help me young hero! I am starving and I can't move due to my wounds!"<<white<<"'. \nYou can hear wolves howling in the distance, they are probably smelling his blood.";
    cout<<"\nDo you help the old man? (Y/N): ";
    do{
        cin>>g.choice;
    }while((g.choice!='Y' && g.choice!='N')&&(g.choice!='y' && g.choice!='n'));

    wHelp(p, g);
}

// Golden Box Event

void hHSB(Player& p, Game& g){

    int dado = 1+rand()%20;

    if(g.choice=='y' || g.choice=='Y'){
        p.box = true;

        if(dado<1){
            g.win = false;
            sevent(35);
        }else if(dado<5){
            p.health -= (10-dado);
            if(p.health<0){
                g.win = false;
                sevent(35);
            } else sevent(34);
        } else sevent(32);

        cout<<"Item obtained: "<<yellow<<"Locked Box"<<white<<endl;

    } else if (g.choice=='n' || g.choice=='N') sevent(33);

    if(p.box && p.key) openBox(p, g);

    g.terminal = true;
}

void hHS(Player& p, Game& g){

    if(g.choice=='n' || g.choice=='N'){
        sevent(30);
        g.terminal = true;
    } else if (g.choice=='y' || g.choice=='Y'){
        sevent(31);
        while((g.choice!='Y' && g.choice!='N')&&(g.choice!='y' && g.choice!='n')) cin>>g.choice;
        hHSB(p, g);
    }
}

void hauntedHouse(Player& p, Game& g){

    cout<<"Walking alone in the plains of "<<green<<"Kyura"<<white<<" you find an "<<yellow<<"abandoned house."<<white<<endl;
    do{
        cout<<"Do you want to look inside the house? (Y/N): ";
        cin>>g.choice;
    }while((g.choice!='Y' && g.choice!='N')&&(g.choice!='y' && g.choice!='n'));

    hHS(p, g);
}

// Ice Shield Event

void pathEnd(Player& p, Game& g){
    if(g.choice=='Y' || g.choice=='y'){
        sevent(25);
        p.shield = true;
        cout<<"Item Obtained: "<<blue<<"Frozen Shield"<<white<<endl;
    } else sevent(26);
}

void pathNext(Player& p, Game& g){

    int chance = 1+rand()%20;

    if(g.choice=='S' || g.choice=='s'){

        sevent(21);

        if(chance<=10){
            sevent(22);
            p.health -= (11-chance);
            if(p.health<=0){
                sevent(27);
                g.win = false;
            }
        } else sevent(23);

    } else if (g.choice=='M' || g.choice=='m'){

        if(chance<=5){
            sevent(28);
            g.win = false;
        } else {
            sevent(24);
            while((g.choice!='Y' && g.choice!='N')&&(g.choice!='y' && g.choice!='n')) cin>>g.choice;
            pathEnd(p, g);
        }
    }

    g.terminal = true;
}

void paths(Player& p, Game& g){

    cout<<"Walking through the lands of Kyura you find yourself in front of a huge mountain. \nYou'll have to cross it in order to reach the other side."<<endl;
    cout<<"\nThere are two ways you can take: There is a shortcut through a "<<yellow<<"cave"<<white<<" which leads to the other side,\nor you can cross the "<<blue<<"frozen and steep mountain."<<white<<endl;
    cout<<"Which way will you take? (S)hortcut/(M)ountain: ";

    while((g.choice!='S' && g.choice!='M')&&(g.choice!='s' && g.choice!='m')) cin>>g.choice;

    pathNext(p, g);

}

