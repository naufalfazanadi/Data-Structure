#include <stdio.h>
#include <string.h>

// define the max length of queue
#define MAX 5

typedef struct{
  char nama[50];
} object;

typedef struct{
  int first;
  int last;
  object elmt[MAX];
} queue;

/* INIT */
void createQueue(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);

/* PROCESSING */
void add(object fx,queue *Q);
void del(queue *Q);

/* OUTPUT */
void printQueue(queue Q);

void addPriority(object fx,int prioritas,queue *Q);