/* --- BISMILLAHIRRAHMAANIRRAHIIM --- */
/*                                    */
/* CODE BY : M. Naufal Fazanadi       */
/*                                    */
/* ---------------------------------- */

#include "head.h"

int main () {
  /* --- CREATE LIST --- */
  list L;
  createList(&L);
  /* ------------------- */
  object kuvukiland; // for input

  int i = 0;
  /* ----------------------- INPUT ----------------------- */
  do {
    scanf("%s", &kuvukiland.signal);
    if (strcmp(kuvukiland.signal, "DONE") != 0) { // if not DONE
      addLast(kuvukiland, &L); // add to List !
    }
  } while (strcmp(kuvukiland.signal, "DONE") != 0);

  // CHECK THE LIST
  printf("==== Received Messages ====\n");
  printElement(1, L);


  /* ----------------------- PROCESS ----------------------- */
  int filtered = filter(&L);
  sorting(&L);

  /* ----------------------- OUTPUT ----------------------- */
  printf("==== Filtered Messages ====\n");
  printf("%d\n", filtered); // sum of filtered message
  printf("=== Valid Messages List ===\n");
  /* SORTING */
  /* ------- */
  printElement(2, L);

  return 0;
}

/* SOAL !!!!!!!!!!!!!! */

/*
Tobi adalah seorang agen intelijen dari negeri Kuvukiland. Ia ditugaskan oleh pemerintahnya untuk pergi mengembara dan menyelamatkan para penduduk negeri Kuvukiland yang diculik oleh negeri lain. Ia mendapat perintah untuk membuat program yang mampu menerima sinyal selama 1 hari penuh untuk menerima daftar nama yang harus ditemukannya. Menurut pemerintah, sinyal yang berisi nama atau inisial target memiliki ciri sebagai berikut :

Memiliki sinyal khusus panjang (Strip / - ) dan/atau pendek (Titik / . )
Memiliki paling tidak 1 karakter huruf
Tobi juga harus membuat program tersebut menyaring sinyal yang sudah masuk agar sesuai dengan kriteria nama atau alias penduduk Kuvukiland, yaitu :

Memiliki maksimal 5 karakter huruf
Tidak memiliki karakter angka
Bantulah Tobi mendapatkan daftar nama targetnya yang sudah diurutkan dari atas!

Catatan : Usahakan menggunakan 1 list saja dan usahakan data yang tidak valid dihapus (gunakan fungsi mesin del*)
Format Masukan

Kode sinyal sebanyak-banyaknya hingga ditemukan kata DONE
Format Keluaran

Isi Daftar/List semua sinyal yang diterima, jika tidak ada, beri pesan khusus untuk Tobi
Jumlah sinyal yang disaring
Isi Daftar/List nama yang valid saja dan sudah diurutkan, jika kosong beri pesan pada Tobi untuk pulang
Contoh Masukan

FS-A.
M.F---.-R
LPM4ST3R-666
-.-.-.-.-.-.-
M-i-r-a.N
D4D4NG
SADLIFE
HELPME
M.N.
M-Rn
F-AF
DONE


Contoh Keluaran

==== Received Messages ====
FS-A.
M.F---.-R
LPM4ST3R-666
-.-.-.-.-.-.-
M-i-r-a.N
D4D4NG
SADLIFE
HELPME
M.N.
M-Rn
F-AF
==== Filtered Messages ====
5
=== Valid Messages List ===
FAF
FSA
MFR
MN
MRn
MiraN

Contoh Masukan 2

DONE


Contoh Keluaran 2

==== Received Messages ====
No signal received.
==== Filtered Messages ====
0
=== Valid Messages List ===
Return to base immediately.
 */