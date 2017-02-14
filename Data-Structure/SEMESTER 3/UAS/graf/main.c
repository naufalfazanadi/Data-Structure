#include "head.h"

int main () {
  /* INIT GRAPH */
  graph G;
  createEmpty(&G);

  /* INIT QUEUE */
  queue Q;
  createQueue(&Q);

  /* INPUT */
  int n;
  scanf("%d", &n);

  int m;
  char initial;
  char dest;

  int i, j;
  for (i = 0; i < n; i++) {
    scanf(" %c %d", &initial, &m);
    for (j = 0; j < m; j++) {
      scanf(" %c", &dest);
      /* ADD TO GRAPH WITH PROCESS */
      addToGraph(initial, dest, &G);
    }
  }

  // the search
  scanf(" %c %c", &initial, &dest);

  counterTemp = 0;
  // FIND THE WAY OF GRAPH + OUTPUT
  findWay(initial, dest, G, &Q);

  return 0;
}