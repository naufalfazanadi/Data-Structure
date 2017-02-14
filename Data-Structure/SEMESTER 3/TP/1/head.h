#include <stdio.h> // library
#include <string.h> // library

// TYPEDEF LIST
typedef struct{
  char word[50];
  int same;
} object;

typedef struct{
  object el;
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
void addFirst (object fx, list *L);
void addAfter (int prev, object fx, list *L);
void addLast(object fx, list *L);

// OUTPUT
void printElement (list L);

// MY F(X)
void compareWord (list *L, char lia[]); // perbandingan
void sorting (list *L); // sorting (bubble)

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi TP1 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
 */