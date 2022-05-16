#include "GameStatus.h"

GameStatus::GameStatus(){

    int round = 1;
    Events event = null;
    int playEvSize = numEvents;
    bool endGame = false;

    for(int i = 1; i<=playEvSize; i++){
        playEv[i] = i;
    }
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