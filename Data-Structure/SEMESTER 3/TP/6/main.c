#include "head.h"

int main () {
  /* INIT FIRST STACK */
  stack S1;
  createStack(&S1);

  /* INPUT */
  int n;
  scanf("%d", &n);

  object project;

  int i;
  for (i = 0; i < n; i++) {
    scanf("%s %d %d", &project.nama, &project.waktu, &project.profit);
    push(project, &S1); // object push to stack
  }

  // printStack(S1);

  /* INIT FOR SECOND STACK (Stack for the project that taken) */
  stack S2;
  createStack(&S2);

  /* PROCESS AND OUTPUT */
  moveAndPrint(&S1, &S2);

  return 0;
}