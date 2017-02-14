#include "head.h"

int main () {
  /* INIT LIST */
  list L;
  createList(&L);

  /* INPUT */
  int n;
  scanf ("%d", &n);

  int num; // the number
  int x, y; // <- range

  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &num);
    addLast(num, &L); // add to list with addlast
  }

  scanf("%d %d", &x, &y); // input the range

  /* PROCESS */
  checkAndDel(x, y, &L); // checking with the rang then del

  /* OUTPUT */
  printElement(L);

  return 0;
}

/*

5
2
3
4
5
6
3
4
 */