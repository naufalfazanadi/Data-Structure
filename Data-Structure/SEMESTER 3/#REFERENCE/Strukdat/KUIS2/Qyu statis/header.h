/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan KUIS 2 STRUKDAT,
 jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */
#include<stdio.h>
#include<string.h>

typedef struct{
	float numb;
}angka;

typedef struct{
	int first;
	int last;
	angka data[100];
}queue;

/* Global Variable */
int n;

/* Global Function/prc */
void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void add(float numb,queue *Q);
void del(queue *Q);
void printQueue(queue Q);
void addPriority(float numb,int prioritas,queue *Q);