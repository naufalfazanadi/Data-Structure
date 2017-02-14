/* --- LIST DINAMIS !!! --- */

#include <stdio.h>
#include <string.h>
#include <malloc.h> // lib memory

typedef struct {
  char nim[10];
  char nama[50];
  char nilai[2];
} object; // main typedef

typedef struct elmt *address;

typedef struct elmt {
  object elmt;
  address prev;
  address next;
} elemen;

typedef struct {
  elemen *first;
  elemen *tail;
} list;

/* --- MESIN LIST DINAMIS (MEMORIES~) --- */
// INIT
void createList (list *L);
int countElement (list L);

// ADD
void addFirst (object fx, list *L);
void addAfter (elemen *before, object fx, list *L);
void addLast (object fx, list *L);

// DELETE
void delFirst (list *L);
void delAfter (elemen *before, list *L);
void delLast (list *L);
void delAll (list *L);

// PRINT
void printElement (list L);