/* LIBRARY */
#include <stdio.h>
#include <malloc.h>
#include <string.h>

/* --- STACK --- */

// OBJECT
typedef struct {
  char nama[50];
  int waktu;
  int profit;
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
void setNULL (object fx, stack *S); // set the value of object to -1

void moveAndPrint(stack *S1, stack *S2); // move the project and print

// Output
void printStack(stack S);



/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi TP6 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/