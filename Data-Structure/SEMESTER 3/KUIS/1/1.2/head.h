/* --- LIST DINAMIS !!! --- */

#include <stdio.h>
#include <string.h>
#include <malloc.h> // lib memory

typedef struct elmt *address;

typedef struct elmt {
  int elmt; // inputan
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
void addFirst (int fx, list *L);
void addAfter (elemen *before, int fx, list *L);
void addLast (int fx, list *L);

// DELETE
void delFirst (list *L);
void delAfter (elemen *before, list *L);
void delBefore (elemen *after, list *L); // additional from me
void delLast (list *L);
void delAll (list *L);

// PRINT
void printElement (list L);
void printToHead (list L); // reverse

// MY F(X)
void addFirstBelakang (int fx, list *L); // modified add first
void changeAndOut (list *L); // process and output

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi KUIS 1 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/
