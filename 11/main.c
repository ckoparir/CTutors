/**
   Sorting algorithm exercises
   [ Quick - Selection ]
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Prints array sequentially
void print(int *array, int size, int clear)
{
  if(clear)
    system("clear");
  
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < array[i]; ++j) {
      printf("|");
    }
    putchar('\n');
  }
  putchar('\n');
  usleep(500);
}

void println(int *array, int size)
{
  
  printf("\r\033[2K");
  /* usleep(1000); */
  for (int i=0; i < size; ++i) {
    printf("%d ", array[i]);
    /* usleep(5000); */
  }
}

// Swaps two integer 
void swap(int *a, int *b)
{
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
  
}

// Partition function used in quick sort algorithm
int partition(int *array, int lo, int hi)
{
  int pivot = array[hi];
  int i = lo - 1;

  for (int j = lo; j <= hi-1 ; j++)
  {
    if(array[j] <= pivot)
    {
      i++;
      swap(&array[i], &array[j]); 
    }
  }
  swap(&array[i+1], &array[hi]);
  return i+1;
}

// Quick sort algoritm method
void QuickSort(int* array, int lo, int hi)
{
  if( lo < hi )
  {
    int p = partition(array, lo, hi);
    QuickSort(array, lo, p-1);
    QuickSort(array, p+1, hi);
  }
  println(array, hi);
}

/**
   Selection Sort Visiualazation
   
  4 ----
       | 4
  3 -[  ]----
       | 3   | 4
  1 -[  ]--[  ]----
       | 1   | 3  | 4
  2 -[  ]--[  ]--[  ]----
       | 1   | 2  | 3   | 4
      
*/

void SelectionSort(int *array, int size)
{
  for (int col=0; col < size; ++col)
  {
    for (int row=0; row < size; ++row)
    {
      if(array[col] < array[row])
      {
        swap(&array[col], &array[row]);
      }
    }
    println(array, size);
  }
}
void initarray(int *array, int size)
{
  for (int i=0; i<size; ++i) {
    int r = rand() % size;
    array[i] = r;
  }
}

int main(void)
{
  double sec;
  clock_t tss1, tss2, tqs1, tqs2;

  int array[50] = {0};
  
  int size = sizeof(array) / sizeof(array[0]);
  initarray(&(*array), size);
  printf("\033[2J\033[H");
  println(array, size);
  
  // Selection sort *****
  printf("\n\nSelection sort...\n");

  tss1 = clock();
  SelectionSort(array, size);
  tss2 = clock();
  // ********************
  
  // Quick sort *********
  printf("\n\nQuick sort...\n");

  tqs1 = clock();
  QuickSort(array, 0, size);
  tqs2 = clock();
  // ********************

  // Results ************
  sec = (double)(tss2 - tss1) / CLOCKS_PER_SEC;
  printf("\n\nSelection sort completed in %f sec.\n", sec);
  
  sec = (double)(tqs2 - tqs1) / CLOCKS_PER_SEC;
  printf("Quick sort completed in %f sec.\n", sec);
  // ********************
  
  return 0;
}
