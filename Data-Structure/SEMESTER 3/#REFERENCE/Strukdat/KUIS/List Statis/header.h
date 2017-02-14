#include<stdio.h>
#include<string.h>
/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan KUIS1, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */
int n;

typedef struct{
	char word[200];
	int next;
}elemen;

typedef struct{
	int first;
	elemen data[200];
}list;

void createList(list *);
int countElement(list );
int emptyElement(list );
void addFirst(char [],list *);
void addAfter(int ,char [],list *);
void addLast(char [],list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElement(list );
void delAll(list *);
void isVocal(list L);