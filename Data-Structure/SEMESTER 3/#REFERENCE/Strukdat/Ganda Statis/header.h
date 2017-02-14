#include<stdio.h>
#include<string.h>

int n;

typedef struct{
	char nim[15];
	char nama[10];
	char nilai[100];
}dataBank;

typedef struct{
	dataBank elmt;
	int next;
	int prev;
}elemen;

typedef struct{
	int first;
	int tail;
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