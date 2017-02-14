/* TP 6 STRUKDAT */
/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan TP6 STRUKDAT,
 jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

//struct form
typedef struct{
	char code[250];
	char name[250];
}form;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	form elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen* top;
}stack;
/*
	Global declaration for function and procedure.
*/
void createStack(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(char nim[],char nama[],stack *S);
void pop(stack *S);
void printStack(stack S);
int isSame(char primary[],char key[]);
