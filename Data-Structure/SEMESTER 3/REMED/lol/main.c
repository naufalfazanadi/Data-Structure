#include "head.h"

int main () {
  /* INIT LIST */
  list L;
  createList(&L);

  /* INPUT */
  int n;
  scanf("%d", &n); // num

  char str[32];

  int i;
  for (i = 0; i < n; i++) {
    scanf("%s", &str); // input string
    /* PROCESSING */
    addToLol(str, &L);
  }

  /* OUTPUT */
  printElement(L);

  return 0;
}