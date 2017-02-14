#include "header.h" // panggil kepala(header)
 
void createList(list *L){
    (*L).first = NULL;
    (*L).tail = NULL;
}
 
int countElement(list L){
    int jumlah = 0;
    elemen *tunjuk;
    tunjuk = L.first;
 
    while(tunjuk != NULL){
        jumlah = jumlah + 1;
        tunjuk = tunjuk->next;
    }
 
    return jumlah;
}
 
void addFirst(char nim[],char nama[],list *L){
 
    elemen *baru;
    baru = (elemen *)malloc(sizeof (elemen));
 
    strcpy(baru->elmt.nim,nim);
    strcpy(baru->elmt.nama,nama);
    // strcpy(baru->elmt.nilai,nilai);
	
 
    if((*L).first == NULL){
        //jika list kosong
		baru->next = NULL;
		baru->prev =  NULL;
        (*L).tail = baru;
    }else{
        //jika list tidak kosong
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
	(*L).first = baru;
	baru = NULL;
}
 
void addAfter(elemen *prev, char nim[],char nama[],list *L){
 
    elemen *baru;
    baru = (elemen *)malloc(sizeof (elemen));
 
    strcpy(baru->elmt.nim,nim);
    strcpy(baru->elmt.nama,nama);
    // strcpy(baru->elmt.nilai,nilai);
	if(prev->next == NULL){
		baru->next = NULL;
		(*L).tail = baru;
	}else{
		baru->next = prev->next;
		baru->next->prev = baru;
	}

    baru->prev = prev;
    prev->next = baru;
 
}
 
void addLast(char nim[],char nama[],list *L){
 
    if((*L).first == NULL){
        addFirst(nim,nama,L);
    }else{
    //proses mencari elemen terakhir
		addAfter((*L).tail,nim,nama,L);
        //inisialisas
        // elemen *baru;
        // baru = (elemen *)malloc(sizeof (elemen));
 
		// strcpy(baru->elmt.nama,nama);
 
        // (*L).tail->next = baru;
        // baru->prev = (*L).tail;
        // baru->next = NULL;
        // (*L).tail = baru;
    }
}
 
void delFirst(list *L){
    if((*L).first != NULL){
		elemen *hapus = (*L).first;
		
        if(countElement(*L)==1){
			//1 ELEMEN
            // elemen *hapus = (*L).first;
            (*L).first = NULL;
            (*L).tail = NULL;
        }else{
            (*L).first = hapus->next;
            (*L).first->prev = NULL;
			hapus->next = NULL;
        }
            free(hapus);
    }
}
 
void delAfter(elemen *prev,list *L){
    if((*L).first != NULL){
		elemen *hapus = prev->next;
		if(hapus != NULL){
			if (hapus->next == NULL){
				prev->next= NULL;
				(*L).tail = prev;
			}else{
				prev->next = hapus->next;
				hapus->next->prev = prev;
				hapus->next = NULL;
			}
			hapus->prev = NULL;
			free(hapus);			
		}
    }
 
}
 
void delLast(list *L){
    if((*L).first != NULL){
        //jika baru list hanya satu
        if(countElement(*L) == 1){
            delFirst(L);
        }else{
            delAfter((*L).tail->prev, L);
        }
    }
}

void printElement(list L){
    if(L.first != NULL){
        //inisialisasi
        elemen *elmt = L.first;
        // elemen *belakang = L.tail;
 
        while(elmt != NULL){
            printf("%s %s\n",elmt->elmt.nim,elmt->elmt.nama);
            // printf("%s\n",elmt->elmt.nilai);
            elmt = elmt->next;
            // belakang = belakang->prev;
        }
    }
    else{
        //proses jika list kosong
    }
}
 
void delAll(list *L){
    int i; 
    for(i=countElement(*L);i>=1;i--){
        delLast(L);
    }
}

void printElementToHead(list L){
	if(L.first != NULL){
		elemen* elmt = L.tail;
		
		while(elmt != NULL){
			printf("%s %s\n",elmt->elmt.nim,elmt->elmt.nama);
			
			elmt = elmt->prev;
		}
	}
}