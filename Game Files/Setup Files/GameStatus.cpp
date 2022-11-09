#include "GameStatus.h"

GameStatus::GameStatus(){

    round = 1;
    evnt = null;
    playEvSize = numEvents;
    endGame = false;

    for(int i = 1; i<=playEvSize; i++)
        playEv[i] = i;
    
};

Events GameStatus::chooseEvent(){

    int num = 1+rand()%playEvSize;

    evnt = playEv[num];
    realloc_events(num);
    
    return evnt;
};

void GameStatus::realloc_events(int pos){
    
    for(int i = pos; i<playEvSize; i++)
        playEv[i] = playEv[i+1];
    
    playEv[playEvSize] = null;
    playEvSize--;
};