#include <stdio.h>
#include <string.h>
#include <malloc.h>

int bol; // boolean
int countDaun;

// main struct
typedef struct {
  char nama;
  int num1;
  int num2;
} object;

typedef struct smp *nodeAddress;
typedef struct smp {
  object info;
  nodeAddress right;
  nodeAddress left;
} node;

typedef struct {
  node *root;
} tree;

/* ---------------- FUNC AND PROCEDURE ---------------- */
void makeTree(object fx, tree *T);

void addRight(object fx, node *root);
void addLeft(object fx, node *root);
void delRight(node *root);
void delLeft(node *root);

void printTreePreOrder(node *root);
void printTreeInOrder(node *root);
void printTreePostOrder(node *root);

/* MY FUNC PROC */
void findAndAdd(char nama[], object fx, node *root, int pos);
void addToTree(char before[], object fx, char position[], tree *T);
void countLeaf(node *root);
void checkMultiple(node *root);

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi UAS dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/