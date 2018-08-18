/*
exercise about stderr handling
(if test.txt cannot be found, gives error)
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>

extern int errno;
const char *_FILE_NAME = "test.txt";

int main() {
  FILE *fp = fopen(_FILE_NAME, "rb+");

  if (fp == NULL) {
    int errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errno);
    perror("Error printed by [perror]...!");
    fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
    printf("testt %d", errno);

  } else {

    int i = 5;
    char ch = 'A';
    float f = i + ch;
    void *_fptr = &f;

    fwrite(_fptr, sizeof(f), 1, fp);
    fclose(fp);
  }
  return 0;
}
