#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stData {
  void *data;
  size_t size;
} DATA, *PDATA;

PDATA CreateData(size_t size) {
  PDATA pData;

  if ((pData = (PDATA)malloc(sizeof(DATA))) == NULL)
    return NULL;

  if ((pData->data = malloc(size)) == NULL) {
    free(pData);
    return NULL;
  }
  pData->size = size;

  return pData;
}

void CloseData(PDATA pData) { free(pData); }

int PutData(PDATA pData, const void *data) {
  memcpy((char *)pData->data + pData->size, data, pData->size);

  return 1;
}

int GetData(PDATA pData, void *data) {
  memcpy(data, (char *)pData->data + pData->size, pData->size);

  return 1;
}

int main(void) {
  int arr[10] = {3, 5, 7, 12, 45, 8, 2}, val[10];
  PDATA data;

  data = CreateData(sizeof(int) * 10);
  PutData(data, &arr);

  GetData(data, &val);
  for (int i = 0; i < 10; ++i) {
    printf("Value: %d\n", val[i]);
  }

  CloseData(data);

  return 0;
}
