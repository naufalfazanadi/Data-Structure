// Bismillahirrahmaanirrahiim
// ===============================
// Lua = Aul, Lua + lia = AULIA :)
// ===============================

#include "head.h"

int main () {
  // -- Create List --
  list L;
  createList(&L);
  // -----------------

  // -- Input --
  int i;
  int n;

  scanf("%d", &n); // input num

  object lua; // str dan jumlah
  char lia[32]; // str pembanding

  // INPUT
  for (i = 0; i < n; i++) {
    scanf("%s", &lua.word);
    addLast(lua, &L); // add to list
  }
  scanf("%s", &lia);
  // -----------------------

  compareWord(&L, lia); // compare huruf - angka

  sorting(&L); // sort list (sort modified)

  printElement(L); // output

  return 0;
}