#ifndef _LIST_H
#define _LIST_H

#include <stddef.h>

/* Symbolic Constants */
#define TRUE 1
#define FALSE 0

/* Typedef Declarations */
typedef int BOOL;

typedef struct tagQUEUE {
  size_t size;
  size_t head;
  size_t count;
  size_t tail;
  size_t width;
  void *pQueue;
} QUEUE, *HQUEUE;

/* Function Prototypes */
HQUEUE CreateQueue(size_t size, size_t width);
void CloseQueue(HQUEUE hQueue);
BOOL PutQueue(HQUEUE hQueue, const void *pItem);
BOOL GetQueue(HQUEUE hQueue, void *pItem);
BOOL IsEmptyQueue(HQUEUE hQueue);

#endif
