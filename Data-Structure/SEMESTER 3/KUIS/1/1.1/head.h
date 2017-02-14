#include <stdio.h> // library
#include <string.h> // library

typedef struct{
  int elmt; // input
  int next;
} container;

typedef struct{
  int first;
  container data[100];
} list;

// ----------------------------------

// ------- MESIN LIST -------
// INIT
void createList (list *L);
int countElement (list L);
int emptyElement (list L);

// ADD
void addFirst (int fx, list *L);
void addAfter (int prev, int fx, list *L);
void addLast(int fx, list *L);

// DEL
void delFirst (list *L);
void delAfter (int prev, list *L);
void delLast (list *L);
void delAll (list *L);

// OUTPUT
void printElement (list L);

// MY F(X)
void checkAndDel(int x, int y, list *L); // checking with the rang then del

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi KUIS 1 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
 */