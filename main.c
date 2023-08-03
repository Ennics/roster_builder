#include <stdio.h>
#include <string.h>

#include "defs.h"

int main()
{
  PlayerArrayType players;
  initPlayerArray(&players, MAX_CAP);
  loadPlayerData(&players);

  int choice;
  do {
    printMenu(&choice);
    if (choice == 1) {
      int id, sportNum, years, months, age;
      SportType sport;
      char name[MAX_STR];
      char gender[MAX_STR];

      // prompt for id
      printf("Please enter an id: ");
      scanf("%d", &id);  
      if (id <= 0) {
        printf("INVALID ID");
      } else {
        // prompt for sport 
        printf("Please enter a sport ( 1=Hockey | 2=Basketball | 3=Other ): ");
        scanf("%d", &sportNum);
        if (sportNum == 1) {
          sport = C_HOCKEY;
        } else if (sportNum == 2) {
          sport = C_BASKETBALL;
        } else if (sportNum == 3) {
          sport = C_OTHER;
        } 
        if (sportNum <= 0 || sportNum >= 4) {
          printf("INVALID SPORT");
        } else {
          // prompt for name
          printf("Please enter a name: ");
          scanf("%s", name);
          // prompt for gender
          printf("Please enter a gender (M or F): ");
          scanf("%s", gender);
          if (strcmp(gender, "M") == 0 || strcmp(gender, "F") == 0 ) {
            // prompt for age
            printf("Please enter an age (years, months).\nYears (0-99): ");
            scanf("%d", &years);
            if (years < 0 || years > 99) {
              printf("INVALID YEAR INPUT");
            } else {
              printf("Months (0-12): ");
              scanf("%d", &months);
              if (months < 0 || months > 12) {
                printf("INVALID MONTH INPUT");
              } else {
                // all input is valid
                age = (years * 12) + months;
                // statically allocate a new player
                PlayerType newPlayer;
                initPlayer(id, sport, name, gender, age, &newPlayer);
                addPlayer(&players, &newPlayer);
              }
            }
          } else {
            printf("INVALID GENDER");
          }
        }
      }
    } else if (choice == 2) {
      int idToDelete;
      printf("Which player would you like to delete (enter an ID): ");
      scanf("%d", &idToDelete);
      if (delPlayer(&players, idToDelete) == C_NOK) {
        printf("ID DOES NOT EXIST");
      }
    } else if (choice == 3) {
      printPlayers(&players);
    } else if (choice == 4) {
      int sportToPrint;
      printf("Which sport would you like print ( 1=HOCKEY | 2=BASKETBALL | 3=OTHER ): ");
      scanf("%d", &sportToPrint);
      if (sportToPrint == 1) {
        printPlayersBySport(&players, C_HOCKEY);
      } else if (sportToPrint == 2) {
        printPlayersBySport(&players, C_BASKETBALL);
      } else if (sportToPrint == 3) {
        printPlayersBySport(&players, C_OTHER);
      } 
    }
  } while (choice > 0 && choice < 5);
  cleanupPlayerArray(&players);
  return(0);
}

/*
  Function:  printMenu
  Purpose:   prints main menu, prompts user for a choice
      out:   choice variable received from user
*/
void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 4;

  printf("\nMAIN MENU\n");
  printf("  (1) Add player\n");
  printf("  (2) Delete player\n");
  printf("  (3) Print all players\n");
  printf("  (4) Print players by sport\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}

