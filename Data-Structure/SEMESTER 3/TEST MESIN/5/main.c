#include "head.h"

int main () {
  /* INIT LIST */
  list L;
  createList(&L);

  /* INPUT */
  int n;
  scanf("%d", &n);

  /* DECLARE OBJECT */
  objectRow inisial[n]; // row
  objectCol kata[n][4]; // col

  int i, j;
  for (i = 0; i < n; i++) {
    scanf(" %c", &inisial[i].ch);

    for (j = 0; j < 4; j++) { // input aja dulu
      scanf("%s", &kata[i][j].str);
    }

    addLastB (inisial[i], &L); // add to list
  }

  eRow *var = L.first; // untuk counter
  for (i = 0; i < n; i++) { // untuk kolom
    addLastK(kata[i][0], var);
    addAfterK(var->col, kata[i][1]);
    addLastK(kata[i][2], var);
    addFirstK(kata[i][3], var);


    var = var->next; // iterasi
  }
  printElement(L);

  return 0;
}