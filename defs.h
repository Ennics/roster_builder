#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C_OK       0
#define C_NOK     -1

#define MAX_STR   32
#define MAX_CAP  128

typedef enum { C_HOCKEY, C_BASKETBALL, C_OTHER } SportType;

typedef struct {
  int         id;
  SportType   sport;
  char        name[MAX_STR];
  char        gender[MAX_STR];
  int         age;
} PlayerType;

typedef struct {
  PlayerType *elements;
  int capacity;
  int size;
} PlayerArrayType;


void printMenu(int*);
void loadPlayerData(PlayerArrayType*);

void initPlayerArray(PlayerArrayType*, int);
void initPlayer(int, SportType, char*, char*, int, PlayerType*);

void addPlayer(PlayerArrayType*, PlayerType*);
int  delPlayer(PlayerArrayType*, int);
void copyPlayer(PlayerType*, PlayerType*);
int  validateSport(int, SportType*);
void convertSport(SportType, char*);

void printPlayers(PlayerArrayType*);
void printPlayersBySport(PlayerArrayType*, SportType);
void cleanupPlayerArray(PlayerArrayType*);

