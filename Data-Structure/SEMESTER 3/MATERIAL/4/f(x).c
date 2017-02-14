/* --- LIST DINAMIS !!! --- */

#include "head.h"

void createList (list *L) {
  (*L).first = NULL;
  (*L).tail = NULL;
}

int countElement (list L) {
  int hasil = 0;
  if (L.first != NULL) {
    /*list tidak kosong*/
    elemen *elmt;
    /*inisialisasi*/
    elmt = L.first;

    while (elmt != NULL) {
      /*proses*/
      hasil++;
      /*iterasi*/
      elmt = elmt->next;
    }
  }
  return hasil;
}

void addFirst (object fx, list *L) {
  elemen *baru;
  baru = (elemen *) malloc (sizeof (elemen)); // malloc = locate memory

  baru->elmt = fx; // pemindahan

  if ((*L).first == NULL) {
    baru->prev = NULL;
    baru->next = NULL;
    (*L).tail = baru;
  } else {
    baru->next = (*L).first;
    baru->prev = NULL;
    (*L).first->prev = baru;
  }

  (*L).first = baru;
  baru = NULL;
}

void addAfter (elemen *before, object fx, list *L) {
  elemen *baru;
  baru = (elemen *) malloc (sizeof (elemen)); // locate the memory

  baru->elmt = fx; // pemindahan

  if (before->next == NULL) {
    baru->next = NULL;
    (*L).tail = baru;
  } else {
    baru->next = before->next;
    baru->next->prev = baru;
  }

  baru->prev = prev;
  prev->next = baru;
  baru = NULL;
}

void addLast (object fx, list *L) {
  if ((*L).first == NULL) {
    /*jika list adalah list kosong*/
    addFirst(fx, L);
  } else {
    /*jika list tidak kosong
    /*mencari elemen terakhir list*/
    elemen *prev = (*L).first;

    while (prev->next != NULL) {
      /*iterasi*/
      prev = prev->next;
    }

    addAfter(prev, fx, L);
  }
}

void delFirst (list *L) {
  if ((*L).first != NULL) {
    /*jika list bukan list kosong*/
    elemen *hapus = (*L).first;

    if (countElement(*L) == 1) {
      (*L).first = NULL;
      (*L).tail = NULL;
    } else {
      (*L).first = (*L).first->next;
      (*L).first->prev = NULL;
      hapus->next = NULL;
    }

    free(hapus); // clean mem
  }
}

void delAfter (elemen *before, list *L) {
  elemen *hapus = before->next;

  if (hapus->next == NULL) {
    before->next = NULL;
  } else {
    before->next = hapus->next;
    hapus->next->prev = before;
    hapus->next = NULL;
  }
  hapus->prev = NULL;
  free(hapus); // clean mem
}

void delLast (list *L) {
  if ((*L).first != NULL) {
    /*jika list tidak kosong*/
    if (countElement(*L) == 1) {
      /*list terdiri dari satu elemen*/
      delFirst(L);
    } else {
      /*mencari elemen terakhir list*/
      elemen *last = (*L).first;
      elemen *prev;

      while (last->next != NULL) {
        /*iterasi*/
        prev = last;
        last = last->next;
      }

      delAfter(prev, L);
    }
  }
}

void delAll (list *L) {
  if (countElement(*L) != 0) {
    int i;
    for (i = countElement(*L); i >= 1; i--) {
      /*proses menghapus elemen list*/
      delLast(L);
    }
  }
}

void printElement (list L) {
  if (L.first != NULL) {
    /*jika list tidak kosong*/
    /*inisialisasi*/
    elemen *elmt = L.first;

    while (elmt != NULL) {
      /*proses*/
      printf("%s %d %c\n", elmt->elmt.nama, elmt->elmt.umur, elmt->elmt.jk);

      /*iterasi*/
      elmt = elmt->next;
    }
  } else {
    /*proses jika list kosong*/
    printf("List Kosong\n");
  }
  printf("=====\n");
}

