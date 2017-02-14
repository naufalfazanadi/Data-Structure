#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	int angka;
}nilaiMatkul;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	nilaiMatkul elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen* top;
}stack;

void createStack(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(int angka,stack *S);
void pop(stack *S);
elemen* getPop(stack *S);
void popIsi(stack *S1,stack *S2);