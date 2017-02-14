#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
  char nim[10];
  char nama[50];
  float nilai;
} object;

typedef struct {
  int top;
  object elmt[MAX];
} stack;

void createStack(stack *S);
int isEmpty(stack S);
int isFull(stack S);

void push(object fx, stack *S);
void pop(stack *S);

void printStack(stack S);
