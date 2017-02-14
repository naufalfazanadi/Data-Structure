#include "head.h"

int main () {
  list L;
  createList(&L);

  int n;
  scanf("%d", &n);

  object input;

  int i;
  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &input.jam, &input.menit, &input.detik);
    input.sumWaktu = count(input);

    addLast(input, &L);
  }

  sorting(&L);

  printElement(L);

  return 0;
}