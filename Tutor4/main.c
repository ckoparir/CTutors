#include <stdio.h>

void Sort(void *pvArray, unsigned size, unsigned width,
          int(*Compare) (const void *, const void *))
{
  unsigned i,j,k;
  char *pcArray = (char*) pvArray, *pc1, *pc2, temp;
  
  for(i = 0; i < size; ++i)
  {
    for (k = 0; k < size - i - 1; ++k)
    {
      pc1 = pcArray + width * k;
      pc2 = pcArray + width * (k + 1);
      if (Compare(pc1, pc2) > 0)
      {
        for (j = 0; j < width; ++j)
        {
          temp = pc1[j];
          pc1[j] = pc2[j];
          pc2[j] = temp;
        }
      }
    }  
  }
  
}

int Compare (const void *pv1, const void *pv2)
{
  int iret = 0;
  const int *pi1 = (const int *)pv1;
  const int *pi2 = (const int *)pv2;
  
  ((char)*pi1 > (char)*pi2) ? (iret=1) : (iret=-1);

  return iret;
}

void PrintArr(const void *pv, unsigned size, unsigned width)
{
  unsigned i = 0;
  const int *pi = (const int *)pv;
  const char *pc = (const char *)pv;
  
  while ( i < size ) {
    if( width < 4 )
      printf("%c ", *pc++);
    else
      printf("%d ", *pi++);

    i++;
  }
}

int main()
{
  const int _size = 10;
  int iarr[10] = { 23, 4, 66, 12, 7, 2, 76, 90 };
  char carr[10] = { 'g', 's', 'h', 'c', 'a', 'e','1','5','9','x' };
  
  putchar('\t');
  PrintArr(iarr, _size, sizeof(int));
  printf("\t->\t");
  Sort(iarr, _size, sizeof(int), Compare);
  PrintArr(iarr, _size, sizeof(int));
  putchar('\n');
  putchar('\t');

  PrintArr(carr, _size, sizeof(char));
  printf("\t->\t");
  Sort(carr, _size, sizeof(char), Compare);
  PrintArr(carr, _size, sizeof(char));
  putchar('\n');
  
    
  return 0;
}
