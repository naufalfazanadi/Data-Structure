/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi Tugas Masa Depan dalam
mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan
kecurangan seperti yang telah dispesifikasikan. Aamiin.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // atoi
#include <malloc.h>

/* DEFINE BOOLEAN */
#define TRUE 1
#define FALSE 0

/* GLOBAL VARIABLE */
int maxLevel;
int maxLength;
int space[32];

int nNode;
int counterNode;

/* STRUCT FOR PAHALA AND DOSA */
typedef struct {
  int n;
  char str[32][64];
} behavior;

/* --------------- MAIN STRUCT (OBJECT) --------------- */
typedef struct {
  char nama[32];
  char minus[32][64];
  char plus[32][64];
  int m; // counter minus
  int p; // counter plus
  int level;
} object;

/* STRUCT N-er TREE */
typedef struct smp *nodeAddress;
typedef struct smp{
  object info;
  nodeAddress sibling;
  nodeAddress child;
} node;

typedef struct{
  node *parent;
} tree;

/* --------------------- Proc And Func --------------------- */
// N-er Tree
void makeTree(object fx, tree *T);
void addChild(object fx, node *parent);
void delChild(object fx, node *parent);
void printTreePreOrder(node *parent);

node *findNode(char search[], node *parent);

// MY PROC AND FUNC !
void addToTree (char command[], tree *T); // separate and add
int getLevel(node *parent, char nama[], int level); // get level node
void setLevel(char nama[], node *parent); // set the level of node

void delArrStr(int index, int n, char str[32][64]); // delete string
void delMinus(behavior tanggungJawab, behavior keberuntungan, node *parent); // del and add
void addPlus(behavior keberuntungan, node *parent); // add plus

/* SPACING */
void setSpace(tree T); // set the max space
void getSpaceLevel(int level, node *parent); // get space of current level
void setMaxLength(node *parent); // set space each level
