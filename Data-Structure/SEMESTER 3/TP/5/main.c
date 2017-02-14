#include "head.h"

int main () {
  /* INIT LIST */
  list L;
  createList(&L);

  /* INPUT LOMBA */
  int n, m;
  int i;

  scanf("%d", &n);

  objectRow lomba;
  /* INIT THE VOTE AND RATE */
  objectCol init;
  init.vote = 0;
  init.rate = 0;

  eRow *var;

  for (i = 0; i < n; i++) {
    scanf("%s", &lomba.nama);
    addLastB(lomba, &L); // add to row

    if (i == 0) {
      var = L.first;
    } else {
      var = var->next;
    }

    addFirstK(init, var); // init the col of row
  }

  /* INPUT VOTE OR RATE */
  scanf("%d", &m);

  char firstStr[5];
  char secondStr[32];
  char thirdStr[32];

  for (i = 0; i < m; i++) {
    scanf("%s %s %s", &firstStr, &secondStr, &thirdStr);
    /* PROCESS */
    update(firstStr, secondStr, thirdStr, &L); // update the vote or rate
  }

  /* PROCESS */
  sort(&L); // sort from vote then rate

  /* OUTPUT */
  printElement(L);

  return 0;
}