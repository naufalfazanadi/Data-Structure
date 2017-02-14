/* LIST OF LIST !!! */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

/* MAIN TYPEDEF STRUCT */
typedef struct {
  char angkatan[16];
} objectRow;

typedef struct {
  char nama[32];
  char angkatan[16];
  int sks;
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

// MY FX
int checkAngkatan (objectRow fx, list *L);
void checkAndAdd (objectRow fx, list *L);
void checkAndAddCol (objectCol fx, objectRow fx2, list *L);
void addUndur (objectCol fx, list *L);
void moveUndur (char undurDiri[], list *L);


/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi UTS dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/