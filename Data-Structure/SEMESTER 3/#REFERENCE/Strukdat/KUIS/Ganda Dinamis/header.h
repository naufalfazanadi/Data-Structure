#include <stdio.h> // pemanggilan library yang diperlukan
#include <malloc.h>
#include <string.h>
 /* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan KUIS1, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */
typedef struct elmt *alamat;
typedef struct elmt{
    char word[100];
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
void addFirst(char [],list *L);
void addAfter(elemen *prev,char [],list *L);
void addLast(char [],list *L);
void delFirst(list *L);
void delAfter(elemen *prev,list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
