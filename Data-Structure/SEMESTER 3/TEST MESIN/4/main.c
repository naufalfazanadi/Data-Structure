/* --- TEST MESIN 4 --- */

/* GANDA DINAMIS */

#include "head.h"

int main () {
  /* INIT LIST */
  list L;
  createList(&L);

  /* INPUTAN */
  object bintang[6];

  int i;
  for (i = 0; i < 6; i++) {
    scanf("%s %s", &bintang[i].nama, &bintang[i].konstelasi);
  }

  /* PROSES + OUTPUT */
  addFirst(bintang[0], &L);
  addFirst(bintang[1], &L);
  addAfter(L.first, bintang[2], &L);

  printElement(L); // output

  delAfter(L.first->next->prev, &L);
  addLast(bintang[3], &L);

  printElement(L); // output

  delFirst(&L);
  addLast(bintang[4], &L);
  addAfter(L.first->next, bintang[5], &L);
  delLast(&L);

  printToHead(L); // output

  return 0;
}
/*
Fornacis Fornax
Bellatrix Orion
Alpheratz Andromeda
Vega Lyra
Aldebaran Taurus
Menkalinan Auriga
*/
