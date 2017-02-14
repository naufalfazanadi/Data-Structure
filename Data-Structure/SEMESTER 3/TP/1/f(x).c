#include "head.h"

// -----------------------------------------------------------------------------
// MESIN LIST !!!
// -----------------------------------------------------------------------------

void createList (list *L) { // inisialisasi list
  (*L).first = -1;

  int i;
  for (i = 0; i < 100; i++) {
    /*proses menginisialisasi isi array*/
    (*L).data[i].next = -2;
  }
}

int countElement (list L) { // hitung list nya
  int sum = 0;

  if (L.first != -1) {
    /*list tidak kosong*/
    int counter;
    /*inisialisasi*/
    counter = L.first;

    while(counter != -1) {
      /*proses*/
      sum++;
      /*iterasi*/
      counter = L.data[counter].next;
    }
  }

  return sum;
}

int emptyElement (list L) { // cari list yg kosong
  int hasil = -1;

  if (countElement(L) < 100) {
    int ketemu = 0;
    int i = 0;

    // sequential search
    while((ketemu == 0) && (i < 100)) {
      if (L.data[i].next == -2) {
        hasil = i;
        ketemu = 1;
      } else {
        i++;
      }
    }
  }

  return hasil;
}

void addFirst (object fx, list *L) { // add di awal
  if (countElement(*L) < 100) {
    int baru = emptyElement(*L);

    (*L).data[baru].el = fx;

    if ((*L).first == -1) {
      /*jika list kosong*/
      (*L).data[baru].next = -1;
    } else {
      /*jika list tidak kosong*/
      (*L).data[baru].next = (*L).first;
    }

    (*L).first = baru;
  } else {
    /*proses jika array penuh*/
    printf("sudah tidak dapat ditambah\n");
  }
}

void addAfter (int prev, object fx, list *L) { // add setelah
  if (countElement(*L) < 100) {
    int baru = emptyElement(*L);

    (*L).data[baru].el = fx;

    if ((*L).data[prev].next == -1) {
      (*L).data[baru].next = -1;
    } else {
      (*L).data[baru].next = (*L).data[prev].next;
    }

    (*L).data[prev].next = baru;
  } else {
    /*proses jika array penuh*/
    printf("sudah tidak dapat ditambah\n");
  }
}

void addLast(object fx, list *L) { // add diakhir
  if ((*L).first == -1) {
    /*proses jika list masih kosong*/
    addFirst(fx, L);
  } else {
    /*proses jika list telah berisi elemen*/
    if (countElement(*L) < 100) {
      /*proses jika array belum penuh*/
      /*proses mencari elemen terakhir*/
      /*inisialisasi*/
      int prev = (*L).first;

      while ((*L).data[prev].next != -1) {
        /*iterasi*/
        prev = (*L).data[prev].next;
      }
      addAfter(prev, fx, L);
    } else {
      /*proses jika array penuh*/
      printf("sudah tidak dapat ditambah\n");
    }
  }
}

void printElement (list L) { // OUTPUT
  if (L.first != -1) {
    /*inisialisasi*/
    int counter = L.first;

    while(counter != -1){
      /*proses*/
      printf("%s %d\n", L.data[counter].el.word, L.data[counter].el.same);
      /*iterasi*/
      counter = L.data[counter].next;
    }
  } else {
    /*proses jika list kosong*/
    printf("List Kosong!\n");
  }
}

// MY F(X) !!!

void compareWord (list *L, char lia[]) { // perbandingan
  int counter = (*L).first; // awal
  int i, j;
  int sameChar, sameNum; // var untuk yg sama
  int total; // total sama

  while (counter != -1) { // loop selama belum null
    sameChar = 0, sameNum = 0; // initial

    for (i = 0; i < strlen((*L).data[counter].el.word); i++) { // loop word
      for (j = 0; j < strlen(lia); j++) { // loop word comparer

        if ((lia[j] == (*L).data[counter].el.word[i]) &&
            (lia[j] >= '0' && lia[j] <= '9')) { // jika sama dan angka
          sameNum++;
        } else if ((lia[j] == (*L).data[counter].el.word[i]) &&
                   (lia[j] < '0' || lia[j] > '9')) { // jika sama dan huruf
          sameChar++;
        }

      }
    }

    if (sameNum > sameChar) { // jika angka lebih banyak total *2
      total = (sameNum + sameChar) * 2;
    } else if (sameNum < sameChar) { // jika angka lebih banyak total *3
      total = (sameNum + sameChar) * 3;
    } else if (sameNum == sameChar) { // jika angka lebih banyak total tetap
      total = (sameNum + sameChar);
    }

    (*L).data[counter].el.same = total; // pemasukan

    counter = (*L).data[counter].next; // iterasi array
  }
}

// hold screen, template dari bu Rosa
// void wait(float x) {
//   //prosedur wait
//   time_t start;
//   time_t current;
//   time(&start);
//   do
//     time(&current);
//   while(difftime(current,start) < x);
// }

void sorting (list *L) { // bubble sort
  int counter;
  int flip;
  int tempPrev /* pointer yang prev el */, tempNext /* pointer yang next di el */;

  int before, iterate;

  int bol;
  do { // loop hingga tidak ada penukaran
    flip = 0;
    counter = (*L).first; // init
    before = (*L).first;

    iterate = 0;
    while ((*L).data[counter].next != -1) { // loop sebelum null

      bol = 0; // boolean untuk ke switch atau tidak

      if ((*L).data[counter].el.same >
          (*L).data[(*L).data[counter].next].el.same &&
          ((*L).data[counter].next != -1)) { // jika counter > dari next nya
        bol = 1; // true

        /* --- SWITCHING !!! --- */

        // TEMPORARY VAR
        tempNext = (*L).data[(*L).data[counter].next].next;

        if (iterate == 0) { // Ubah next dari prev
          tempPrev = (*L).first;
          (*L).first = (*L).data[counter].next;
        } else {
          tempPrev = (*L).data[before].next;
          (*L).data[before].next = (*L).data[counter].next;
        }

        (*L).data[(*L).data[counter].next].next = tempPrev;

        before = (*L).data[counter].next;

        (*L).data[counter].next = tempNext;

        flip = 1;
      }
      if (bol == 0) {
        before = counter;
        counter = (*L).data[counter].next; // iterasi
      } else {
        counter = (*L).data[before].next; // iterasi
      }
      iterate = 1;
    }

  } while(flip == 1);
}

/*
5
5e8u4h
k3n4n94n
y4n999
akan
d11n94t
9a4n3
*/