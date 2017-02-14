/* List Of List */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct {
	char nama[100];
	int sks;
}mahasiswa;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	char matkul[100];
	alamatekolom next;
}eKolom;

typedef struct ebr *alamatbaris;
typedef struct ebr{
	mahasiswa elmt;
	eKolom *col;
	alamatbaris next;

}eBaris;

typedef struct {
	eBaris *first;
}list;
