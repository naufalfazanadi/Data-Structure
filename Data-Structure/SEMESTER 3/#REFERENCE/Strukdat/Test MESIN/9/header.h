#include <stdio.h>
#include <string.h>
#include <malloc.h>
/* Pointer Struct */
typedef struct smp *alamatsimpul;
typedef struct smp{
	char name;
	alamatsimpul sibling;
	alamatsimpul child;
}simpul;

typedef struct{
	simpul* root;
}tree;

void makeTree(char name, tree *T);
void addChild(char name, simpul *root);
void delChild(char name, simpul *root);
simpul* findSimpul(char name, simpul *root);
void printTreePreOrder(simpul *root);

int count;