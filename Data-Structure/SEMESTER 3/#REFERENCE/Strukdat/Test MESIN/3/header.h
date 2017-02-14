#include<stdio.h>
#include<string.h>

int n;

typedef struct{
	char kode[15];
	char nama[15];
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
void addFirst(char [],char [],list *);
void addAfter(int ,char [],char [],list *);
void addLast(char [],char [],list *);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElement(list );
void delAll(list *);
void printElementToHead(list L);