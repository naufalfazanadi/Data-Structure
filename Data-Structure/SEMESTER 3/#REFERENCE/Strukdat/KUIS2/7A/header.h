#include<stdio.h>
#include<string.h>

typedef struct{
	float numb;
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