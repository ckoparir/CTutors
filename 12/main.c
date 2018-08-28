/**
   Exercise about recursive call of a function in C
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long long int factorial(unsigned int f)
{
  if(f <= 1) return 1;
  return f * factorial(f-1);
}

int fibonacci(int f)
{
  if(f == 0) return 0;
  if(f == 1) return 1;
   
  return fibonacci(f-1) + fibonacci(f-2);
}

int floorbyten(int num)
{
  if(num % 10 == 0)
    return num;
  else
    return floorbyten(num-1);
}

int main()
{
  // factorial function test
  int i=1;

  printf("\nFactorial test:\n" \
         "Please enter an integer to calculate its factorial: ");
    scanf("%d", &i);
  printf("Factorial of %d: %llu\n", i, factorial(i));
  
  // fibonacci function test
  printf("\nFibonacci test:\n" \
         "Please enter an integer to calculate fibonacci series: ");
  scanf("%d", &i);
  for (int f=0; f<i; ++f) {
    printf("%d ", fibonacci(f));
  }
  putchar('\n');
  
  // floorbyten function test
  printf("\nFloor(10) test:\n" \
         "Please enter an integer to calculate its floor by 10: ");
  scanf("%d",&i);
  printf("Floor of %d: %d", i, floorbyten(i));
  putchar('\n');
  
  return 0;
  
}
