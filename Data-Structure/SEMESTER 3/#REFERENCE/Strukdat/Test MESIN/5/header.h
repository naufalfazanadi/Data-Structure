/* List Of List */
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char nama[50];
}kata;

typedef struct {
	char word[10];
}huruf;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	huruf elmt;
	alamatekolom next;
}eKolom;

typedef struct ebr *alamatbaris;
typedef struct ebr{
	kata elmt;
	eKolom *col;
	alamatbaris next;

}eBaris;

typedef struct {
	eBaris *first;
}list;
