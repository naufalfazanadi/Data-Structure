#include "head.h"

void createList (list *L) {
  (*L).first = NULL;
}

/* COUNT LIST BIASA NYA (ROW) */
int countElementB (list L) {
  int hasil = 0;

  if (L.first != NULL) {
    /* list tidak kosong */

    eRow *elmt;

    /* inisialisasi */
    elmt = L.first;

    while (elmt != NULL) {
      hasil++;
      elmt = elmt->next;
    }
  }

  return hasil;
}

int countElementK (eRow L) {
  int hasil = 0;

  if (L.col != NULL) {
    /* list tidak kosong */

    eCol *elmt;

    /* init */
    elmt = L.col;

    while (elmt != NULL) {
      /*process*/
      hasil++;
      elmt = elmt->next;
    }
  }

  return hasil;
}

void addFirstB (objectRow fx, list *L) {
  eRow *var;
  var = (eRow *) malloc (sizeof (eRow)); // locate the memory

  var->elmt = fx; // pemindahan
  var->col = NULL; // init the col to NULL

  if ((*L).first == NULL) { // jika kosong
    var->next = NULL;
  } else { // jika ada sebelumnya
    var->next = (*L).first;
  }

  (*L).first = var;
  var = NULL;
}

void addFirstK (objectCol fx, eRow *L) {
  eCol *var;
  var = (eCol *) malloc (sizeof (eCol)); // locate the memory

  var->elmt = fx; // pemindahan

  if ((*L).col == NULL) { // jika kosong
    var->next = NULL;
  } else { // jika ada sebelumnya
    var->next = (*L).col;
  }

  (*L).col = var;
  var = NULL;
}

void addAfterB (eRow *prev, objectRow fx) {
  eRow *var;
  var = (eRow *) malloc (sizeof (eRow));

  var->elmt = fx;
  var->col = NULL;

  if (prev->next == NULL) {
    var->next = NULL;
  } else {
    var->next = prev->next;
  }

  prev->next = var;
  var = NULL;
}

void addAfterK (eCol *prev, objectCol fx) {
  eCol *var;
  var = (eCol *) malloc (sizeof (eCol));

  var->elmt = fx;

  if (prev->next == NULL) {
    var->next = NULL;
  } else {
    var->next = prev->next;
  }

  prev->next = var;
  var = NULL;
}

void addLastB (objectRow fx, list *L) {
  if ((*L).first == NULL) {
    addFirstB(fx, L);
  } else {
    /* jika list tidak kosong mencari elemen terakhir list */
    eRow *prev = (*L).first;
    while(prev->next != NULL){
      /*iterasi*/
      prev = prev->next;
    }

    addAfterB (prev, fx);
  }
}

void addLastK (objectCol fx, eRow *L) {
  if ((*L).col == NULL) {
    addFirstK(fx, L);
  } else {
    /* jika list tidak kosong mencari elemen terakhir list */
    eCol *prev = (*L).col;
    while(prev->next != NULL){
      /*iterasi*/
      prev = prev->next;
    }

    addAfterK (prev, fx);
  }
}

void delAllB (list *L) {
  if (countElementB(*L) != 0) {
    int i;
    for (i = countElementB(*L); i >= 1; i--) {
      /* PROCESS HAPUS */
      delLastB(L);
    }
  }
}

void delAllK (eRow *L) {
  if (countElementK(*L) != 0) {
    int i;
    for (i = countElementK(*L); i >= 1; i--) {
      /* PROCESS HAPUS */
      delLastK(L);
    }
  }
}

void delFirstB (list *L) {
  if ((*L).first != NULL) {
    /* jika list bukan list kosong */
    eRow *var = (*L).first;

    /* DEL ALL DULU */
    delAllK(var);

    if (countElementB(*L) == 1) {
      (*L).first = NULL;
    } else {
      (*L).first = (*L).first->next;
      var->next = NULL;
    }

    free(var);
  }
}

void delFirstK (eRow *L) {
  if ((*L).col != NULL) {
    /* jika list bukan list kosong */
    eCol *var = (*L).col;

    if (countElementK(*L) == 1) {
      (*L).col = NULL;
    } else {
      (*L).col = (*L).col->next;
      var->next = NULL;
    }

    free(var);
  }
}

void delAfterB (eRow *prev) {
  eRow *var = prev->next;

  /* DEL ALL DULU */
  delAllK(var);

  if (var->next == NULL) {
    prev->next = NULL;
  } else {
    prev->next = var->next;
    var->next = NULL;
  }

  free(var);
}

void delAfterK (eCol *prev) {
  eCol *var = prev->next;

  if (var->next == NULL) {
    prev->next = NULL;
  } else {
    prev->next = var->next;
    var->next = NULL;
  }

  free(var);
}

void delLastB (list *L) {
  if ((*L).first != NULL) {
    if (countElementB(*L) == 1) {
      delFirstB(L);
    } else {
      /* jika list tidak kosong mencari elemen terakhir list */
      eRow *last = (*L).first;
      eRow *beforeLast;

      while (last->next != NULL) {
        /* iterasi */
        beforeLast = last;
        last = last->next;
      }

      beforeLast->next = NULL;
      free(last);
    }
  }
}

void delLastK (eRow *L) {
  if ((*L).col != NULL) {
    if (countElementK(*L) == 1) {
      delFirstK(L);
    } else {
      /* jika list tidak kosong mencari elemen terakhir list */
      eCol *last = (*L).col;
      eCol *beforeLast;

      while (last->next != NULL) {
        /* iterasi */
        beforeLast = last;
        last = last->next;
      }

      beforeLast->next = NULL;
      free(last);
    }
  }
}

void printElement (list L) {
  if (L.first != NULL) {
    /* init */
    int i = 0;

    eRow *var = L.first;

    while (var != NULL && i < 2) {
      /* PROCESS */
      printf("%d. %s\n", i+1, var->elmt.nama);

      // eCol *var2 = var->col;
      // while (var2 != NULL) {
      //   printf("%d %.2f\n", var2->elmt.vote, var2->elmt.rate);

      //   var2 = var2->next; // iterate col
      // }

      i++; // iterate urutan
      var = var->next; //iterate row
    }
  } else {
    /* JIKA LIST KOSONG */
    printf("list kosong\n");
  }
}

/* MY F(X) */
int convert(char str) { // convert the char to int
  switch(str) {
    case '0': return 0; break;
    case '1': return 1; break;
    case '2': return 2; break;
    case '3': return 3; break;
    case '4': return 4; break;
    case '5': return 5; break;
  }
}

void update(char str1[], char str2[], char str3[], list *L) {
  eRow *var = (*L).first; // for access the list
  int bol = 0; // boolean set to FALSE FOR INIT

  if (strcmp(str1,"VOTE") == 0) {
    while (var != NULL && bol == 0) {
      if (strcmp(str3,var->elmt.nama) == 0) {
        bol = 1; // TRUE
        var->col->elmt.vote++; // iterate vote
      }

      var = var->next; // iterate counter
    }
  } else if (strcmp(str1,"RATE") == 0) {
    while (var != NULL && bol == 0) {
      if (strcmp(str2,var->elmt.nama) == 0) {
        bol = 1; // TRUE
        if (var->col->elmt.rate == 0) { // if the first rate. . .
          var->col->elmt.rate += convert(str3[0]);
        } else { // if not the first
          var->col->elmt.rate += convert(str3[0]); // sum
          var->col->elmt.rate /= 2; // divide
        }
      }

      var = var->next; // iterate counter
    }
  }
}

void sort(list *L) { // bubble sort
  if ((*L).first != NULL) {

    int flip;
    int bol;
    int iterate; // penanda untuk loop ke satu atau bukan

    eRow *counter;
    eRow *tempPrev /* pointer yang prev */, *tempNext /* pointer yang next */;

    eRow *prev; // counter previous

    do { // loop hingga tidak ada penukaran
      flip = 0;
      counter = (*L).first; // init

      prev = (*L).first; // init prev

      iterate = 0;
      while (counter->next != NULL) { // loop sebelum null

        bol = 0; // boolean untuk ke switch atau tidak
        if (((counter->col->elmt.vote < counter->next->col->elmt.vote) ||
           (counter->col->elmt.vote == counter->next->col->elmt.vote &&
            counter->col->elmt.rate < counter->next->col->elmt.rate)) &&
            (counter->next != NULL)) { // jika counter > dari next nya
          bol = 1; // true

          /* --- SWITCHING !!! --- */

          // TEMPORARY VAR
          tempNext = counter->next->next;

          if (iterate == 0) { // Ubah next dari prev
            // TEMPORARY VAR
            tempPrev = (*L).first;
            (*L).first = counter->next;
          } else {
            // TEMPORARY VAR
            tempPrev = prev->next;
            prev->next = counter->next;
          }

          counter->next->next = tempPrev;
          counter->next = tempNext;

          flip = 1;
        }
        if (bol == 0) { /* kalau tdk ada yang ditukar maka iterasi normal */
          prev = counter;
          counter = counter->next; // iterasi
        } else { /* kalau ada yang ditukar maka iterasi dari prev */
          counter = prev->next; // iterasi
        }
      }
      iterate = 1; // kalau 1 maka bukan loop pertama
    } while(flip == 1);
  }
}