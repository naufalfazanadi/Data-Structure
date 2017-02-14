#include<stdio.h>
#include<malloc.h>
#include<string.h>
/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan Testmesin, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */

// int n;
typedef struct{
	char nim[20];
	char nama[60];
	int gaji;
}nilaiMatKul;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	nilaiMatKul elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
}list;
void createList(list *L);
int countElement(list L);
void addFirst(char [],char [],int ,list *);
void addAfter(elemen *prev,char nim[],char nama[],int ,list *L);
void addLast(char nim[],char nama[],int ,list *L);
void delFirst(list *L);
void delAfter(elemen *prev,list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);