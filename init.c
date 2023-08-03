#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"

/*
  Function:  loadPlayerData
  Purpose:   loads an array of players
      out:   arr to have values assigned
*/
void loadPlayerData(PlayerArrayType *arr)
{
  PlayerType player;

  initPlayer(1008, C_HOCKEY, "Avery", "F", 612, &player);
  addPlayer(arr, &player);
  initPlayer(1001, C_BASKETBALL, "Liam", "M", 480, &player);
  addPlayer(arr, &player);
  initPlayer(1017, C_OTHER, "Harper", "F", 762, &player);
  addPlayer(arr, &player);
  initPlayer(1002, C_HOCKEY, "Jackson", "M", 598, &player);
  addPlayer(arr, &player);
  initPlayer(1032, C_BASKETBALL, "Olivia", "F", 826, &player);
  addPlayer(arr, &player);
  initPlayer(1004, C_OTHER, "Noah", "M", 715, &player);
  addPlayer(arr, &player);
  initPlayer(1013, C_HOCKEY, "Emma", "F", 344, &player);
  addPlayer(arr, &player);
  initPlayer(1018, C_BASKETBALL, "Lucas", "M", 688, &player);
  addPlayer(arr, &player);
  initPlayer(1029, C_OTHER, "Ava", "F", 500, &player);
  addPlayer(arr, &player);
  initPlayer(1007, C_HOCKEY, "Leon", "M", 796, &player);
  addPlayer(arr, &player);
  initPlayer(1027, C_BASKETBALL, "Sophia", "F", 579, &player);
  addPlayer(arr, &player);
  initPlayer(1016, C_OTHER, "Ethan", "M", 374, &player);
  addPlayer(arr, &player);
  initPlayer(1024, C_HOCKEY, "Mia", "F", 721, &player);
  addPlayer(arr, &player);
  initPlayer(1021, C_BASKETBALL, "Aiden", "F", 622, &player);
  addPlayer(arr, &player);
  initPlayer(1023, C_OTHER, "Isabella", "F", 405, &player);
  addPlayer(arr, &player);
}

/*
  Function:  initPlayerArray
  Purpose:   initialize all variables in arr to default values
      out:   arr to have values initializes
       in:   capacity variable to initialize the array
*/
void initPlayerArray(PlayerArrayType *arr, int cap) {
  arr->capacity = cap;
  arr->size = 0;
  arr->elements = calloc(cap, sizeof(PlayerType));
}

/*
  Function:  initPlayer
  Purpose:   initializes a specific player
       in:   id information used for initialization 
       in:   SportType information used for initialization 
       in:   name information used for initialization
       in:   gender information used for initialization 
       in:   age information used for initialization
      out:   PlayerType that is being initialized 
*/
void initPlayer(int i, SportType s, char *n, char *g, int a, PlayerType *player) {
  player->id = i;
  player->sport = s;
  strcpy(player->name, n);
  strcpy(player->gender, g);
  player->age = a;
}