#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char nim[10];
	char nama[50];
}mahasiswa; // isi elemen List Besar

typedef struct{
	char kode[10];
	char nilai[3];
}matKul; // isi elemen List Kecil

typedef struct eK *alamatK;
typedef struct eK{
	matKul elmt;
	alamatK next;
}eKolom; // list Kecil

typedef struct eB *alamatB;
typedef struct eB{
	mahasiswa elmt;
	eKolom *col; // pointer yang menjadi Head List Kecil
	alamatB next;
}eBaris; // List Besar

typedef struct{
	eBaris *first; // pointer yang menjadi Head List Besar
}list; // List of List

void createList(list *L);
int countElemenB(list L);
int countElemenK(eBaris L);
void addFirstB(char nim[],char nama[],list *L);
void addFirstK(char kode[],char nilai[],eBaris *L);
void addAfterB(eBaris *prev,char nim[],char nama[]);
void addAfterK(eKolom *prev,char kode[],char nilai[]);
void addLastB(char nim[],char nama[],list *L);
void addLastK(char kode[],char nilai[],eBaris *L);
void delFirstB(list *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delLastK(eBaris *L);
void printElemen(list L);