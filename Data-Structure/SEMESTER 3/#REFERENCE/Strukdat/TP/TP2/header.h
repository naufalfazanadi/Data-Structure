/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan TP2, 
jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */
/* Tugas Praktikum 2 2015 
by Faisal SA
*/
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct elmt *alamatelmt;
typedef struct elmt{
	char word[50];
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
}list;


void createList(list *L);
int countElement(list L);
void addFirst(char kata[],list *L);
void addAfter(elemen *prev,char kata[],list *L);
void addLast(char kata[],list *L);
void delFirst(list *L);
void delAfter(elemen *prev,list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void selectionSort (list *L);
elemen *searchData(char find[],list L);
void delSearch(char word[],list *L);
void addWordBetween(char req[],char newWord[],list *L);