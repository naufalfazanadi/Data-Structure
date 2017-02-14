/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan Evaluasi, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */

#include<stdio.h>
#include<malloc.h>
#include<string.h>


typedef struct elmt *alamatelmt;
typedef struct elmt{
	char nama[250];
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
}list;
// global function and procedure
void createList(list *L);
int countElement(list L);
void addFirst(char depan[],list *L);
void addAfter(elemen *prev,char depan[],list *L);
void addLast(char depan[],list *L);
void delFirst(list *L);
void delAfter(elemen *prev,list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void check(list L);
int isNumber(char string[]);