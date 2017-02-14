#include <stdio.h>
#include <string.h>

/*
Saya Faisal Syaiful Anwar tidak melakukan kecurangan seperti yang telah dispesifikasikan
pada mata kuliah Strurktur Data dalam mengerjakan LISTUNGS, jika saya melakukan kecurangan
maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/

int n;

typedef struct{
	char tipe[50];
	char nama[50];
	char hp[50];
}data;

typedef struct{
	data elmt;
	int next;
}elemen;

typedef struct{
	int first;
	elemen data[100];
}list;

void createList(list *);
int countElement(list );
int emptyElement(list );
void addFirst(char [],char [],char [],list *);
void addAfter(int ,char [],char [],char [],list *);
void addLast(char [],char [],char [],list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElemen(list );
void delAll(list *);
void newLine();