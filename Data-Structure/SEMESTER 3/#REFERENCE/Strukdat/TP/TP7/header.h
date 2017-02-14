/* Code by : faisalSA */
/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan TP7 STRUKDAT,
 jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//struct element
typedef struct{
	char nama[100];
	int spp;
}calonPeserta;

typedef struct elm *alamatelmt;
typedef struct elm{
	calonPeserta elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen *first;
	elemen *last;
}queue;

/* Global declaration */
queue *choosen;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nama[],int spp,queue *Q);
void del(queue *Q);
void printQueue(queue Q);
void addPriority(char nama[],int spp,int prioritas, queue *Q);
void compareWith(elemen *tempqyu, queue *Q);