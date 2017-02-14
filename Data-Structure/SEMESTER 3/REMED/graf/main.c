#include "head.h"

int main(){
  /* INIT GRAPH */
  graph G;
  createEmpty(&G);

  /* INPUT */
  int n;
  scanf("%d", &n);

  char c1, c2; // not array because immediately add

  int i;
  for (i = 0; i < n; i++) { // loop
    scanf(" %c %c", &c1, &c2); // input

    /* PROCESSING ADD */
    addToGraph(c1, c2, &G);
  }

  // input the searched way
  int m;
  scanf("%d", &m);

  char find[32]; // way
  int bol[m]; // boolean per searched

  for (i = 0; i < m; i++) {
    scanf("%s", &find);
    /* PROCESSING THE FINDING WAY */
    bol[i] = cekJalur(find, G);
  }

  /* OUTPUT HERE */
  for (i = 0; i < m; i++) {
    if (bol[i] == 1) {
      printf("ada\n");
    } else {
      printf("tidak ada\n");
    }
  }
  // printGraph(G);

  return 0;
}