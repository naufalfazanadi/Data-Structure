//bismillah
/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan TP3, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */

#include<stdio.h>
#include<string.h>


typedef struct{
	char title[50];
	int price;
	int rating;
}dataBook;

typedef struct{
	dataBook elmt;
	int next;
	int prev;
}elemen;

typedef struct{
	int first;
	int tail;
	elemen data[100];
}list;

typedef struct{
	int number;
	int total;
}combine;

int n;
int counterF;
int temp;
combine combineBook;

void createList(list *);
int countElement(list );
int emptyElement(list );
void addFirst(char title[],int price, int rating, list *L);
void addAfter(int prev,char title[],int price, int rating,list *L);
void addLast(char title[],int price, int rating,list *L);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElement(list );
void delAll(list *);
void nextPrior(int from, int rate,list L);