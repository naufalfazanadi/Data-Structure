#include<stdio.h>
#include<string.h>

int n;

typedef struct{
	char nama[15];
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
void addFirst(char [],char [],char [],list *);
void addAfter(int ,char [],char [],char [],list *);
void addLast(char [],char [],char [],list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElement(list );
void delAll(list *);