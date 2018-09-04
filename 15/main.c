/*
  Exercise about callback functions and
  EventHandling in C
*/
#include <stdio.h>
#include <unistd.h>

typedef void (*callback)(void);
void register_callback(callback ptr_callback);

void mysleep(void)
{
  for (int i=10000; i>1; i-=100) {
    usleep(i);
  }
  printf("Sleep function ended...\n");
}

int main()
{
  callback mycall = mysleep;

  printf("Registering callback function...\n");
  register_callback(mycall);
  
  return 0;
}

void register_callback(callback  ptr_callback)
{
  printf("Callback function has been registered\n");
  (*ptr_callback)();
}

