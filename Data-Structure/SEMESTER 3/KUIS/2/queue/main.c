#include "head.h"

int main () {
  /* INIT QUEUE */
  queue Q;
  createQueue(&Q);

  // input how many person
  int n;

  scanf("%d", &n);

  object input; // struct

  int i;
  for (i = 0; i < n; i++) {
    scanf("%s %d", &input.nama, &input.prio);
    addPriority(input, input.prio, &Q); // add priority
  }

  // input how many person to out
  int out;
  scanf("%d", &out);

  /* PROCESS AND OUTPUT */
  keluarBarakah(out, &Q);

  return 0;
}