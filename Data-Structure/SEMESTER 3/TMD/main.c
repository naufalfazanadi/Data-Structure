#include "head.h"

int main () {
  /* INIT TREE */
  tree T;

  nNode = 0;
  maxLevel = 0;

  /* ---------------- INPUT ---------------- */
  int i;

  int n;
  scanf("%d", &n);

  // input the command
  char command[n][64];

  for (i = 0; i < n; i++) {
    scanf("%s", &command[i]);
    /* PROCESS INPUT (WITH SEPARATE) */
    addToTree(command[i], &T);
  }

  // --- INPUT TANGGUNG JAWAB YANG DIHAPUS ---
  behavior tanggungJawab;

  scanf("%d", &tanggungJawab.n);

  for (i = 0; i < tanggungJawab.n; i++) {
    scanf("%s", &tanggungJawab.str[i]);
  }

  // --- INPUT KEBERUNTUNGAN YANG DITAMBAH ---
  behavior keberuntungan;

  scanf("%d", &keberuntungan.n);

  for (i = 0; i < keberuntungan.n; i++) {
    scanf("%s", &keberuntungan.str[i]);
  }

  /* ---------------- PROCESSING TO OUTPUT AND CHANGING ---------------- */
  setSpace(T); // set space

  counterNode = 0; // set to 0
  printTreePreOrder(T.parent); // output

  printf("\n");

  // The change
  delMinus(tanggungJawab, keberuntungan, T.parent);

  setSpace(T); // set space again after del and add

  counterNode = 0;
  printTreePreOrder(T.parent); // output again..

  return 0;
}