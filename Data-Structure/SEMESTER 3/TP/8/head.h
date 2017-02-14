/* LIBRARY */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* MAIN STRUCT */
typedef struct {
  char nama[32];
  int amal;
} object;

/* --- TREE --- */
typedef struct smp *nodeAddress;
typedef struct smp {
  object info;
  nodeAddress right;
  nodeAddress left;
} node;

typedef struct {
  node *root;
} tree;

/* --- STACK --- */
typedef struct elemen *addressElement;
typedef struct elemen {
  object elmt;
  addressElement next;
} elemen;

typedef struct {
  elemen* top;
} stack;

/* GLOBAL VARIABLE */
int countTree;
int bol;
int bolRoot;

/* TREE FUNCTION PROCEDURE */
void makeTree(object fx, tree *T);
void addRight(object fx, node *root);
void addLeft(object fx, node *root);
void delRight(node *root);
void delLeft(node *root);
void printTreePreOrder(node *root);

/* STACK FUNTION PROCEDURE */
void createStack(stack *S);
void emptyStack(stack *S);
int isEmpty(stack S);
int countElement(stack S);

void pop(stack *S);
void push(object fx, stack *S);
void printStack(stack S);

// MY F(X)

object fillPerson(char nama[], int amal); // to fill the tree
void findNode(char nama[], node *root, stack *S, tree *T); // find the node
void findRoot(node *child, stack *S, node *root); // find the root

// int getLevelUtil(node *root, char nama[], int level);
// int getLevel(node *root, char nama[]);

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi TP8 dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/