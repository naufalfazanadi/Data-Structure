#include "header.h"

//buat stack kosong
void createStack(stack *S){
  (*S).top = NULL;
}
 
//fungsi memeriksa stack kosong atau tidak
int isEmpty(stack S){
    int hasil = 0;
 
    if(S.top == NULL){ //jika kosong
        hasil = 1;
    }
 
    return hasil;
}
 
//menghitung banyak elemen dalam stack yang tersisa
int countElement(stack S){
    int hasil = 0;
 
    if(S.top != NULL){ //jika tidak kosong
        elemen *tunjuk = S.top;
 
        while(tunjuk != NULL){
            hasil= hasil + 1;
            tunjuk = tunjuk->next;
        }
    }
 
    return hasil;
}
 
//operator  push
void push(int angka, stack *S ){
    elemen *tunjuk;
    tunjuk = (elemen *) malloc (sizeof (elemen));
    tunjuk->angka = angka;
    tunjuk->next = (*S).top;
    (*S).top = tunjuk;
    tunjuk = NULL;
}
 
//operator pop
void pop(stack *S){
    if((*S).top != NULL){ //jika tidak kosong
        elemen *tunjuk = (*S).top;
        (*S).top = (*S).top->next;
        tunjuk->next = NULL;
        free(tunjuk);
    }
}
 
//print stack
void printStack(stack S){
    if(S.top != NULL){
        elemen *tunjuk = S.top;
  
        while(tunjuk != NULL){
			if(tunjuk->next == NULL){
				printf("%d", tunjuk->angka);
			}else{
				printf("%d ", tunjuk->angka);
			}
            tunjuk = tunjuk->next;
        }
		printf("\n");
    }
    else{
        printf("Stack Kosong\n");
    }
}

elemen* getPop(stack *S){
	
	elemen* temp = NULL;
	if((*S).top != NULL){
		if(countElement(*S) == 1){
			temp = (*S).top;
			(*S).top = NULL;
		}else{
			elemen *elmt = (*S).top;
			temp = elmt;
			(*S).top = (*S).top->next;
			elmt->next = NULL;
			free(elmt);
		}
	}
	return temp;
}

//prosedur pop isi -> pindahkan satu elemen teratas dari S ke S2
void popIsi(stack *S, stack *S2){
    if(isEmpty(*S) == 0){ //jika stack1 tidak kosong
        push((*S).top->angka, &(*S2));
        pop(&(*S));
    }
}

//hapus yang dicari
void popCari(int cari, stack *S){
    if((*S).top != NULL){
		stack Stemp;
		createStack(&Stemp);
		
		//pindahin stack ke stack sementara sampe ketemu yang dicari
        while((*S).top != NULL && (*S).top->angka!=cari){
			popIsi(S, &Stemp);
        }
		//jika ketemu yang dicari maka dihapus
		if((*S).top->angka==cari) pop(S);
		
		//pindahin stack temp ke stack asal
		while(Stemp.top != NULL){
			popIsi(&Stemp, S);
        }
		
    }
}

//tambah diatas stack yang dicari
void pushOn(int cari, int angka, stack *S){
    if((*S).top != NULL){
		stack Stemp;
		createStack(&Stemp);
		
		//pindahin stack ke stack sementara sampe ketemu yang dicari
        while((*S).top != NULL && (*S).top->angka!=cari){
			popIsi(S, &Stemp);
        }
		//jika ketemu yang dicari maka dihapus
		if((*S).top->angka==cari) push(angka, S);
		
		//pindahin stack temp ke stack asal
		while(Stemp.top != NULL){
			popIsi(&Stemp, S);
        }
		
    }
}