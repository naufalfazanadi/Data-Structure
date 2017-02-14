#include "head.h"

void createEmpty(queue *Q) {
  (*Q).first = -1;
  (*Q).last = -1;
}

int isEmpty(queue Q) {
  int hasil = 0;

  if(Q.first == -1) {
    hasil = 1;
  }

  return hasil;
}

int isFull(queue Q) {
  int hasil = 0;

  if (Q.last == (MAX - 1)) {
    hasil = 1;
  }

  return hasil;
}

void add(object fx,queue *Q) {
  if (isEmpty(*Q) == 1) { // if queue empty
    (*Q).first = 0;
    (*Q).last = 0;
    (*Q).elmt[0] = fx; // add the elmt
  } else {
    if (isFull(*Q) != 1) {
      // add from last
      (*Q).last = (*Q).last + 1;
      (*Q).elmt[(*Q).last] = fx; // add the elmt in at last
    } else {
      // full
      printf("Queue penuh!\n");
    }
  }
}

void del(queue *Q) {
  if ((*Q).last == 0) { // if last in the first
    // set to null
    (*Q).first = -1;
    (*Q).last = -1;
  } else {
    int i;
    // Geserrr
    for (i = ((*Q).first +1); i <= (*Q).last; i++) {
      (*Q).elmt[i-1] = (*Q).elmt[i];
    }
    // last set to null
    (*Q).last = (*Q).last - 1;
  }
}

void printQueue(queue Q) {
  if (Q.first != -1) {
    int i;
    for (i = Q.first; i <= Q.last; i++){
      printf("%s\n", Q.elmt[i].nama);
    }
  } else {
    printf("Queue Kosong!\n");
  }
}

void addPriority(object fx,int prioritas,queue *Q) {
  if (isEmpty(*Q) == 1) {
    (*Q).first = 0;
    (*Q).last = 0;
    (*Q).elmt[0] = fx;
  } else {
    if ((*Q).last+1 < prioritas) {
      (*Q).last += 1;
      (*Q).elmt[(*Q).last] = fx; // add the elmt in at last
    } else {
      prioritas -= 1;
      int i;
      (*Q).last+=1;
      for (i = (*Q).last; i > prioritas; i--) {
        (*Q).elmt[i] = (*Q).elmt[i-1];
      }
      (*Q).elmt[i] = fx;
    }
  }
}
