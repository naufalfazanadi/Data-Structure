/* Saya Faisal Syaiful Anwar tidak melakukan kecurangan yang dispesifikasikan pada tugas
masa depan Struktur Data pada saat mengerjakan Tugas Masa Depan
Struktur Data. Jika saya melakukan kecurangan maka Allah/Tuhan adalah
saksi saya, dan saya bersedia menerima hukumanNya. Aamiin.
*/
/* Alhamdulillah terimakasih CSPC untuk 3 Semesternya, Terimakasih bu rosa atas materinya:D */
/* Semoga nilai Kuis bisa ketutupi dengan TMD ini, amiin YRA */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* Pointer Struct */
typedef struct smp *alamatsimpul;
typedef struct smp{
	char name[500];
	alamatsimpul sibling;
	alamatsimpul child;
}simpul;

typedef struct{
	simpul* root;
}tree;
/* This Struct just for input for sure */
/* Split String */
typedef struct{
	char parent[100];
	char child[100];
}family;

/* Global Declaration */
family splitString(char string[]);
void makeTree(char name[], tree *T);
void addChild(char name[], simpul *root);
void delChild(char name[], simpul *root);
simpul* findSimpul(char name[], simpul *root);
void printTreePreOrder(simpul *root,int spasi,int count);
void visitSimpul(char name[], simpul *root,simpul *visitasi[],int indeks,int index);
void del(simpul *root);
void refineLength(simpul *root,int count);
void resetLen();

/* Global Variable */
int stats; // this stats for visitSimpul status when data has been found.
int inx[64]; // inx is variable for save length of the route.
int maxlen[64]; // maxLength used for PRINT SECTION.