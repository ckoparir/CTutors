/*
  Exercise about measuring process time between
  two process. And using selective main method
  with #define preprocessor declaration
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STDC_METHOD

#ifdef STDC_METHOD
int main(void) {
  FILE *f;
  int ch;
  clock_t t1, t2;
  double sec;

  printf("Using STDC_METHOD...\n");

  if ((f = fopen("/usr/bin/emacs", "rb")) == NULL) {
    printf("Cannot open file!..\n");
    exit(EXIT_FAILURE);
  }
  t1 = clock();
  while ((ch = fgetc(f)) != EOF)
    ;
  t2 = clock();
  sec = (double)(t2 - t1) / CLOCKS_PER_SEC;
  printf("%f\n", sec);
  fclose(f);
  return 0;
}
#endif

#ifdef SYS_METHOD
int main(void) {
  HANDLE hFile;
  char ch;
  DWORD dwRead;
  clock_t t1, t2;
  double sec;

  printf("Using SYS_METHOD...\n");

  if ((hFile = CreateFile("/usr/bin/emacs", GENERIC_READ, 0, NULL,
                          OPEN_EXISTING, 0, NULL)) == INVALID_HANDLE_VALUE) {
    printf("Cannot open file!..\n");
    exit(EXIT_FAILURE);
  }

  t1 = clock();
  do {
    if (!ReadFile(hFile, &ch, 1, &dwRead, NULL)) {
      printf("IO error\n");
      exit(EXIT_FAILURE);
    }
  } while (dwRead != 0);
  t2 = clock();
  sec = (double)(t2 - t1) / CLOCKS_PER_SEC;
  printf("%f\n", sec);
  CloseHandle(hFile);
  return 0;
}
#endif
