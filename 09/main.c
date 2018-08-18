/*
 Exercise scanning characters from stdin using
 scanf with spaces and using escape codes for
 color outputs
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i = 0;
  char *str;
  // int ch = '\0';

  if (( str = malloc(sizeof(char)*50)) == NULL) {
    printf("ERROR:\n");
    fprintf(stderr, "Cannot allocate memory string...!\n");
    exit(EXIT_FAILURE);
  }

  /* Another method to add characters to char pointer */
  /*
  while (ch != EOF && ch != '\n') {
    ch = getchar();
    *(str+i) = ch;
    i++;
  }
  */

  printf("Enter a string: ");
  scanf("%25[^\t\n]s", str);
  
  printf("\nYour entry is: %s\n" \
         "<str> pointer address: [%p]\n",
         str, str);

  for (i = 0; i < 20; ++i) {
    /* prints the charcters entered to the char pointer with their memory address */
    printf("\e[31m%c\e[0m \e[32m[%p]\e[0m\n", *(str+i), (str+i));

  }
  
  free(str);
  return 0;
}
