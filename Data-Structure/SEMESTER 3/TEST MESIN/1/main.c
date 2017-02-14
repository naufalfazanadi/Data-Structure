#include "head.h"

int main () {

  int i;

  // UNTUK LIST!
  list L;
  createList(&L);

  object asdos[5]; // array inputan

  // input
  for (i = 0; i < 5; i++) {
    scanf("%s %d %c", &asdos[i].nama, &asdos[i].umur, &asdos[i].jk);
  }

  addFirst(asdos[0], &L);
  addFirst(asdos[1], &L);
  addLast(asdos[2], &L);

  delLast(&L);

  printElement(L);

  addAfter(L.data[L.data[L.first].next].next, asdos[3], &L);

  printElement(L);

  addFirst(asdos[4], &L);

  delAfter(L.first, &L);
  delLast(&L);

  printElement(L);

  delAll(&L);

  printElement(L);

  return 0;
}