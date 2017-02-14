#include <stdio.h>
#include <malloc.h>
 
//container
typedef struct elemen *alamatElemen;
typedef struct elemen{
    int angka;
    alamatElemen next;
}elemen;
 
typedef struct {
  elemen* top;
}stack;


void createStack(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void popCari(int cari, stack *S);
void popIsi(stack *S, stack *S2);
void printStack(stack S);
void pop(stack *S);
void push(int angka, stack *S );
void pushOn(int cari, int angka, stack *S);
