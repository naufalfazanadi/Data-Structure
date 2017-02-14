#include "head.h"

int main () {
  /* INIT MAIN QUEUE */
  queue Q;
  createQueue(&Q);

  /* INPUT */
  int n;
  scanf("%d", &n);

  object pendaftar;

  int i;
  for (i = 0; i < n; i++) { // loop
    scanf("%s %d %d", &pendaftar.nama, &pendaftar.TOEFL, &pendaftar.prio);

    // Add to queue
    if (pendaftar.prio == 0) { // usual add
      add(pendaftar, &Q);
    } else { // add priority
      addPriority(pendaftar, pendaftar.prio, &Q);
    }
  }

  /* INIT Golongan 1 Golongan 2 QUEUE */
  queue Q1;
  queue Q2;
  createQueue(&Q1);
  createQueue(&Q2);

  /* PROCESSING */
  selectionTOEFL(&Q, &Q1, &Q2);

  /* OUTPUT */
  output(Q, Q1, Q2);

  return 0;
}