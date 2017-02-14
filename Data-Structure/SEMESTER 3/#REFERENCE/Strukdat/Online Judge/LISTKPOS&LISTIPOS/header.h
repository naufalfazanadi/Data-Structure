#include<stdio.h>
#include<string.h>

typedef struct{
	int huruf;
	int move;
}problem;

typedef struct{
	int isi;
	int next;
}elemen;

typedef struct{
	int first;
	elemen data[100];
}list;

int n;

void createList(list *);
int countElement(list );
int emptyElement(list );
void addFirst(int ,list *);
void addAfter(int ,int ,list *);
void addLast(int ,list *);
void printElement(list );
void delAll(list *);
void replaceIt(int ,int ,list *);