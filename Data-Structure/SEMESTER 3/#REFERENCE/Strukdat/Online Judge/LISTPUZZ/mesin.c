#include "header.h"

void createList(list *L){
	(*L).first = NULL;
}

int countElemenB(list L){
	int hasil = 0;
	if(L.first != NULL){
		eBaris *elmt = L.first;

		while(elmt != NULL){
			hasil++;
			elmt = elmt -> next;
		}
	}
	return hasil;
}

int countElemenK(eBaris L){
	int hasil = 0;
	if(L.col != NULL){
		eKolom *elmt = L.col;

		while(elmt != NULL){
			hasil++;
			elmt = elmt -> next;
		}
	}
	return hasil;
}

void addFirstB(char nim[],char nama[],list *L){
	eBaris *baru;
	baru = (eBaris *)malloc(sizeof (eBaris));

	strcpy(baru->elmt.nim,nim);
	strcpy(baru->elmt.nama,nama);

	baru->col = NULL; //create list head colom
	
	if((*L).first == NULL){
		//jika diawal
		baru->next = NULL;
	}else{
		baru->next = (*L).first;
	}
	(*L).first = baru;
	baru = NULL;
}

void addFirstK(char kode[],char nilai[],eBaris *L){
	eKolom *baru;
	baru = (eKolom *)malloc(sizeof (eKolom));

	strcpy(baru->elmt.kode,kode);
	strcpy(baru->elmt.nilai,nilai);
	
	if((*L).col == NULL){
		baru->next = NULL;
	}else{
		baru->next = (*L).col;
	}
	(*L).col = baru;
	baru = NULL;
}

void addAfterB(eBaris *prev,char nim[],char nama[]){
	eBaris *baru;
	baru = (eBaris *)malloc(sizeof (eBaris));

	strcpy(baru->elmt.nim,nim);
	strcpy(baru->elmt.nama,nama);
	// baru->dataB.huruf = huruf;
	baru->col = NULL;
	if(prev->next == NULL){
		baru->next = NULL;
	}else{
		baru->next = prev->next;
	}
	prev->next = baru;
	baru = NULL;

}
void addAfterK(eKolom *prev,char kode[],char nilai[]){
	eKolom *baru;
	baru = (eKolom *)malloc(sizeof (eKolom));

	strcpy(baru->elmt.kode,kode);
	strcpy(baru->elmt.nilai,nilai);
	
	if(prev->next == NULL){
		baru->next = NULL;
	}else{
		baru->next = prev->next;
	}
	prev->next = baru;
	baru = NULL;

}

void addLastB(char nim[],char nama[],list *L){
	if((*L).first == NULL){
		addFirstB(nim,nama,L);
	}else{
		eBaris *baru;
		baru = (eBaris *)malloc(sizeof (eBaris));

		strcpy(baru->elmt.nim,nim);
		strcpy(baru->elmt.nama,nama);
		baru->next = NULL;

		baru->col = NULL; //create list kol
		
		eBaris *last = (*L).first;

		while(last->next != NULL){
			
			last = last->next;
		}

		last->next = baru;
		
		baru = NULL;
	}
}

void addLastK(char kode[],char nilai[],eBaris *L){
	if((*L).col == NULL){
		addFirstK(kode,nilai,L);
	}else{
		eKolom *baru;
		baru = (eKolom *)malloc(sizeof (eKolom));

		strcpy(baru->elmt.kode,kode);
		strcpy(baru->elmt.nilai,nilai);
		baru->next = NULL;

		eKolom *last = (*L).col;

		while(last->next != NULL){
			last = last->next;
		}

		last->next = baru;
		baru = NULL;
	}
}

void delFirstB(list *L){
	if((*L).first != NULL){
		eBaris *hapus = (*L).first;
		
		if(countElemenB(*L) == 1){
			(*L).first = NULL;
		}else{
			(*L).first = (*L).first->next;
			hapus->next = NULL;
		}
		free(hapus);
	}
}

void delFirstK(eBaris *L){
	if((*L).col != NULL){
		eKolom *hapus = (*L).col;
		
		if(countElemenK(*L) == 1){
			(*L).col = NULL;
		}else{
			(*L).col = (*L).col->next;
			hapus->next = NULL;
		}
		free(hapus);
	}
}

void delAfterK(eKolom *prev){
	if(prev->next != NULL){
		eKolom *hapus = prev->next;
		if(hapus->next == NULL){
			prev->next = NULL;
		}else{
			prev->next = hapus->next;
			hapus->next = NULL;
		}
		free(hapus);
	}
}

void delAfterB(eBaris *prev){
	if(prev->next != NULL){		
		eBaris *hapus = prev-> next;
		if(hapus->next == NULL){
			prev->next = NULL;
		}else{
			prev->next = hapus->next;
			hapus->next = NULL;
		}
	}
}

void delLastB(list *L){
	if((*L).first != NULL){
		if(countElemenB(*L) == 1){
			delFirstB(L);
		}else{
			eBaris *last = (*L).first;
			eBaris *prevLast;
			while(last->next != NULL){
				
				prevLast = last;
				last = last->next;
			}
			delAfterB(prevLast);
		}
	}
}

void delLastK(eBaris *L){
	if((*L).col != NULL){
		if(countElemenK(*L) == 1){
			delFirstK(L);
		}else{
			eKolom *last = (*L).col;
			eKolom *prevLast;
			while(last->next != NULL){
				
				prevLast = last;
				last = last->next;
			}
			delAfterK(prevLast);
		}
	}
}

void printElemen(list L){
	if(L.first != NULL){
		eBaris *elmt = L.first;
		while(elmt != NULL){
			eKolom *elmt2 = elmt->col;
			printf("%s %s\n",elmt->elmt.nim,elmt->elmt.nama);
			while(elmt2 != NULL){
				printf("-%s %s\n",elmt2->elmt.kode,elmt2->elmt.nilai);
				elmt2 = elmt2 -> next;
			}
			elmt = elmt->next;
		}
	}
}

void delAllB(list *L){
	// eBaris *elmt = L.first;
	int i;
	for(i=countElemenB(*L);i>=1;i--){
		delLastB(L);
	}
}

void delAllK(eBaris *L){
	int i;
	for(i=countElemenK(*L);i>=1;i--){
		delLastK(L);
	}
}
