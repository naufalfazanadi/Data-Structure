/* LOOOOOOOLLL :V */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

/**
 * STRUCT FOR ROW AND COL
 */
typedef struct {
  int num;
} objectRow;

typedef struct {
  char str[32];
} objectCol;
/* ------------------- */

typedef struct eKolom *addressColumn;
typedef struct eKolom {
  objectCol elmt;
  addressColumn next;
} eCol;

typedef struct eBaris *addressRow;
typedef struct eBaris {
  objectRow elmt;
  eCol *col;
  addressRow next;
} eRow;

typedef struct {
  eRow *first;
} list;

/* -------------------- MESIN LIST -------------------- */
void createList (list *L); // init

// COUNT
int countElementB (list L);
int countElementK (eRow L);

// ADD
void addFirstB (objectRow fx, list *L);
void addFirstK (objectCol fx, eRow *L);
void addAfterB (eRow *prev, objectRow fx);
void addAfterK (eCol *prev, objectCol fx);
void addLastB (objectRow fx, list *L);
void addLastK (objectCol fx, eRow *L);

// DELETE
void delAllB (list *L);
void delAllK (eRow *L);
void delFirstB (list *L);
void delFirstK (eRow *L);
void delAfterB (eRow *prev);
void delAfterK (eCol *prev);
void delLastB (list *L);
void delLastK (eRow *L);

// OUTPUT
void printElement (list L);

// MY PROC FUNC
int getCountVokal(char str[]); // get the count of vokal
objectCol getStr(char str[]); // func to get the str of vokal
int cekRow(int find, list L); // check availability of row

void addToLol(char str[], list *L); // Adding to List Of List

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi REMEDIAL dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/