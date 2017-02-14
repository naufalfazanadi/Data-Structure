/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan UAS STRUKDAT,
 jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */
#include <stdio.h>
#include <malloc.h>
/* Struct pointer data */
typedef struct smp *alamatsimpul;
typedef struct smp{
	char info;
	alamatsimpul right;
	alamatsimpul left;
}simpul;

typedef struct{
	simpul* root;
}tree;

/* Global Variable */
int result; // result for save true provition ( have 2 child )

/* Global Function/Procedure */
void makeTree(char c, tree *T);
void addRight(char c, simpul *root);
void addLeft(char c, simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root);
void printTreeInOrder(simpul *root);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
simpul* findSimpul(char cari,simpul* root);
int isTwo(simpul *root);
void isTwoChild(simpul *root);