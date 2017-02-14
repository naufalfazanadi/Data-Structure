#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
  char nama[50];
} object;

typedef struct elmt *address;
typedef struct elmt {
  object elmt;
  address next;
} elemen;

typedef struct{
  elemen *first;
  elemen *last;
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);

void add(object fx, queue *Q);
void del(queue *Q);

void printQueue(queue Q);

void addPriority(object fx, int prioritas, queue *Q);