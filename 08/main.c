/*
 Exercise about type independent Queue with FIFO principle
*/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 25

void ShowHelp() {
  system("clear");
  printf("Commnds for Queue:\n");
  printf("\t<h>\tHelp (this screen)\n"
         "\t<+>\tto add data to queue\n"
         "\t<->\tto get data from queue\n"
         "\t<!>\texit program\n\n");
}

int main(void) {
  HQUEUE hQueue;
  char val[SIZE], ientry[SIZE] ="";
  
  if ((hQueue = CreateQueue(SIZE)) == NULL) {
    fprintf(stderr, "Cannot create queue...!\n");
    exit(EXIT_FAILURE);
  }

  ShowHelp();
  
  while (ientry[0] != '!') {

    printf(":> ");
    int i = 0, ch = 0;
    strcpy(ientry, "");
    
    while(ch != EOF && ch != '\n'){
        ch = getchar();
        *(ientry + i) = ch;
        ientry[i+1] = '\0';
        if(i++ > SIZE-1) break;
    }
          
    if(ientry[0] == '+') {
      PutQueue(hQueue, &ientry);
      printf("data has added to queue...\n");
    }
    else if(ientry[0] == '-') {

      if (IsQueueEmpty(hQueue)) {
        printf("Queue stack is empty...!\n");
      }

      if (GetQueue(hQueue, &val)) {
        printf("Data: %s\n", val);
      }
    }
    else if(ientry[0] == 'h') {
      ShowHelp();
    }
  }

  CloseQueue(hQueue);
  return 0;
}
