#include "head.h"

int main () {
  list L;
  createList(&L);

  int n;
  scanf("%d", &n);

  object input;

  int i;
  for (i = 0; i < n; i++) {
    scanf("%f", &input.num);
    input.belakang = count(input);

    addLast(input, &L);
  }

  sorting(&L);

  printElement(L);

  return 0;
}