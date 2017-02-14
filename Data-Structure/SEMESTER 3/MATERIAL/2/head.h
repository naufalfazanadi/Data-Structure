/* --- LIST DINAMIS !!! --- */

#include <stdio.h>
#include <string.h>
#include <malloc.h> // lib memory

typedef struct {
  char nim[10];
  char nama[50];
  char nilai[2];
} object;

typedef struct elmt *address;

typedef struct elmt {
  object elmt;
  address next;
} elemen;

typedef struct {
  elemen *first;
} list;

/* --- MESIN LIST DINAMIS (MEMORIES~) --- */
void createList (list *L);
int countElement (list L);

void addFirst (char nim[], char nama[], char nilai[], list *L);
void addAfter (elemen *prev, char nim[], char nama[], char nilai[], list *L);
void addLast (char nim[], char nama[], char nilai[], list *L);

void delFirst (list *L);
void delAfter (elemen *prev, list *L);
void delLast (list *L);
void delAll (list *L);

void printElement (list L);