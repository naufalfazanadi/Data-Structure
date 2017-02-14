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
    eRow *var = L.first;

    while (var != NULL) {
      /* PROCESS */
      printf("%s\n", var->elmt.angkatan);

      eCol *var2 = var->col;
      while (var2 != NULL) {
        if (strcmp(var->elmt.angkatan,"undur diri") == 0) {
          printf("- %s %s %d\n", var2->elmt.nama, var2->elmt.angkatan, var2->elmt.sks);
        } else {
          printf("- %s %d\n", var2->elmt.nama, var2->elmt.sks);
        }

        var2 = var2->next; // iterate col
      }

      var = var->next; //iterate row
    }
  } else {
    /* JIKA LIST KOSONG */
    printf("list kosong\n");
  }
}

/* -------------------------------- MY FX -------------------------------- */
int checkAngkatan (objectRow fx, list *L) {
  eRow *var = (*L).first;

  int bol = 0;

  while (var != NULL) {
    if (strcmp(var->elmt.angkatan, fx.angkatan) == 0) {
      return 0;
    } else {
      bol = 1;
    }

    var = var->next;
  }

  if (bol == 1) {
    return 1;
  }
}

void checkAndAdd (objectRow fx, list *L) {
  int bol = 0;

  if ((*L).first == NULL) {
    addFirstB(fx, L);
  } else {
    eRow *var = (*L).first;
    eRow *prev = (*L).first;

    while (var != NULL && bol == 0 && checkAngkatan(fx, L) == 1) {
      if (strcmp(var->elmt.angkatan, fx.angkatan) != 0) {
        bol = 1;
        if (strcmp(var->elmt.angkatan, fx.angkatan) > 0) {
          if (var == (*L).first) {
            addFirstB(fx, L);
          } else {
            addAfterB(prev, fx);
          }
        } else {
          addAfterB(var, fx);
        }
      }

      prev = var;
      var = var->next;
    }
  }
}

void checkAndAddCol (objectCol fx, objectRow fx2, list *L) {
  eRow *var = (*L).first;

  int bol = 0;

  while (var != NULL && bol == 0) {
    if (strcmp(var->elmt.angkatan, fx2.angkatan) == 0) {
      bol = 1;
      addLastK(fx, var);
    }

    var = var->next;
  }
}

void addUndur (objectCol fx, list *L) {
  eRow *var = (*L).first;

  objectRow generation;
  strcpy(generation.angkatan, "undur diri");

  while (var->next != NULL) {
    var = var->next;
  }

  if (strcmp(var->elmt.angkatan,"undur diri") != 0) {
    addLastB(generation, L);
    var = var->next;
  }

  eCol *var2 = var->col;
  eCol *prev = var->col;

  if (var2 == NULL) {
    addFirstK(fx, var);
  }

  int bol = 0;

  while (var2 != NULL && bol == 0) {
    if (strcmp(var2->elmt.angkatan, fx.angkatan) > 0) {
      bol = 1;
      if (var == (*L).first) {
        addFirstK(fx, var);
      } else {
        addAfterK(prev, fx);
      }
    } else {
      bol = 1;
      addAfterK(prev, fx);
    }
    // addLastK(fx, var);
    prev = var2;
    var2 = var2->next;
  }
}

void moveUndur (char undurDiri[], list *L) {
  objectCol fx;

  int bol = 0;

  eRow *var = (*L).first;

  while (var != NULL && bol == 0) {
    eCol *var2 = var->col;
    eCol *prev2 = var->col;

    while (var2 != NULL && bol == 0) {
      if (strcmp(var2->elmt.nama, undurDiri) == 0) {
        bol = 1;

        fx = var2->elmt;
        strcpy(fx.angkatan, var->elmt.angkatan);

        if (var2 == var->col) {
          delFirstK(var);
          addUndur(fx, L);
        } else {
          delAfterK(prev2);
          addUndur(fx, L);
        }
      }

      prev2 = var2;
      var2 = var2->next; // iterate col
    }

    var = var->next; //iterate row
  }

  var = (*L).first;
  eRow *prev = (*L).first;

  while (var != NULL) {
    if (var->col == NULL) {
      if (var == (*L).first) {
        delFirstB(L);
      } else {
        delAfterB(prev);
      }
    }

    prev = var;
    var = var->next;
  }
}