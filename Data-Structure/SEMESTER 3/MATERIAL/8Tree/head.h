#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct {
  char ch;
} object;

typedef struct smp *nodeAddress;
typedef struct smp {
  object info;
  nodeAddress right;
  nodeAddress left;
} node;

typedef struct {
  node *parent;
} tree;

void makeTree(object fx, tree *T);
void addRight(object fx, node *parent);
void addLeft(object fx, node *parent);
void delRight(node *parent);
void delLeft(node *parent);
void printTreePostOrder(node *parent);
void copyTree(node *parent1, node *parent2);
int isEqual(node *parent1, node *parent2);