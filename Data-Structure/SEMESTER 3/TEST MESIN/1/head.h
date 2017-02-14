#include <stdio.h>
#include <string.h>

// TYPEDEF
typedef struct{
  char nama[50];
  int umur;
  char jk;
} object;

typedef struct{
  object el;
  int next;
} container;

typedef struct{
  int first;
  container data[10];
} list;

// ----------------------------------

void createList (list *L);
int countElement (list L);
int emptyElement (list L);

void addFirst (object fx, list *L);
void addAfter (int prev, object fx, list *L);
void addLast(object fx, list *L);

void delFirst (list *L);
void delAfter (int prev, list *L);
void delLast (list *L);
void delAll (list *L);

void printElement (list L);