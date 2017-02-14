#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct smp *nodeAddress;
typedef struct smp {
  char info;
  nodeAddress right;
  nodeAddress left;
} node;

typedef struct {
  node *root;
} tree;

int countTree;
int countPre;
int countIn;
int countPost;

void makeTree(char fx, tree *T);
void addRight(char fx, node *root);
void addLeft(char fx, node *root);
void delRight(node *root);
void delLeft(node *root);
void printTreePreOrder(node *root);
void printTreeInOrder(node *root);
void printTreePostOrder(node *root);
void copyTree(node *root1, node **root2);
int isEqual(node *root1, node *root2);