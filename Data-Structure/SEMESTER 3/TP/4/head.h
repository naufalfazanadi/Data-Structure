/* --- LIST DINAMIS !!! --- */

#include <stdio.h>
#include <string.h>
#include <malloc.h> // lib memory

typedef struct {
  char nama[32];
  int konsonan;
  int vokal;
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
void delBefore (elemen *after, list *L); // additional from me
void delLast (list *L);
void delAll (list *L);

// PRINT
void printElement (list L);
void printToHead (list L); // reverse

// MY F(X)
void checkKonsoVokal (list *L); // check n konsonan n vokal
void reArrange (list *L); // procedure re-arrange list

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi TP4 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/
