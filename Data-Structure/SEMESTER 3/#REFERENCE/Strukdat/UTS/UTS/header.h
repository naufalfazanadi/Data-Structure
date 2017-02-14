/* UTS STRUKDAT 2014 */
/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan UTS STRUKDAT,
 jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
//struct big element.
typedef struct {
	char code;
}structA;
//Struct small element
typedef struct{
	char puzz[100];
}structB;
typedef struct eklm *alamatekolom;
typedef struct eklm{
	structB elmt;
	alamatekolom next;
}eKolom;

typedef struct ebr *alamatbaris;
typedef struct ebr{
	structA elmt;
	eKolom *col;
	alamatbaris next;

}eBaris;

typedef struct {
	eBaris *first;
}list;
/* Global variable for total*/

/* Global Declaration */
