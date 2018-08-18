/*
    Exercise about type independet linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void)
{
  const size_t size = 10;
  int i = 23, ival;
  HQUEUE node1;

  char *str = "This is a test message";
  char *sval = "";
  
  if ((node1 = CreateQueue(size, sizeof(char *))) == NULL) {
    fprintf(stderr, "Cannot create node1...!\n");
    exit(EXIT_FAILURE);
  }
  
  for (i = 0; i < (int)size; ++i) {
    PutQueue(node1, &str);
  }

  while (IsEmptyQueue(node1)==FALSE) {
    GetQueue(node1, &ival);
    printf("node1: %s\n", sval);
  }

  CloseQueue(node1);
  
  return 0;
}
