/* TP 5 STRUKDAT */
/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan TP5 STRUKDAT,
 jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

//struct big element.
typedef struct {
	char category[500];
	char name[500];
}participant;

//Struct small element
typedef struct{
	char aspect[50];
	int score;
}form;

typedef struct eklm *alamatekolom;
typedef struct eklm{
	form elmt;
	alamatekolom next;
}eKolom;

typedef struct ebr *alamatbaris;
typedef struct ebr{
	participant elmt;
	eKolom *col;
	alamatbaris next;

}eBaris;

typedef struct {
	eBaris *first;
}list;

/* Global Declaration */

eBaris* isAvail(char [], list );
eKolom* isExist(char [],eBaris* );
eKolom* getPrev(char aspect[], eBaris* L);
int getScore(char aspect[],eBaris *L);
void printRanking(list L);
