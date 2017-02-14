#include "head.h"

int main () {
  stack S1, S2;
  createStack(&S1);
  createStack(&S2);

  object input;

  int i, m, n;

  char stackKe[3];
  scanf("%s", &stackKe);

  if (strcmp(stackKe, "s1") == 0) {
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
      scanf("%d", &input.num);
      push(input, &S1);
    }
  } else if (strcmp(stackKe, "s2") == 0) {
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
      scanf("%d", &input.num);
      push(input, &S2);
    }
  }

  scanf("%s", &stackKe);

  if (strcmp(stackKe, "s1") == 0) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", &input.num);
      push(input, &S1);
    }
  } else if (strcmp(stackKe, "s2") == 0) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", &input.num);
      push(input, &S2);
    }
  }

  checkAndOutput(&S1, &S2);

  return 0;
}