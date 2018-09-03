#include <stdio.h>
#include <stdlib.h>


#define TRUE 1;
#define FALSE 0;

typedef int DATA;
typedef int BOOL;

typedef struct stStack
{
  DATA *pStack;
  DATA *data;
  size_t size;
}STACK, *HSTACK;

HSTACK CreateStack(size_t size)
{
  HSTACK hStack;

  if((hStack = (HSTACK)malloc(sizeof(STACK))) == NULL)
    return NULL;

  if((hStack->pStack = (DATA *)malloc(sizeof(DATA) * size)) == NULL)
  {
    free(hStack);
    return NULL;
  }

  hStack->data = hStack->pStack + size;
  hStack->size = size;

  return hStack;
}

BOOL Push(HSTACK hStack, DATA data)
{
  if(hStack->data == hStack->pStack)
    return FALSE;

  *(--hStack->data) = data;
  
  return TRUE;
}

DATA Pop(HSTACK hStack)
{
  return *(hStack->data++);
}

BOOL IsEmpty(HSTACK hStack)
{
  return hStack->data == hStack->pStack + hStack->size;
}
    
void CloseStack(HSTACK hStack)
{
  free(hStack->pStack);
  free(hStack);
}

int main()
{
  HSTACK hStack;
  char *Str = "Caglar KOPARIR";

  if((hStack = CreateStack(50)) == NULL)
  {
    fprintf(stderr,"Cannot create stack...!\n");
    exit(EXIT_FAILURE);
  }

  printf("Stack has been created successfully...\n");
  
  while (*Str != '\0') {
    Push(hStack, *Str++);
  }
  printf("The string pushed to stack.\n");
  
  // while(!IsEmpty(hStack) && Pop(hStack) != ' ');
  while (!(IsEmpty(hStack)))
    putchar(Pop(hStack));

  puts("");
  CloseStack(hStack);
  return 0;
}
