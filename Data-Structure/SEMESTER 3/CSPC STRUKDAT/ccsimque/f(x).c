#include "head.h"

void createQueue(queue *Q) {
  // set to null
  (*Q).first = NULL;
  (*Q).last = NULL;
}

int isEmpty(queue Q) { // check empty queue
  int hasil = 0;
  if (Q.first == NULL) {
    hasil = 1;
  }
  return hasil;
}

int countElement(queue Q) { // count the queue
  int hasil = 0;

  if (Q.first != NULL) {
    elemen *var;
    var = Q.first;

    while (var != NULL) {
      hasil++; // count
      var = var->next; // iterate
    }
  }
  return hasil;
}

void add(object fx, queue *Q) {
  /* INIT */
  elemen *var;
  var = (elemen *) malloc (sizeof (elemen));

  // Move
  var->elmt = fx;
  var->next = NULL;

  if ((*Q).first == NULL) {
    (*Q).first = var;
  } else {
    (*Q).last->next = var;
  }

  (*Q).last = var;
  // set to null
  var = NULL;
}

void del(queue *Q) {
  if ((*Q).first != NULL) {
    if (countElement(*Q) == 1) { // del if just 1 elmt
      (*Q).first = NULL; // just set to null
      (*Q).last = NULL; // just set to null
    } else {
      elemen *var = (*Q).first;

      (*Q).first = (*Q).first->next; // move the first
      var->next = NULL; // delete..

      free(var);
    }
  }
}

void printQueue(queue Q) {
  if (Q.first != NULL) { // if not empty
    elemen *var = Q.first;

    while(var != NULL) { // loop all elmt
      printf("%d\n", var->elmt.num);

      var = var->next; // iterate
    }
  } else { // if empty
    // printf("Kosong!\n");
  }
  printf("-1\n");
}

void addPriority(object fx, int prioritas, queue *Q) {
  /* INIT NEW ELMT */
  elemen *baru;
  baru = (elemen *) malloc (sizeof (elemen));

  baru->elmt = fx;

  if (isEmpty(*Q)) { // if empty
    add(fx, Q); // just add
  } else {
    if (countElement(*Q) < prioritas) { // if priority so big
      add(fx, Q); // add last (just add)
    } else { // if priority in first or middle
      if (prioritas == 1) {
        // add first
        baru->next = (*Q).first;
        (*Q).first = baru;
      } else { // middle
        elemen *var = (*Q).first;

        int i = 1;

        // loop till the position
        while (var != NULL && i < prioritas-1) {
          i++;
          var = var->next; // iterate
        }

        // insert
        baru->next = var->next;
        var->next = baru;
      }
    }
  }
}
