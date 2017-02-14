#include "head.h"

int main () {
  /* --- INIT LIST --- */
  list L;
  createList(&L);
  /* ----------------- */


  int n;
  scanf("%d", &n);

  int num; // var input

  /* INPUT */
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &num);
    addFirstBelakang(num, &L); // addfirst to list from tail
  }

  /* PROCESS WITH OUTPUT */
  changeAndOut(&L);

  // printElement(L); // for check the full list

  return 0;
}