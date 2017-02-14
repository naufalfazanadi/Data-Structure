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
      hasil++;
      var = var->next; // iterate
    }
  }
  return hasil;
}

void add(object fx, queue *Q) {
  elemen *var;
  var = (elemen *) malloc (sizeof (elemen));

  var->elmt = fx;
  var->next = NULL;

  if ((*Q).first == NULL) {
    (*Q).first = var;
  } else {
    (*Q).last->next = var;
  }

  (*Q).last = var;
  var = NULL;
}

void del(queue *Q) {
  if ((*Q).first != NULL) {
    if (countElement(*Q) == 1) {
      (*Q).first = NULL;
      (*Q).last = NULL;
    } else {
      elemen *var = (*Q).first;

      (*Q).first = (*Q).first->next;
      var->next = NULL;

      free(var);
    }
  }
}

void printQueue(queue Q) {
  printf("======\n");
  if (Q.first != NULL) {
    elemen *var = Q.first;
    int i = 1;
    while(var != NULL) {
      printf("%s\n", var->elmt.nama);

      var = var->next; // iterate
      i++;
    }
  } else {
    printf("Queue Kosong!\n");
  }
}

void addPriority(object fx,int prioritas, queue *Q) {
  elemen *baru;
  baru = (elemen *) malloc (sizeof (elemen));

  baru->elmt = fx;

  if (isEmpty(*Q)) {
    (*Q).first = baru;
    (*Q).last = baru;
    baru->next = NULL;
  } else {
    if (countElement(*Q) < prioritas) {
      (*Q).last->next = baru;
      (*Q).last = baru;
      baru->next = NULL;
    } else {
      if (prioritas == 1) {
        baru->next = (*Q).first;
        (*Q).first = baru;
      } else {
        elemen *var;
        var = (*Q).first;

        int i = 1;

        while (var != NULL && i < prioritas-1) {
          // printf(".");
          // prioritas--;
          i++;
          var = var->next; // iterate
        }

        baru->next = var->next;
        var->next = baru;
      }
    }
  }
}