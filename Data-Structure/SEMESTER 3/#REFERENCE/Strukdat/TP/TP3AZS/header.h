#include<stdio.h>
#include<string.h>

int n;
int total;
char nextC[100];
typedef struct{
	char city[15];
	int value;
}dataCity;

typedef struct{
	dataCity elmt;
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
void addFirst(char city[],int value,list *L);
void addAfter(int prev,char city[],int value,list *L);
void addLast(char city[],int value,list *L);
void delFirst(list *);
void delAfter(int ,list *);
void delLast(list *);
void printElement(list );
void delAll(list *);