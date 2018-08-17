#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ShowHelp() {
  system("@clr||clear");
  printf("\nCommnds for Queue:\n");
  printf("<h> Help (this screen)\n"
         "<a> to add data to queue\n"
         "<g> to get data from queue\n"
         "<q> exit program\n\n");

  printf("Please choose a method for queue: ");
}

int main(void) {
  char val[25], ientry[25];
  int csel;
  HQUEUE hQueue;

  if ((hQueue = CreateQueue(sizeof(char*))) == NULL) {
    fprintf(stderr, "Cannot create queue...!\n");
    exit(EXIT_FAILURE);
  }

  ShowHelp();

  while ((csel = getchar()) != EOF) {

    switch (csel) {
      case 'a': {
        /* Add Queue */
          printf("Add an entry for queue:");
          scanf("%20s\n", ientry);
          if (!PutQueue(hQueue, &ientry)) {
            fprintf(stderr, "Error adding data to queue...!\n");
            CloseQueue(hQueue);
            exit(EXIT_FAILURE);
          }
          // ShowHelp();
          break;
      }
      case 'g': {
        /* Get Queue */
        if (IsQueueEmpty(hQueue)) {
          printf("\nQueue stack is empty...!\n");
          break;
        }
        if (GetQueue(hQueue, &val)) {
          printf("\nData: %s\n", val);
          getchar();
        }
        // ShowHelp();
        break;
      }
      case 'h': {
        ShowHelp();
        break;
      }
      case 'q': {
        CloseQueue(hQueue);
        return 0;
      }
    }
  }

  CloseQueue(hQueue);
  return 0;
}
