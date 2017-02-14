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

void addFirst (int fx, list *L) { // add di awal
  if (countElement(*L) < 100) {
    int baru = emptyElement(*L);

    (*L).data[baru].elmt = fx;

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

void addAfter (int prev, int fx, list *L) { // add setelah
  if (countElement(*L) < 100) {
    int baru = emptyElement(*L);

    (*L).data[baru].elmt = fx;

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

void addLast(int fx, list *L) { // add diakhir
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

void delFirst (list *L) {
  if ((*L).first != -1) {
    int hapus = (*L).first;

    if(countElement(*L) == 1){
      (*L).first = -1;
    }else{
      (*L).first = (*L).data[(*L).first].next;
    }

    /*elemen awal sebelumnya dikosongkan*/
    (*L).data[hapus].next = -2;
  } else {
    /*proses jika list kosong*/
    printf("list kosong\n");
  }
}

void delAfter (int prev, list *L) {
  int hapus = (*L).data[prev].next;
  if(hapus != -1){

    if ((*L).data[hapus].next == -1) {
      (*L).data[prev].next = -1;
    } else {
      (*L).data[prev].next = (*L).data[hapus].next;
    }

    /*pengosongan elemen*/
    (*L).data[hapus].next = -2;
  }
}

void delLast (list *L) {
  if ((*L).first != -1) {
    if (countElement(*L) == 1) {
      /*proses jika list hanya berisi satu elemen*/
      delFirst(L);
    } else {
      int hapus = (*L).first;
      int prev;
      while ((*L).data[hapus].next != -1) {
        /*iterasi*/
        prev = hapus;
        hapus = (*L).data[hapus].next;
      }
      /*elemen sebelum elemen terakhir menjadi elemen terakhir*/
      delAfter(prev, L);
    }
  } else {
    /*proses jika list kosong*/
    printf("list kosong\n");
  }
}

void delAll (list *L) {
  int i;
  for (i = countElement(*L); i >= 1; i--) {
    /*proses menghapus elemen list*/
    delLast(L);
  }
}

void printElement (list L) { // OUTPUT
  if (L.first != -1) {
    /*inisialisasi*/
    int counter = L.first;

    while(counter != -1){
      /*proses*/
      if (counter == L.first) {
        printf("%d", L.data[counter].elmt);
      } else {
        printf(" %d", L.data[counter].elmt);
      }
      /*iterasi*/
      counter = L.data[counter].next;
    }
    printf("\n");
  } else {
    /*proses jika list kosong*/
    printf("empty list\n");
  }
}

// MY F(X) !!!
void checkAndDel(int x, int y, list *L) { // checking with the rang then del
  /* INIT */
  int counter = (*L).first;
  int before = (*L).first; // for delafter

  while (counter != -1) { // loop till NULL
    if ((*L).data[counter].elmt >= x && (*L).data[counter].elmt <= y) { // if in range. . .
      if (counter == (*L).first) { // if in the first
        delFirst(L);
        counter = (*L).first; // counter back to first
      } else {
        delAfter(before, L);
        counter = before; // counter back to before first
        before = counter;
        counter = (*L).data[counter].next; // then iterate
      }
    } else {
      before = counter; // temp before
      counter = (*L).data[counter].next; // iterasi
    }
  }
}
