#include <stdio.h> // pemanggilan library yang diperlukan
#include <malloc.h>
#include <string.h>
 
typedef struct{
    char nim[15];
    char nama[50];
}nilai; // isi dari element list
 
typedef struct elmt *alamat;
typedef struct elmt{
    nilai elmt;
    alamat next;
    alamat prev;
}elemen; // element list
 
typedef struct{
    elemen *first;
    elemen *tail;
}list; // list
 
// fungsi dan prosedur list ganda dinamis
void createList(list *L);
int countElement(list L);
void addFirst(char [],char [],list *L);
void addAfter(elemen *prev,char [],char [],list *L);
void addLast(char [],char [],list *L);
void delFirst(list *L);
void delAfter(elemen *prev,list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
