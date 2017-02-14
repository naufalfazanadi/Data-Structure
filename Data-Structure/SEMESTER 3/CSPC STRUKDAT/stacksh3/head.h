/* LIBRARY */
#include <stdio.h>
#include <malloc.h>
#include <string.h>

/* --- STACK --- */

// OBJECT
typedef struct {
  int num;
} object;

typedef struct elemen *addressElement;
typedef struct elemen {
  object data;
  addressElement next;
} elemen;

typedef struct {
  elemen* top;
} stack;

/* Funciton Procedure */
// Init
void createStack(stack *S);
int isEmpty(stack S);
int countElement(stack S);

// Process
void pop(stack *S);
void push(object fx, stack *S);

// Output
void printStack(stack S);
