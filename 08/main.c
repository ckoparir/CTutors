/*
 Exercise about type independent Queue with FIFO principle
*/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256


void ShowHelp() {
  system("@clr||clear");
  printf("\nCommnds for Queue:\n");
  printf("<h> Help (this screen)\n"
         "<a> to add data to queue\n"
         "<g> to get data from queue\n"
         "<q> exit program\n\n");

  printf("Please choose a method for queue: ");
}
/*
void Destroy()
{

  if (ientry != NULL) {
    printf("Freeing ientry...\n");
    free(ientry);
  }
  
  if(val != NULL) {
    printf("Freeing val...\n");
    free(val);
    
  }
  
  if(hQueue != NULL) {    
    printf("Freeing hQueue...\n");
    CloseQueue(hQueue);
  }
}
*/

char *GetEntry(char entry[])
{
  int ch;
  int i =0;
  
  ch = getchar();
  
  while (ch != '\n' && ch != EOF) {
    entry[i] = ch;
    ch = getchar();
    i++;
  }
  entry[i] = '\0';
  return entry;
}

int main(void) {
  int csel;
  HQUEUE hQueue;
  char val[25], ientry[25];

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
          scanf("%23s\n", ientry);
          /* GetEntry(&ientry); */
          /* fgets(ientry, 23, stdin);  */
          
          if (!PutQueue(hQueue, &ientry)) {
            fprintf(stderr, "Error adding data to queue...!\n");
            CloseQueue(hQueue);
            exit(EXIT_FAILURE);
          }
          /* getchar(); */
          /* ShowHelp(); */
          break;
      }
      case 'g': {
        /* Get Queue */
        if (IsQueueEmpty(hQueue)) {
          printf("\nQueue stack is empty...!\n");
          break;
        }
        if (GetQueue(hQueue, &val)) {
          // ShowHelp();
          printf("\nData: %s\n", val);
          //getchar();
        }
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
