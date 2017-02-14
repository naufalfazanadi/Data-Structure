#include "head.h"

int main () {
  stack S1;
  stack S2;
  createStack(&S1);
  createStack(&S2);

  object asdos[5];

  int i;
  for (i = 0; i < 5; i++) {
    scanf("%s", &asdos[i].nama);
  }

  printf("S1 - ");printStack(S1);
  printf("S2 - ");printStack(S2);
  push(asdos[0], &S1);
  push(asdos[1], &S2);
  move(&S1, &S2);
  printf("S1 - ");printStack(S1);
  printf("S2 - ");printStack(S2);
  pop(&S2);
  push(asdos[2], &S1);
  push(asdos[3], &S2);
  push(asdos[4], &S2);
  move(&S2, &S1);
  printf("S2 - ");printStack(S2);
  printf("S1 - ");printStack(S1);

  return 0;
}