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

  baru->prev = before;
  before->next = baru;
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
      printf("%s\n", counter->elmt.nama);

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
      printf("%s\n", counter->elmt.nama);

      /*iterasi*/
      counter = counter->prev;
    }
  } else {
    /*proses jika list kosong*/
    printf("List Kosong\n");
  }
}

/* ------------------- MY F(X) ------------------- */

void checkKonsoVokal(list *L) {
  elemen *var; // counter + the current
  var = (*L).first;

  int i;
  // check all the list
  while (var != NULL) {
    /* INIT */
    var->elmt.konsonan = 0;
    var->elmt.vokal = 0;

    // Loop till end of string current list
    for (i = 0; i < strlen(var->elmt.nama); i++) {
      if (var->elmt.nama[i] == 'a' || var->elmt.nama[i] == 'i' ||
          var->elmt.nama[i] == 'u' || var->elmt.nama[i] == 'e' ||
          var->elmt.nama[i] == 'o' || var->elmt.nama[i] == 'A' ||
          var->elmt.nama[i] == 'I' || var->elmt.nama[i] == 'U' ||
          var->elmt.nama[i] == 'E' || var->elmt.nama[i] == 'O') { // vokal
        var->elmt.vokal++;
      } else { // konosonan
        var->elmt.konsonan++;
      }
    }

    var = var->next; // iterasi
  }
}

/* Procedure Re-Arrange the list */
void reArrange (list *L) {
  checkKonsoVokal(L); // check first

  elemen *varHead, *varTail, *temp; // temporary var

  varHead = (*L).first; // from front
  varTail = (*L).tail; // from back

  /* MAKE A NEW SPACE FOR ADDITIONAL ELMT */
  temp = (elemen *) malloc (sizeof (elemen)); // locate the memory

  int i;
  /* SETENGAH AWAL */
  for (i = 0; i < (countElement(*L) / 2); i++) {
    if (varHead->elmt.konsonan > varHead->elmt.vokal) {
      temp->elmt = varHead->elmt;
      if (varHead == (*L).first) { // kalau diawal
        delFirst(L);
        addLast(temp->elmt, L);

        varHead = (*L).first; // the counter still in the first
      } else { // kalau di tengah
        varHead = varHead->prev; // pindahkan dulu

        delAfter(varHead, L);
        addLast(temp->elmt, L);

        varHead = varHead->next; // iterasikan
      }
    } else {
      varHead = varHead->next; // iterasi jika conditional tidak terpenuhi
    }
  }

  /* SETENGAH AKHIR */
  for (i = 0; i < (countElement(*L) / 2); i++) {
    if (varTail->elmt.konsonan < varTail->elmt.vokal) {
      temp->elmt = varTail->elmt;
      if (varTail == (*L).tail) { // jika di akhir (di tail yg awal)
        delLast(L);
        addFirst(temp->elmt, L);

        varTail = (*L).tail; // counter tetap
      } else {
        varTail = varTail->next; // pindahkan dulu

        delBefore(varTail, L); // my additionoal procedure
        addFirst(temp->elmt, L);

        varTail = varTail->prev; // iterasikan
      }
    } else {
      varTail = varTail->prev; // iterasi jika conditional tidak terpenuhi
    }
  }
}

/*
6
antares
lyra
atria
bellatrix
avior
equuleus
*/