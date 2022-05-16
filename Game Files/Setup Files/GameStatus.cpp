#include "GameStatus.h"

GameStatus::GameStatus(){

    round = 1;
    event = null;
    playEvSize = numEvents;
    endGame = false;

    for(int i = 1; i<=playEvSize; i++)
        playEv[i] = i;
    
};

Events GameStatus::chooseEvent(){

    int num = 1+rand()%playEvSize;

    event = playEv[num];
    realloc_events(num);
    
    return event;
};

void GameStatus::realloc_events(int pos){
    
    Events before, after, aux;

    for(int i = pos; i<playEvSize; i++)
        playEv[i] = playEv[i+1];
    
    playEv[playEvSize] = null;
    playEvSize--;
};