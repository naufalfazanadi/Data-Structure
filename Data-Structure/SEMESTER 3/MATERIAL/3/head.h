#include <stdio.h>
#include <string.h>

typedef struct{
  char nim[10];
  char nama[50];
  char nilai[2];
} object;

typedef struct{
  object elmt;
  int prev;
  int next;
} elemen;

typedef struct{
  int first;
  int tail;
  elemen data[10];
} list;

// MACHINE
// init
void createList (list *L);
// misc.
int countElement (list L);
int emptyElement (list L);

// add
void addFirst (char nim[], char nama[], char nilai[], list *L);
void addAfter (int before, char nim[], char nama[], char nilai[], list *L);
void addLast (char nim[], char nama[], char nilai[], list *L);

// del
void delFirst (list *L);
void delAfter (int before, list *L);
void delLast (list *L);
void delAll (list *L);

void printElement (list L);