#include<stdio.h>
#include<malloc.h>
#include<string.h>

// int n;
typedef struct{
	char nim[10];
	char nama[50];
	char nilai[2];
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
void addFirst(char [],char [],char [],list *);
void addAfter(elemen *prev,char nim[],char nama[],char nilai[],list *L);
void addLast(char nim[],char nama[],char nilai[],list *L);
void delFirst(list *L);
void delAfter(elemen *prev,list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);