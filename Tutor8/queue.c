#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

HQUEUE CreateQueue(size_t size)
{
  HQUEUE hQueue;
  
  if ((hQueue = (HQUEUE) malloc(sizeof(QUEUE))) == NULL)
     return NULL;
  if((hQueue->data =(void *) malloc(sizeof(void *) * size)) == NULL) {
    free(hQueue);
    return NULL;
  }
  hQueue->size = size;
  hQueue->tail = 0;
  
  return hQueue;
}

void CloseQueue(HQUEUE hQueue)
{
  free(hQueue->data);
  free(hQueue);
}

Bool PutQueue(HQUEUE hQueue, const void *data)
{
  if(hQueue->tail == hQueue->size)
    return FALSE;

  memcpy( (char *) hQueue->data + hQueue->tail * hQueue->size, data, hQueue->size);
  ++hQueue->tail;

  return TRUE;
}

Bool GetQueue(HQUEUE hQueue, void *data)
{
  if(hQueue->tail == 0)
    return FALSE;

  memcpy(data, (char *)hQueue->data, hQueue->size);
  memmove(hQueue->data, hQueue->data + (hQueue->size), (hQueue->tail -1) * hQueue->size );

  --hQueue->tail;

  return TRUE;
}

Bool IsQueueEmpty(HQUEUE hQueue)
{
  return hQueue->tail == 0;
}
