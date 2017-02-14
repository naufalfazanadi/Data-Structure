#include "head.h"

int main () {
  stack S;
  createStack(&S);

  int n;
  scanf("%d", &n);

  object input[n];

  char command[n][16];
  int number[2][n];

  int i;

  for (i = 0; i < n; i++) {
    scanf("%s", &command[i]);
    if (strcmp(command[i], "push") == 0) {
      scanf("%d", &input[i].num);
    } else if (strcmp(command[i], "pop_banyak") == 0) {
      scanf("%d", &number[0][i]);
    } else if (strcmp(command[i], "pop_cari") == 0) {
      scanf("%d", &number[1][i]);
    }
  }

  for (i = 0; i < n; i++) {
    if (strcmp(command[i], "push") == 0) {
      push(input[i], &S);
    } else if (strcmp(command[i], "pop_banyak") == 0) {
      popBanyak(number[0][i], &S);
    } else if (strcmp(command[i], "pop_cari") == 0) {
      popCari(number[1][i], &S);
    } else if (strcmp(command[i], "print_stack") == 0) {
      printStack(S);
    }
  }

  return 0;
}