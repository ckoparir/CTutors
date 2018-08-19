/*
    Exercise about type independet linked list
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define SIZE 25

int main(void)
{
  const size_t width = 30;
  HQUEUE node1;

  char str[SIZE] = "This is a test message";
  char sval[SIZE];
  
  if ((node1 = CreateQueue(width, sizeof(char))) == NULL) {
    fprintf(stderr, "Cannot create node1...!\n");
    exit(EXIT_FAILURE);
  }
  
  for (int i = 0; i < (int) SIZE; ++i) {
    PutQueue(node1, str + i);
  }

  while (!IsEmptyQueue(node1)) {
    GetQueue(node1, &sval);
    printf("node1: %s\n", sval);
  }

  CloseQueue(node1);
  
  return 0;
}
