/* LIBRARY */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
  char nama[50];
  int TOEFL;
  int prio;
} object; // main struct

typedef struct elmt *address;
typedef struct elmt {
  object elmt;
  address next;
} elemen;

typedef struct{
  elemen *first;
  elemen *last;
} queue;

/* INIT */
void createQueue(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);

/* PROCESS */
void add(object fx, queue *Q);
void del(queue *Q);
// add prio
void addPriority(object fx, int prioritas, queue *Q);
void selectionTOEFL (queue *Q, queue *Q1, queue *Q2); // selection

/* OUTPUT */
void printQueue(queue Q);
void output(queue Q, queue Q1, queue Q2); // output

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi TP7 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/