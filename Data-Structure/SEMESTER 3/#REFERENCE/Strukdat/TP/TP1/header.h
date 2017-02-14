#include<stdio.h>
#include<string.h>


/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan TP1, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */

int n;

typedef struct{
	char nama[50];
	char rekening[10];
	int saldo;
}dataBank;

typedef struct{
	dataBank elmt;
	int next;
}elemen;

typedef struct{
	int first;
	elemen data[100];
}list;


void createList(list *);
int countElement(list );
int emptyElement(list );
void addFirst(char [],char [],int ,list *);
void addAfter(int ,char [],char [],int ,list *);
void addLast(char [],char [],int ,list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElement(list );
void bonusManager(char [],list *);
int bonusCheck(char ,char ,char ,char );