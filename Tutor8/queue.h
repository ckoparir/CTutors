#ifndef _QUEUE_H
#define _QUEUE_H
#include <stddef.h>

#define TRUE 1
#define FALSE 0

typedef int Bool;

typedef struct STQUEUE {
  size_t size;
  size_t tail;
  void *data;
}QUEUE, *HQUEUE;


HQUEUE CreateQueue(size_t size);
void CloseQueue(HQUEUE hQueue);
Bool PutQueue(HQUEUE hQueue, const void *data);
Bool GetQueue(HQUEUE hQueue, void *data);
Bool IsQueueEmpty(HQUEUE hQueue);

#endif
