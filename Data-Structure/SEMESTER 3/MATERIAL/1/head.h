#include <stdio.h>
#include <string.h>

typedef struct{
  char nim[10];
  char nama[50];
  char nilai[2];
} nilaiMatKul;

typedef struct{
  nilaiMatKul el;
  int next;
} container;

typedef struct{
  int first;
  container data[10];
} list;

// MACHINE
// initial
void createList (list *L);
// misc.
int countElement (list L);
int emptyElement (list L);
// add
void addFirst (char nim[], char nama[], char nilai[], list *L);
void addAfter (int prev, char nim[], char nama[], char nilai[], list *L);
void addLast(char nim[], char nama[], char nilai[], list *L);

void delFirst (list *L);
void delAfter (int prev, list *L);
void delLast (list *L);
void printElement (list L);
void delAll (list *L);