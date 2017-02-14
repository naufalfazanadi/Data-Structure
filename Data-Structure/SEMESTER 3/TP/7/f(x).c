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
      printf("%s %d\n", var->elmt.nama, var->elmt.TOEFL);

      var = var->next; // iterate
    }
  } else { // if empty
    printf("Kosong!\n");
  }
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

void selectionTOEFL (queue *Q, queue *Q1, queue *Q2) {
  int bol = 1; // boolean

  elemen *var = (*Q).first;

  // loop till null and till false
  while (var != NULL && bol) {
    if (var->elmt.TOEFL >= 650 && countElement(*Q1) < 5) { // golongan 1
      add(var->elmt, Q1);
    } else if (var->elmt.TOEFL >= 500 && countElement(*Q2) < 5) { // golongan 2
      add(var->elmt, Q2);
    } else if (countElement(*Q1) == 5 && countElement(*Q2) == 5) { // if full...
      bol = 0; // set to false
    }

    if (bol) { // if true
      // delete and move the counter to first again
      del(Q);
      var = (*Q).first;
    }
  }
}

void output(queue Q, queue Q1, queue Q2) {
  printf("===Antrian Wawancara Golongan 1===\n");
  printQueue(Q1); // >= 650
  printf("===Antrian Wawancara Golongan 2===\n");
  printQueue(Q2); // >= 500
  printf("===Sisa Pendaftar===\n");
  printQueue(Q); // main queue
}

/*
13
A 500 4
B 500 4
C 500 3
D 500 5
E 500 0
F 650 1
G 650 1
H 650 2
I 650 2
J 650 0
K 250 1
L 250 0
M 250 0
*/