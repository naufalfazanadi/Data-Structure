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
 
void addFirst(float angka,list *L){
 
    elemen *isi;
    isi = (elemen *)malloc(sizeof (elemen));
 
    // strcpy(isi->elmt.nama,nama);
	isi->elmt.angka = angka;
 
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
 
void addAfter(elemen *prev, float angka,list *L){
 
    elemen *isi;
    isi = (elemen *)malloc(sizeof (elemen));
 
    // strcpy(isi->elmt.nama,nama);
	isi->elmt.angka = angka;
 
    isi->next = prev->next;
    isi->prev = prev;
    prev->next->prev = isi;
    prev->next = isi;
 
}
 
void addLast(float angka,list *L){
 
    if((*L).head == NULL){
        addFirst(angka, L);
    }else{
    //proses mencari elemen terakhir
        //inisialisas
        elemen *isi;
        isi = (elemen *)malloc(sizeof (elemen));
 
		// strcpy(isi->elmt.nama,nama);
		isi->elmt.angka = angka;
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
            printf("%.2f\n",depan->elmt.angka);
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

void reverseFloat(list *L){
	elemen *elmt;
	elmt = (*L).tail;
	
	int count = 0;
	int stop = countElement(*L) / 2;
	while(elmt != NULL){
		elmt->elmt.angka = getNum(elmt->elmt.angka);
		
		elmt = elmt->prev;
		count++;
		if(count == stop){
			elmt = NULL;
		}
	}
}

float getNum(float angka){
	int first = angka;
	float a = (angka - first)*1000;
	int last;
	if((int)a%2==1){
		last = ((int)a+1)/10;
	}else{
		last = a/10;
		
	}
	int f1,f2,
		l1,l2;
		
		f1 = first/10;
		f2 = first - (f1*10);
		first = (f2*10)+f1;
		
		l1 = last/10;
		l2 = last - (l1*10);
		last = (l2*10) + l1;
		
		float fix = (((float)(last*100)+first))/100;
		return fix;
		// printf("%.2f\n\n",fix);
}