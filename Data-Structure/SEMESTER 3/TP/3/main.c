#include "head.h"

int main () {
  /* ----- CREATE LIST ----- */
  list L;
  createList(&L);
  /* ----------------------- */

  int n; // jumlah inputan
  scanf("%d", &n);

  object obat; // var obat
  char penyakit[8];

  /* --- INPUT --- */
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d %s %d %d", &obat.nomor, &obat.nama, &obat.stok, &obat.harga);
    addLast(obat, &L);
  }
  scanf("%s", &penyakit);

  /* --- PROCESS --- */
  int validation = check(penyakit, &L); // check the availability

  if (validation != 0) {
    deleteObat(validation, &L); // deletion of none compatible obat

    maxMin result = checkMaxMin(&L); // sorting + function max min

    /* OUTPUT */
    printToHead(L); // reverse (high to low)
    printf("%d\n", result.max);

    printf("======\n");

    printElement(L); // normal (low to high)
    printf("%d\n", result.min);
  } else { // if not available
    printf("Tidak ada rekomendasi/obat tidak tersedia.\n");
  }

  return 0;
}