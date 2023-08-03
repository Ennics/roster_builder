#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"

/*
  Function:  copyPlayer
  Purpose:   copy data from one player to another
      out:   newPlayer PlayerType that is going to contain values from oldPlayer
       in:   oldPlayer PlayerType that is getting its values copied 
*/
void copyPlayer(PlayerType *newPlayer, PlayerType *oldPlayer) {
  initPlayer(oldPlayer->id, oldPlayer->sport, oldPlayer->name, oldPlayer->gender, oldPlayer->age, newPlayer);
}

/*
  Function:  addPlayer
  Purpose:   add player an to array arr in its correct position
      out:   array arr that is going to have a new player added to it
       in:   player an that is going to be added to the array
*/
void addPlayer(PlayerArrayType *arr, PlayerType *player) {

  // check if there is room to add anything
  int insertionPoint;
  if (arr->size < arr->capacity) {

    // if there is nothing in the array, add, else, find insertion point, shift, add
    if (arr->size == 0) {
      copyPlayer(arr->elements, player);
    } else {

      // find insertion point
      for (int i = 0; i < arr->size; ++i) {
        if (arr->elements[i].sport == player->sport) {
          if (player->age >= arr->elements[i].age) {
            insertionPoint = i;
            break;
          } else if (i == arr->size - 1) {
            insertionPoint = i + 1;
            break;
          }
        } else if (arr->elements[i].sport > player->sport) {
          insertionPoint = i;
          break;
        } else if (i == arr->size - 1) {
          insertionPoint = i + 1;
          break;
        }
      }

      // shift elements
      for (int i = arr->size - 1; i >= insertionPoint; --i) {
        copyPlayer(&(arr->elements[i + 1]), &(arr->elements[i]));
      }

      // add player to insertion point
      copyPlayer(&(arr->elements[insertionPoint]), player);

    }
    ++arr->size;
  }
  return;
}

/*
  Function:  delPlayer
  Purpose:   removes a player from arr and shifts elements back into position
      out:   array arr that is going to have an player removed
       in:   player id that is going to be removed from the array
   return:   returns an error flag if an player is not found
*/
int delPlayer(PlayerArrayType *arr, int id) {
  for (int i = 0; i < arr->size; ++i) {
    if (arr->elements[i].id == id) {
      if (i == arr->size - 1) {
        --arr->size;
        return C_OK;
      } else {
        for (int y = i + 1; y < arr->size; ++y) {
          copyPlayer(&(arr->elements[y - 1]), &(arr->elements[y]));
        }
        --arr->size;
        return C_OK;
      }
    }
  }
  return C_NOK;
}

/*
  Function:  printPlayers
  Purpose:   prints all players in a spaced out format
       in:   players to be printed out 
*/
void printPlayers(PlayerArrayType *arr) {
  char sport[12];
  int years = 0;
  int months = 0;

  // assign proper sport string
  for (int i = 0; i < arr->size; ++i) {
    if (arr->elements[i].sport == 0) {
      strcpy(sport, "Hockey");
    } else if (arr->elements[i].sport == 1) {
      strcpy(sport, "Basketball");
    } else {
      strcpy(sport, "Other");
    }

    // split months into years 
    if (arr->elements[i].age >= 12) {
      years = arr->elements[i].age / 12;
      months = arr->elements[i].age % 12;
    } else {
      years = 0;
      months = arr->elements[i].age;
    }

    //print
    printf("%-4d : %-10s : %12s : %s; Age: %3d yrs, %2d mths\n", arr->elements[i].id, arr->elements[i].name, sport, arr->elements[i].gender, years, months);
  }
}

/*
  Function:  cleanupPlayerArray
  Purpose:   frees all memory in heap used up by elements in the player array
       in:   players array containing the pointer to the memory in the heap
*/
void cleanupPlayerArray(PlayerArrayType *arr) {
  free(arr->elements);
}

/*
  Function:  printPlayersBySport
  Purpose:   prints all players with a specific given sport
       in:   players array containing players to be printed
       in:   given sport type to find players that will be printed
*/
void printPlayersBySport(PlayerArrayType *arr, SportType s) {
  PlayerArrayType playerArr;
  initPlayerArray(&playerArr, MAX_CAP);

  for (int i = 0; i < arr->size; ++i) {
    if (arr->elements[i].sport == s) {
      addPlayer(&playerArr, &(arr->elements[i]));
    }
  }

  printPlayers(&playerArr);
  cleanupPlayerArray(&playerArr);
}

/*
  Function:  validateSport
  Purpose:   prints all players with a specific given sport
       in:   the sport type inputed by the user
      out:   sport type to be stored if valid
   return:   return success or error flag
*/
int validateSport(int choice, SportType *s) {
  if (choice == 1) {
    *s = C_HOCKEY;
    return C_OK;
  } else if (choice == 2) {
    *s = C_BASKETBALL;
    return C_OK;
  } else if (choice == 3) {
    *s = C_OTHER;
    return C_OK;
  } else {
    return C_NOK;
  }
}