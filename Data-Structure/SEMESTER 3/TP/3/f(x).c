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
      printf("%d %s %d\n", L.data[counter].elmt.nomor,
                           L.data[counter].elmt.nama,
                           L.data[counter].elmt.harga);
      /*iterasi*/
      counter = L.data[counter].next;
    }
  } else {
    /*proses jika list kosong*/
    printf("list kosong\n");
  }
}

void printToHead (list L) {
  if (L.first != -1) {
    /*inisialisasi*/
    int counter = L.tail;

    while(counter != -1){
      // OUTPUT
      printf("%d %s %d\n", L.data[counter].elmt.nomor,
                           L.data[counter].elmt.nama,
                           L.data[counter].elmt.harga);
      /*iterasi*/
      counter = L.data[counter].prev;
    }
  } else {
    /*proses jika list kosong*/
    printf("list kosong\n");
  }
}

int check (char penyakit[], list *L) {
  /*
  Nomor 1 dan 4 untuk nyeri
  Nomor 1 dan 3 untuk demam
  Nomor 2 dan 5 untuk alergi
  */
  int validation = 0;

  if ((*L).first != -1) {
    int counter = (*L).first; // init

    while (counter != -1 && validation == 0) { // loop
      if (strcmp(penyakit, "nyeri") == 0 &&
          ((*L).data[counter].elmt.nomor == 1 || (*L).data[counter].elmt.nomor == 4) &&
          (*L).data[counter].elmt.stok != 0) { // nyeri
        validation = 1; // 1
      } else if (strcmp(penyakit, "demam") == 0 &&
          ((*L).data[counter].elmt.nomor == 1 || (*L).data[counter].elmt.nomor == 3) &&
          (*L).data[counter].elmt.stok != 0) { // demam
        validation = 2; // 2
      } else if (strcmp(penyakit, "alergi") == 0 &&
          ((*L).data[counter].elmt.nomor == 2 || (*L).data[counter].elmt.nomor == 5) &&
          (*L).data[counter].elmt.stok != 0) { // alergi
        validation = 3; // 3
      }

      counter = (*L).data[counter].next; // iterate
    }

    return validation;
  }
}

void deleteObat (int validation, list *L) {
  if ((*L).first != -1) {
    int counter = (*L).first; // init
    int before; // previous elmt

    while (counter != -1) { // loop
      /* KALAU STOK KOSONG DAN SAMA DENGAN OBAT MAKA HAPUS */
      if (validation == 1 && (((*L).data[counter].elmt.nomor != 1 &&
                              (*L).data[counter].elmt.nomor != 4) || (*L).data[counter].elmt.stok == 0)) {
        if (counter == (*L).first) { // awal
          delFirst(L);
          counter = (*L).first; // pemindahan counter ke first baru
        } else {
          delAfter((*L).data[counter].prev, L); // delCurrent
          counter = before; // pemindahan counter ke elmt sebelum
        }
      } else if (validation == 2 && (((*L).data[counter].elmt.nomor != 1 &&
                                     (*L).data[counter].elmt.nomor != 3) || (*L).data[counter].elmt.stok == 0)) {
        if (counter == (*L).first) { // awal
          delFirst(L);
          counter = (*L).first; // pemindahan counter ke first baru
        } else {
          delAfter((*L).data[counter].prev, L); // delCurrent
          counter = before; // pemindahan counter ke elmt sebelum
        }
      } else if (validation == 3 && (((*L).data[counter].elmt.nomor != 2 &&
                                     (*L).data[counter].elmt.nomor != 5) || (*L).data[counter].elmt.stok == 0)) {
        if (counter == (*L).first) { // awal
          delFirst(L);
          counter = (*L).first; // pemindahan counter ke first baru
        } else {
          delAfter((*L).data[counter].prev, L); // delCurrent
          counter = before; // pemindahan counter ke elmt sebelum
        }
      }
      before = counter; // temp before
      counter = (*L).data[counter].next; // iterasi
    }
  }
}

void sorting (list *L) { // bubble sort
  int counter;
  int flip;
  int tempPrev /* pointer yang prev el */, tempNext /* pointer yang next di el */;

  int before, iterate;

  int bol;
  do { // loop hingga tidak ada penukaran
    flip = 0;
    counter = (*L).first; // init
    before = (*L).first; // init before

    iterate = 0;
    while ((*L).data[counter].next != -1) { // loop sebelum null

      bol = 0; // boolean untuk ke switch atau tidak

      if ((*L).data[counter].elmt.harga >
          (*L).data[(*L).data[counter].next].elmt.harga &&
          ((*L).data[counter].next != -1)) { // jika counter > dari next nya
        bol = 1; // true

        /* --- SWITCHING !!! --- */

        // TEMPORARY VAR
        tempNext = (*L).data[(*L).data[counter].next].next;

        if (iterate == 0) { // first loop, and switch the before to elmt next
          tempPrev = (*L).first;

          (*L).first = (*L).data[counter].next;
          (*L).data[(*L).data[counter].next].prev = -1; // reversity
        } else {
          tempPrev = (*L).data[before].next;

          (*L).data[before].next = (*L).data[counter].next;
          (*L).data[(*L).data[counter].next].prev = before;// reversity
        }

        /* switch from elmt next to current */
        (*L).data[(*L).data[counter].next].next = tempPrev;
        (*L).data[tempPrev].prev = (*L).data[counter].next; // reversity

        /* temp the before */
        before = (*L).data[counter].next;

        /* current to next next elmt */
        (*L).data[counter].next = tempNext;
        if ((*L).data[counter].next != -1) { // reversity but if in the end,
                                             // tail moved
          (*L).data[(*L).data[counter].next].prev = tempPrev;
        } else {
          (*L).tail = counter;
        }

        flip = 1;
      }
      if (bol == 0) { // if switched
        before = counter;
        counter = (*L).data[counter].next; // iterasi
      } else {
        counter = (*L).data[before].next; // iterasi
      }
      iterate = 1;
    }

  } while(flip == 1);
}

maxMin checkMaxMin (list *L) { // this is typedef function
  sorting(L); // sort first

  maxMin result; // var typedef
  result.max = 0; // set to 0
  result.min = 0; // set to 0

  int same; // pembeda
  int bol = 0;

  // min
  int counter = (*L).first; // init
  while(counter != -1 && bol == 0) { // jika belum ketemu 2 harga min
    if (counter == (*L).first) { // if first loop
      result.min += (*L).data[(*L).first].elmt.harga; // min plused
      same = (*L).data[(*L).first].elmt.nomor; // nomornya ganti
    } else if (same != (*L).data[counter].elmt.nomor) {
      result.min += (*L).data[counter].elmt.harga;
      bol = 1;
    }
    counter = (*L).data[counter].next; // iterate
  }

  // max
  same = 0; // reset
  bol = 0; // reset
  counter = (*L).tail; // reversity
  while(counter != -1 && bol == 0) { // jika belum ketemu 2 harga max
    if (counter == (*L).tail) { // jika first loop
      result.max += (*L).data[(*L).tail].elmt.harga; // max plused
      same = (*L).data[(*L).tail].elmt.nomor; // nomornya ganti
    } else if (same != (*L).data[counter].elmt.nomor) {
      result.max += (*L).data[counter].elmt.harga;
      bol = 1;
    }
    counter = (*L).data[counter].prev; // iterate
  }

  return result;
}
/*
8
5 Antihistamin 3 10000
1 Amoxicillin 20 2000
2 Piroxicam 5 6000
2 Indomethacine 0 4000
5 Bioflavonoid 20 1000
3 Benorylate 15 3000
5 Metamizole 10 2000
3 Fentanyl 9 11000
alergi
 */