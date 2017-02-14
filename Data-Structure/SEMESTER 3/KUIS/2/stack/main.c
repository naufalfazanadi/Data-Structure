#include "head.h"

int main () {
  /* INIT STACK */
  stack S;
  createStack(&S);

  // how many data
  int n;
  scanf("%d", &n);

  object input; // struct

  int m;

  int i, j;
  for (i = 0; i < n; i++) { // first loop
    scanf("%d", &m);
    for (j = 0; j < m; j++) { // second loop for input skrip per - m
      scanf("%s", &input.skrip);
      push(input, &S); // immediateliately push to stack
    }
  }

  /* PROCESS AND OUTPUT HERE */
  processCommand(n, &S);

  return 0;
}