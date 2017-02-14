/* Saya Faisal Syaiful tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan UAS STRUKDAT GRAF,
 jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */
/* Alhamdulillah makasih bu atas materi STRUKDATNYA :') */
#include <stdio.h>
#include <string.h>
#include <malloc.h>
/* Struct Simpul */
typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;
typedef struct smp{
	char info;
	alamatsimpul next;
	alamatjalur arc;
}simpul;

/* struct jalur */
typedef struct jlr{
	alamatjalur next;
	simpul *node;
}jalur;

typedef struct{
	simpul* first;
}graph;

char jalan[100];

simpul* findSimpul(char c, graph G);
int countGraph(graph G);