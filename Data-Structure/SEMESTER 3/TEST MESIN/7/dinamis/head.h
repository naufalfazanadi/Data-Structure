#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
  char nama[50];
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

/* OUTPUT */
void printQueue(queue Q);
