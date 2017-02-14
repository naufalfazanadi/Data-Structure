#include "head.h"

int main () {
  /* Init List */
  list L;
  createList(&L);

  /* INPUT + PROCESS !!! */
  objectRow generation; // delare struct for row
  objectCol mahasiswa; // delare struct for col

  int m, n;

  scanf("%d", &m);

  int i;
  for (i = 0; i < m; i++) {
    scanf("%s %s %d", &mahasiswa.nama, &generation.angkatan, &mahasiswa.sks);
    checkAndAdd(generation, &L);
    checkAndAddCol(mahasiswa, generation, &L);
  }

  scanf("%d", &n);

  char undurDiri[32];

  for (i = 0; i < n; i++) {
    scanf("%s", &undurDiri);
    moveUndur(undurDiri, &L);
  }

  /* OUTPUT */
  printElement(L);

  return 0;
}