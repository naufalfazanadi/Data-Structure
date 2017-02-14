#include "head.h"

int main () {
  queue S;
  createQueue(&S);

  int n;
  scanf("%d", &n);

  object input[n];

  char command[n][16];
  int number[n];

  int i;

  for (i = 0; i < n; i++) {
    scanf("%s", &command[i]);
    if (strcmp(command[i], "add") == 0) {
      scanf("%d", &input[i].num);
    } else if (strcmp(command[i], "add_prioritas") == 0) {
      scanf("%d %d", &input[i].num, &number[i]);
    }
  }

  for (i = 0; i < n; i++) {
    if (strcmp(command[i], "add") == 0) {
      add(input[i], &S);
    } else if (strcmp(command[i], "del") == 0) {
      del(&S);
    } else if (strcmp(command[i], "add_prioritas") == 0) {
      addPriority(input[i], number[i], &S);
    } else if (strcmp(command[i], "print_queue") == 0) {
      printQueue(S);
    }
  }

  return 0;
}