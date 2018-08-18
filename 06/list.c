#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUBLIC
#define PRIVATE static

PUBLIC HQUEUE CreateQueue(size_t size, size_t width) {
  HQUEUE hQueue;
  if ((hQueue = (HQUEUE)malloc(sizeof(QUEUE))) == NULL)
    return NULL;
  if ((hQueue->pQueue = malloc(width * size)) == NULL) {
    free(hQueue);
    return NULL;
  }
  hQueue->size = size;
  hQueue->width = width;
  hQueue->count = hQueue->head = hQueue->tail = 0;
  return hQueue;
}

PUBLIC void CloseQueue(HQUEUE hQueue) {
  free(hQueue->pQueue);
  free(hQueue);
}

PUBLIC BOOL PutQueue(HQUEUE hQueue, const void *pItem) {
  if (hQueue->count == hQueue->size)
    return FALSE;
  if (hQueue->tail == hQueue->size)
    hQueue->tail = 0;
  memcpy((char *)hQueue->pQueue + hQueue->tail * hQueue->width, pItem,
         hQueue->width);
  ++hQueue->tail;
  ++hQueue->count;
  return TRUE;
}

PUBLIC BOOL GetQueue(HQUEUE hQueue, void *pItem) {
  if (hQueue->count == 0)
    return FALSE;
  if (hQueue->head == hQueue->size)
    hQueue->head = 0;
  /*
  hQueue->head = hQueue->head % hQueue->size;
  */
  memcpy(pItem, (char *)hQueue->pQueue + hQueue->head * hQueue->width,
         hQueue->width);
  hQueue->head++;
  --hQueue->count;
  return TRUE;
}

PUBLIC BOOL IsEmptyQueue(HQUEUE hQueue) { return hQueue->count == 0; }
