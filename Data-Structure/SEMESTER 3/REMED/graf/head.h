#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* ------------- GRAPH STRUCT ------------- */
typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp{
  char info;
  alamatsimpul next;
  alamatjalur arc;
}simpul;

typedef struct jlr{
  alamatjalur next;
  simpul *node;
}jalur;

typedef struct{
  simpul* first;
}graph;

/* GRAPH FUNC PROC */
void createEmpty(graph *G);
void addSimpul(char c, graph *G);
void addJalur(simpul *tujuan, simpul *awal);
void delJalur(char ctujuan, simpul *awal);
void delSimpul(char c, graph *G);

// Find Simpul
simpul *findSimpul(char c, graph G);

// Print And Count
void printGraph(graph G);
int countGraph(graph G);

/* MNY FUNC AND PROC */
void addToGraph(char c1, char c2, graph *G); // process add to graph
int cekJalur(char find[], graph G); // func to check the jalur

/* ------------------------------------------------------ */
/*
Saya Muhammad Naufal Fazanadi mengerjakan evaluasi REMEDIAL dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.
*/