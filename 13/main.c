/**
   Excercies about bitwise operation

   * decimal to bin conversation
   * sum and subtsraction with bitwise operators
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char* convertobin(size_t const size, void const *const ptr)
{
  size_t s = size * 8;
  unsigned char *b = (unsigned char*) ptr;
  unsigned char *byte = (unsigned char*)malloc(s+1);
  int cnt=0;
  /* int c=0; */
  
  for (int i = size-1; i >= 0; i--)
  {
    for (int j = 7; j >= 0; j--)
    {

      // loop count formula
      // (i*j) + ( (i-1) * (7-j) )
      //c = abs(((i+1)*(j+1))+((i)*(7-j))-(int)s);
      byte[cnt] = (( b[i] >> j ) & 1) == 0 ? '0' : '1';
      cnt++; 
     }
  }
  return byte;
}

unsigned char* tobin(size_t size, void const *const ptr)
{
  int cnt = 0;
  unsigned char *dec = (unsigned char*) ptr;
  int quotient = (int) *dec;
  size_t SIZE = size * 8;
  
  unsigned char *byte = (unsigned char*)malloc(SIZE+1);
  
  while(quotient != 0)
  {
    byte[cnt] = ((quotient % 2) == 0) ? '0' : '1';
    quotient >>= 1;
    ++cnt;
  }
  
  cnt--;
  int i=0;

  while (cnt > 0)
  {
    unsigned char tmp = byte[i];
    byte[i] = byte[cnt];
    byte[cnt] = tmp;
    cnt--;
    i++;
  }
  return byte;
}

int Add(int a, int b)
{
  while(b != 0)
  {
    int carry = (a & b);

    a = a ^ b;
    b = carry << 1;
  }
  return a;
}

int Sub(int a, int b)
{
  while(b != 0)
  {
    
    int barrow = ((~a) & b);
    a = a ^ b;
    b = barrow <<1;
  }
  return a;
}

int AddAsm(int a, int b)
{
  int result;
 __asm__(
     "mov %1, %%eax;"
     "add %2, %%eax;": "=a"(result): "a"(a), "b"(b)
         );
 return result;
}

int main()
{
  clock_t t1, t2;
  double sec1, sec2;
  
  int a=0, b=0;
  /* int sum=0, sub=0; */
  
  /* printf("Please enter two integer: "); */
  /* scanf("%d%d", &a, &b); */
  /* sum = Add(a, b); */
  /* sub = Sub(a, b); */
  /* printf("( %d + %d ): %d\n", a, b, sub); */

  printf("Please enter an integer: ");
  scanf("%d%d", &a, &b);

  /* unsigned char *str = tobin(sizeof(int), &a); */
  t1 = clock();
  printf("( %d + %d ): %d\n", a, b, AddAsm(a, b));
  t2 = clock();


  sec1 = (double)(t2-t1) / CLOCKS_PER_SEC;


  t1 = clock();
  printf("( %d + %d ): %d\n", a, b, Add(a, b));
  t2 = clock();
  sec2 = (double)(t2-t1) / CLOCKS_PER_SEC;
  

  printf("AddAsm():\t[%f sec]\n", sec1);
  printf("Add()   :\t[%f sec]\n", sec2);

  t1 = clock();
  a += b;
  t2 = clock();
  sec2 = (double)(t2-t1) / CLOCKS_PER_SEC;
  printf("(a+=b)  : %d\t[%f sec]\n", a, sec2);
  
  
  return 0;
}
