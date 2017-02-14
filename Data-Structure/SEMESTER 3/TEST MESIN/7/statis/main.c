#include "head.h"

int main () {
  queue Q;
  createQueue(&Q);

  object asdos[8];

  int i;
  for (i = 0; i < 8; i++) {
    scanf("%s", &asdos[i].nama);
  }

  add(asdos[0], &Q);
  add(asdos[1], &Q);
  addPriority(asdos[2], 1, &Q);
  add(asdos[3], &Q);
  addPriority(asdos[4], 30, &Q);

  printf("======\n");
  printQueue(Q);

  printf("======\n");
  add(asdos[5], &Q);
  addPriority(asdos[6], 1, &Q);
  add(asdos[7], &Q);

  printQueue(Q);

  del(&Q);
  del(&Q);
  del(&Q);
  del(&Q);
  del(&Q);

  printf("======\n");
  printQueue(Q);
  printf("======\n");

  return 0;
}