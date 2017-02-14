#include "head.h"

void createList (list *L) { // inisialisasi list
  (*L).first = -1;
  (*L).tail = -1;

  int i;
  for (i = 0; i < 10; i++) {
    /*proses menginisialisasi isi array*/
    (*L).data[i].prev = -2;
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

  if (countElement(L) < 10) {
    int ketemu = 0;
    int i = 0;

    // sequential search
    while((ketemu == 0) && (i < 10)) {
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

void addFirst (object fx, list *L) {
  if (countElement(*L) < 10) {
    int baru = emptyElement(*L);

    (*L).data[baru].elmt = fx;

    if ((*L).first == -1) {
      /*jika list kosong*/
      (*L).data[baru].prev = -1;
      (*L).data[baru].next = -1;
      (*L).tail = baru;
    } else {
      /*jika list tidak kosong*/
      (*L).data[baru].prev = -1;
      (*L).data[baru].next = (*L).first;
      (*L).data[(*L).first].prev = baru;
    }

    (*L).first = baru;
  } else {
    /*proses jika array penuh*/
    printf("sudah tidak dapat ditambah\n");
  }
}

void addAfter (int before, object fx, list *L) {
  if (countElement(*L) < 10) {
    int baru = emptyElement(*L);

    (*L).data[baru].elmt = fx;

    if ((*L).data[before].next != -1) { // kalau tidak di ujung
      (*L).data[baru].prev = before;
      (*L).data[baru].next = (*L).data[before].next;
      (*L).data[before].next = baru;
      (*L).data[(*L).data[baru].next].prev = baru;
    } else { // kalau diujung
      (*L).data[baru].prev = before;
      (*L).data[before].next = baru;
      (*L).data[baru].next = -1;
      (*L).tail = baru;
    }
  } else {
    /*proses jika array penuh*/
    printf("sudah tidak dapat ditambah\n");
  }
}

void addLast(object fx, list *L) {
  if ((*L).first == -1) {
    /*proses jika list masih kosong*/
    addFirst(fx, L);
  } else {
    /*proses jika list telah berisi elemen*/
    if (countElement(*L) < 10) {
      /*proses jika array belum penuh*/
      /*proses mencari elemen terakhir*/
      /*inisialisasi*/
      int before = (*L).first;

      while ((*L).data[before].next != -1) {
        /*iterasi*/
        before = (*L).data[before].next;
      }
      addAfter(before, fx, L);
    } else {
      /*proses jika array penuh*/
      printf("sudah tidak dapat ditambah\n");
    }
  }
}

void delFirst (list *L) {
  if ((*L).first != -1) {
    int hapus = (*L).first;

    if(countElement(*L) == 1){ // single list
      (*L).first = -1;
      (*L).tail = -1;
    }else{
      (*L).first = (*L).data[(*L).first].next;
      (*L).data[(*L).first].prev = -1;
    }

    /*elemen awal sebelumnya dikosongkan*/
    (*L).data[hapus].prev = -2;
    (*L).data[hapus].next = -2;
  } else {
    /*proses jika list kosong*/
    printf("list kosong\n");
  }
}

void delAfter (int before, list *L) {
  int hapus = (*L).data[before].next;

  if(hapus != -1){
    if ((*L).data[hapus].next == -1) {
      (*L).tail = before;
      (*L).data[before].next = -1;
    } else {
      (*L).data[before].next = (*L).data[hapus].next;
      (*L).data[(*L).data[hapus].next].prev = before;
    }

    /*pengosongan elemen*/
    (*L).data[hapus].prev = -2;
    (*L).data[hapus].next = -2;
  }
}

void delLast (list *L) {
  if ((*L).first != -1) {
    if (countElement(*L) == 1) {
      /*proses jika list hanya berisi satu elemen*/
      delFirst(L);
    } else {
      int hapus = (*L).tail;
      (*L).tail = (*L).data[hapus].prev;
      (*L).data[(*L).tail].next = -1;

      /*elemen terakhir sebelumnya dikosongkan*/
      (*L).data[hapus].prev = -2;
      (*L).data[hapus].next = -2;
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

void printElement (list L) {
  if (L.first != -1) {
    /*inisialisasi*/
    int counter = L.first;

    while(counter != -1){
      // OUTPUT
      printf("%s %d %d\n", L.data[counter].elmt.nama, L.data[counter].elmt.stok, L.data[counter].elmt.harga);
      /*iterasi*/
      counter = L.data[counter].next;
    }
  } else {
    /*proses jika list kosong*/
    printf("list kosong\n");
  }
  printf("======\n");
}

void printToHead (list L) {
  if (L.first != -1) {
    /*inisialisasi*/
    int counter = L.tail;

    while(counter != -1){
      // OUTPUT
      printf("%s %d %d\n", L.data[counter].elmt.nama, L.data[counter].elmt.stok, L.data[counter].elmt.harga);
      /*iterasi*/
      counter = L.data[counter].prev;
    }
  } else {
    /*proses jika list kosong*/
    printf("list kosong\n");
  }
  printf("======\n");
}