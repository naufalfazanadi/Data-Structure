#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp{
	char info;
	alamatsimpul next;
	alamatjalur arc;
}simpul;

typedef struct jlr{
	int info;
	alamatjalur next;
	simpul *node;
}jalur;

typedef struct{
	simpul* first;
}graph;

simpul* findSimpul(char c, graph G);