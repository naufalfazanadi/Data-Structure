#include <stdio.h>
#include <string.h>

typedef struct{
  char nama[32];
  int stok;
  int harga;
} object; // main typedef

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
void addFirst (object fx, list *L);
void addAfter (int before, object fx, list *L);
void addLast (object fx, list *L);

// del
void delFirst (list *L);
void delAfter (int before, list *L);
void delLast (list *L);
void delAll (list *L);

 // OUTPUT
void printElement (list L);