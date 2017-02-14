#include <stdio.h>
#include <string.h>
#include <malloc.h>

// global
char temp[8]; int counterTemp;

/* ------------- GRAPH STRUCT ------------- */
typedef struct smp *nodeAddress;
typedef struct jlr *laneAddress;

typedef struct smp{
  char info;
  nodeAddress next;
  laneAddress arc;
}node;

typedef struct jlr{
  laneAddress next;
  node *var;
}lane;

typedef struct{
  node *first;
}graph;

/* --------------- QUEUE STRUCT --------------- */

typedef struct elmt *address;
typedef struct elmt {
  char elmt;
  address next;
} elemen;

typedef struct{
  elemen *first;
  elemen *last;
} queue;

/* GRAPH FUNC PROC */
void createEmpty(graph *G);
void addNode(char c, graph *G);
void addLane(node *dest, node *initial);
void delNode(char c, graph *G);
void delLane(char cDest, node *initial);

// Find node
node *findNode(char c, graph G);

// Print And Count
void printGraph(graph G);
int countGraph(graph G);

/* QUEUE FUNC PROC */
void createQueue(queue *Q);
int countElement(queue Q);

void add(char fx, queue *Q);
void del(queue *Q);
void printQueue(queue Q);


/* MNY FUNC AND PROC */
void addToGraph(char c1, char c2, graph *G); // process add to graph
void findWay(char initial, char dest, graph G, queue *Q);

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi UAS dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/