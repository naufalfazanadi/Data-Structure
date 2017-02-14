#include <stdio.h>
#include <malloc.h>

/* N-er TREE */
typedef struct smp *nodeAddress;
typedef struct smp{
  char info;
  nodeAddress sibling;
  nodeAddress child;
} node;

typedef struct{
  node *parent;
} tree;

/* Proc And Func */
void makeTree(char c, tree *T);
void addChild(char c, node *parent);
void delChild(char c, node *parent);
void printTreePreOrder(node *parent);
void printTreePostOrder(node *parent);
void copyTree(node *parent1, node **parent2);
int isEqual(node *parent1, node *parent2);

node *findNode(char c, node *parent);