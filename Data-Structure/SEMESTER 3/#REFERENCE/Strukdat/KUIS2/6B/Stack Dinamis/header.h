/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan KUIS2 STRUKDAT,
 jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	float numb;
}notfloat;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	notfloat elmt;
	alamatelmt next;
}elemen;

typedef struct{
	elemen* top;
}stack;

void createStack(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(float numb,stack *S);
void pop(stack *S);
elemen* getPop(stack *S);
void popIsi(stack *S1,stack *S2);