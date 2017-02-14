#include "head.h"

int main () {
  /* INIT LIST */
  list L;
  createList(&L);

  /* INPUT */
  object stars; // var for input

  int n; // jumlah
  scanf("%d", &n);

  int i;
  for (i = 0; i < n; i++) {
    scanf("%s", &stars.nama); // input
    addLast(stars, &L); // add to list
  }

  /* PROCESS */
  reArrange(&L); // re-arrange the list depends on konso vokal. . .

  /* OUTPUT */
  printElement(L);

  return 0;
}