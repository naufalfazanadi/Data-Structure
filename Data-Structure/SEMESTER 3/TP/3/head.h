#include <stdio.h>
#include <string.h>

typedef struct{
  int nomor;
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

typedef struct {
  int max;
  int min;
} maxMin; // typedef max min

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
void printToHead (list L); // reverse

/* MY F(X) */
int check (char penyakit[], list *L); // check availability
void deleteObat (int validation, list *L); // deletion

void sorting (list *L); // sort (still bubble...)
maxMin checkMaxMin(list *L); // function to return max min + sort inside

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi TP3 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/