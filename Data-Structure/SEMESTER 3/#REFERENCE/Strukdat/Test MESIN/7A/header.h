#include<stdio.h>
#include<string.h>

#define MAX_QYU 3
typedef struct{
	char nama[50];
}nilaiMatkul;


typedef struct{
	int first;
	int last;
	nilaiMatkul data[MAX_QYU];
}queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void add(char nama[],queue *Q);
void del(queue *Q);
void printQueue(queue Q);
void addPriority(char nama[],int prioritas,queue *Q);