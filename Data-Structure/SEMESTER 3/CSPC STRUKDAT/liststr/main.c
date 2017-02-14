#include "head.h"

int main () {
  list L;
  createList(&L);

  int n;
  scanf("%d", &n);

  object input;

  int i;
  for (i = 0; i < n; i++) {
    scanf("%s", input.str);
    addFirst(input, &L);
  }

  printElement(L);

  return 0;
}