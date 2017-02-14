#include "header.h" // panggil kepala(header)
 
void createList(list *L){
    (*L).head = NULL;
    (*L).tail = NULL;
}
 
int countElement(list L){
    int jumlah = 0;
    elemen *tunjuk;
    tunjuk = L.head;
 
    while(tunjuk != NULL){
        jumlah = jumlah + 1;
        tunjuk = tunjuk->next;
    }
 
    return jumlah;
}
 
void addFirst(char nama[],list *L){
 
    elemen *isi;
    isi = (elemen *)malloc(sizeof (elemen));
 
    strcpy(isi->elmt.nama,nama);
 
    isi->next = NULL;
    isi->prev =  NULL;
 
    if((*L).head == NULL){
        //jika list kosong
        (*L).head = isi;
        (*L).tail = isi;
    }else{
        //jika list tidak kosong
        (*L).head->prev = isi;
        isi->next = (*L).head;
        (*L).head = isi;
    }
}
 
void addAfter(elemen *prev, char nama[],list *L){
 
    elemen *isi;
    isi = (elemen *)malloc(sizeof (elemen));
 
    strcpy(isi->elmt.nama,nama);
 
    isi->next = prev->next;
    isi->prev = prev;
    prev->next->prev = isi;
    prev->next = isi;
 
}
 
void addLast(char nama[],list *L){
 
    if((*L).head == NULL){
        addFirst(nama, L);
    }else{
    //proses mencari elemen terakhir
        //inisialisas
        elemen *isi;
        isi = (elemen *)malloc(sizeof (elemen));
 
		strcpy(isi->elmt.nama,nama);
 
        (*L).tail->next = isi;
        isi->prev = (*L).tail;
        isi->next = NULL;
        (*L).tail = isi;
    }
}
 
void delFirst(list *L){
    if((*L).head != NULL){
        if(countElement(*L)==1){
            elemen *hapus = (*L).head;
            (*L).head = NULL;
            (*L).tail = NULL;
            free(hapus);
        }else{
            elemen *hapus = (*L).head;
            (*L).head = hapus->next;
            hapus->next->prev = NULL;
            free(hapus);
        }
    }
}
 
void delAfter(elemen *prev,list *L){
    if((*L).head != NULL){
        if (prev->next == (*L).tail){
            elemen *hapus = (*L).tail;
            prev->next= NULL;
            (*L).tail = prev;
            free(hapus);
        }else{
            elemen *hapus = prev->next;
            prev->next = hapus->next;
            hapus->next->prev = prev;
            free(hapus);
        }
    }
 
}
 
void delLast(list *L){
    if((*L).head != NULL){
        //jika isi list hanya satu
        if(countElement(*L) == 1){
            delFirst(L);
        }else{
            delAfter((*L).tail->prev, L);
        }
    }
}

void printElement(list L){
    if(L.head != NULL){
        //inisialisasi
        elemen *depan = L.head;
        // elemen *belakang = L.tail;
 
        while(depan != NULL){
            printf("%s\n",depan->elmt.nama);
            depan = depan->next;
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

void reverseString(list *L){
	elemen *elmt;
	elmt = (*L).tail;
	int stop = countElement((*L)) / 2;
	// printf("%d\n",stop);
	int count = 0;
	while(elmt != NULL){
		int i;
		int counter = strlen(elmt->elmt.nama) - 1;
		char temp[20];
		strcpy(temp,elmt->elmt.nama);
		for(i=0;i<strlen(elmt->elmt.nama);i++){
			elmt->elmt.nama[i] = temp[counter];
			counter--;
			// printf("-%s-\n",elmt->elmt.nama);
		}
		count++;
		elmt = elmt->prev;
		if(count == stop){
			elmt = NULL;
		}
	}
}
