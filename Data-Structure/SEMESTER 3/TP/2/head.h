 /* --- LIST DINAMIS !!! --- */

#include <stdio.h>
#include <string.h>
#include <malloc.h> // lib memory
// #include <time.h> // wait <--- for checking. . .

typedef struct {
  char signal[64];
  int validation;
  char realCode[64];
} object; // main typedef

typedef struct elmt *address;

typedef struct elmt {
  object elmt;
  address next;
} elemen;

typedef struct {
  elemen *first;
} list;

/* --- MESIN LIST DINAMIS (MEMORIES~) --- */
// INIT
void createList (list *L);
int countElement (list L);

// ADD
void addFirst (object fx, list *L);
void addAfter (elemen *prev, object fx, list *L);
void addLast (object fx, list *L);

// DELETE
void delFirst (list *L);
void delAfter (elemen *prev, list *L);
void delLast (list *L);
void delAll (list *L);

// PRINT
void printElement (int menu, list L);


// MY F(X)
/*void wait(float x);*/
object checkCode (object fx);
int filter (list *L);
void sorting(list *L);
// void selection_sort (list *L);

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi TP2 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/
