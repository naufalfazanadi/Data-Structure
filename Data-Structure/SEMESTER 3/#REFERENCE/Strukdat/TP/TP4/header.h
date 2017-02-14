/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan TP4, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */

#include <stdio.h> // pemanggilan library yang diperlukan
#include <malloc.h>
#include <string.h>
 
typedef struct{
    char name[200];
}band; // isi dari element list
 
typedef struct elmt *alamat;
typedef struct elmt{
    band elmt;
    alamat next;
    alamat prev;
}elemen; // element list
 
typedef struct{
    elemen *head;
    elemen *tail;
}list; // list
 
// fungsi dan prosedur list ganda dinamis
int arrWhen[50];
int cntWhen;
void createList(list *L);
int countElement(list L);
void addFirst(char nama[],list *L);
void addAfter(elemen *prev, char nama[],list *L);
void addLast(char nama[],list *L);
void delFirst(list *L);
void delAfter(elemen *prev,list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
elemen *searchData(char find[],list *L);
int orderList(char find[],list *L);
void insertProc(char att1[],char att2[],char att3[],list *L);
void deleteProc(char att1[],list *L);
void checkCommand(char comm[],list *L);
