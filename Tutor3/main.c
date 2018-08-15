#include <stdio.h>
#include <stdlib.h>

void foreach(int *p, int size, void(*pf)(int *))
{
  while (size > 0) {
    pf(p++);
    size--;
  }
}

void printptr(int *pi)
{
  printf("%16d\t->\t[ %p - %p ]\n", *pi, pi, &pi);
}

void incptr(int *pi)
{
  *pi = *pi+1;
}

int main()
{
  const int isize = 10;
  int iarr[50] = {11, 22, 33, 44, 55};

  puts("\nBefore [ void incptr(int *) ]\n");
  foreach(iarr, isize, printptr);

  foreach(iarr, isize, incptr);  // increment integers

  puts("\nAfter [ void incptr(int *) ]\n");
  foreach(iarr, isize, printptr);

  puts("");
  
  return 0;
}
