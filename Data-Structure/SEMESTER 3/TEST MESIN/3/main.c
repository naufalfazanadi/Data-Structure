#include "head.h"

int main () {
  /* INIT */
  list L;
  createList(&L);
  /* ---- */

  object obat[5]; // var typedef

  /* INPUT */
  int i;
  for (i = 0; i < 5; i++) {
    scanf("%s %d %d", &obat[i].nama, &obat[i].stok, &obat[i].harga);
  }

  /* OUTPUT AND PROCESS */
  addLast(obat[0], &L);
  addFirst(obat[1], &L);
  addAfter(L.data[L.first].next, obat[2], &L);


  printElement(L); // output

  addFirst(obat[3], &L);
  delAfter(L.first, &L);

  printElement(L); // output

  addLast(obat[4], &L);

  printElement(L); // output

  delFirst(&L);
  delLast(&L);

  printElement(L); // output
  printToHead(L);

  return 0;
}