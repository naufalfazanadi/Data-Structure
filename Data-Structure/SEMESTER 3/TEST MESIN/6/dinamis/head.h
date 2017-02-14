#include <stdio.h>
#include <malloc.h>
#include <string.h>

/* --- STACK --- */

// OBJECT
typedef struct {
  char nama[50];
} object;

typedef struct elemen *addressElement;
typedef struct elemen {
  object elmt;
  addressElement next;
} elemen;

typedef struct {
  elemen* top;
} stack;

// Funciton Procedure
void createStack(stack *S);
int isEmpty(stack S);
int countElement(stack S);

void pop(stack *S);
void push(object fx, stack *S);

void printStack(stack S);

