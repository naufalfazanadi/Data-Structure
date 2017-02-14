 /* --- LIST DINAMIS !!! --- */

#include "head.h"

void createList (list *L) {
  /* INIT */
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

void addFirst (int fx, list *L) {
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

void addAfter (elemen *before, int fx, list *L) {
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

  baru->prev = before;
  before->next = baru;
  baru = NULL;
}

void addLast (int fx, list *L) {
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

void delBefore (elemen *after, list *L) {
  elemen *hapus = after->prev;

  if (hapus->prev == NULL) {
    after->prev = NULL;
  } else {
    after->prev = hapus->prev;
    hapus->prev->next = after;
    hapus->prev = NULL;
  }
  hapus->next = NULL;
  free(hapus); // clean mem
}

void delLast (list *L) {
  if ((*L).first != NULL) {
    /*jika list tidak kosong*/
    if (countElement(*L) == 1) {
      /*list terdiri dari satu elemen*/
      delFirst(L);
    } else {
      /* IN THE LAST */
      elemen *hapus = (*L).tail;

      (*L).tail = hapus->prev;

      (*L).tail->next = NULL;
      hapus->prev = NULL;

      free(hapus); // erase
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
    elemen *counter = L.first;

    while (counter != NULL) {
      /*proses*/
      printf("%d\n", counter->elmt);

      /*iterasi*/
      counter = counter->next;
    }
  } else {
    /*proses jika list kosong*/
    printf("List Kosong\n");
  }
}

void printToHead (list L) { // reverse
  if (L.first != NULL) {
    /*jika list tidak kosong*/
    /*inisialisasi*/
    elemen *counter = L.tail;

    while (counter != NULL) {
      /*proses*/
      printf("%d\n", counter->elmt);

      /*iterasi*/
      counter = counter->prev;
    }
  } else {
    /*proses jika list kosong*/
    printf("List Kosong\n");
  }
}

/* ------------------- MY F(X) ------------------- */

void addFirstBelakang (int fx, list *L) { // add first from tail
  elemen *baru;
  baru = (elemen *) malloc (sizeof (elemen)); // malloc = locate memory

  baru->elmt = fx; // pemindahan

  if ((*L).tail == NULL) { // kalau kosong. . .
    baru->prev = NULL;
    baru->next = NULL;
    (*L).first = baru;
  } else {
    baru->next = NULL;
    baru->prev = (*L).tail;
    (*L).tail->next = baru;
  }

  (*L).tail = baru;
  baru = NULL;
}

void changeAndOut (list *L) {
  /* CHANGE (LOCATE THE MIDDLE) */
  elemen *var; // counter nya

  var = (*L).first;

  int i;
  for (i = 0; i < countElement(*L) / 2; i++) { // loop hingga tengah
    var = var->next; // iterasi
  }

  var->elmt = 999; // setelah kelocate tengah nya, lalu ubah

  /* OUTPUT */
  /* ------ DEPAN ------ */
  var = (*L).first; // reset

  printf("depan");
  while (var->elmt != 999) { // loop hingga tengah (999)
    printf(" %d", var->elmt); // OUT

    var = var->next; // iterasi
  }
  printf("\n"); // dont forget to \n :)

  /* ------ BELAKANG ------ */
  var = (*L).tail; // reset

  printf("belakang");
  while (var->elmt != 999) { // loop hingga tengah (999)
    printf(" %d", var->elmt); // OUT

    var = var->prev; // iterasi
  }
  printf("\n"); // dont forget to \n :)
}