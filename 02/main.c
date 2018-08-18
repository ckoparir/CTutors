/* Exercise about data structures and pointers */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  long len;
  char* data;
} DataFile;

/* Function prototypes */
DataFile* writedatafile(char*);
void printdatafile(DataFile*);

int main()
{
  DataFile* dataFile;
  char *data = "This is a test data...\n";
  
  dataFile = writedatafile(data);
  printdatafile(dataFile);

  free(dataFile);
  
  return 0;
}

DataFile* writedatafile(char* data){

  DataFile* dataFile = malloc(sizeof(DataFile));
  
  dataFile->id = rand();
  dataFile->len = sizeof(DataFile);
  dataFile->data = data;

  return dataFile;
}

void printdatafile(DataFile* df){
  printf("ID: %d\n", df->id);
  printf("Total Lenght: %ld bytes\n", df->len);
  printf("Data: %s", df->data);
}
