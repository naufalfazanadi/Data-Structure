#include <stdio.h>
#include <string.h>

#define MAX_STACK 3

typedef struct{
	char huruf;
}nilaiMatkul;

typedef struct{
	int top;
	nilaiMatkul data[MAX_STACK];	
}stack;

void createStack(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(char nim, stack *S);
void pop(stack *S);
nilaiMatkul getPop(stack *S);
void printStack(stack S);
