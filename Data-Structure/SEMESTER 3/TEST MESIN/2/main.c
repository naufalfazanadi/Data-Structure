#include "head.h"

int main () {
  /* --- CREATE LIST --- */
  list L;
  createList(&L);
  /* ------------------- */

  int i;

  object asdos[5]; // typedef asdos

  for (i = 0; i < 5; i++) {
    scanf("%s %d %c", &asdos[i].nama, &asdos[i].umur, &asdos[i].jk); // INPUT
  }

  /* --- PROSES SESUAI CSPC --- */
  addFirst(asdos[0], &L);
  addLast(asdos[1], &L);
  addFirst(asdos[2], &L);

  printf("=====\n");
  printElement(L); /* OUTPUT */

  addAfter(L.first->next, asdos[3], &L);

  printElement(L); /* OUTPUT */

  delAfter(L.first->next, &L);
  addLast(asdos[4], &L);

  printElement(L); /* OUTPUT */

  delFirst(&L);
  delLast(&L);

  printElement(L); /* OUTPUT */

  delAll(&L);

  printElement(L); /* OUTPUT */

  return 0;
}