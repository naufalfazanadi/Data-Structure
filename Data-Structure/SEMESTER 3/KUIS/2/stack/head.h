/* LIBRARY */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h> // for atoi

/* --- STACK --- */

// OBJECT
typedef struct {
  char skrip[50];
  int nilai;
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

/* PROCESS AND OUTPUT */
void processCommand(int n, stack *S);

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi Kuis 2 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/