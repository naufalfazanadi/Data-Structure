#include "header.h"

void createList(list *L){
	
	(*L).first = NULL;
}

int countElement(list L){
	int hasil = 0;
	
	if(L.first != NULL){
		//list tidak kosong
		elemen *elmt;
		
		elmt = L.first;
		
		while(elmt != NULL){
			hasil++;
			elmt = elmt -> next;
		}
	}
	
	return hasil;
}

void addFirst(char nim[],char nama[],char nilai[],list *L){
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	
	strcpy(baru->elmt.nim,nim);
	strcpy(baru->elmt.nama,nama);
	strcpy(baru->elmt.nilai,nilai);
	
	if((*L).first == NULL){
		baru->next = NULL;
	}else{
		baru->next = (*L).first;
	}
	(*L).first = baru;
	baru = NULL;
		
}

void addAfter(elemen *prev,char nim[],char nama[],char nilai[],list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	
	strcpy(baru->elmt.nim,nim);
	strcpy(baru->elmt.nama,nama);
	strcpy(baru->elmt.nilai,nilai);
	
	if(prev->next== NULL){
		baru->next = NULL;
	}else{
		baru->next = prev->next;
	}
	prev->next = baru;
	baru = NULL;
}

void addLast(char nim[],char nama[],char nilai[],list *L){
	if((*L).first == NULL){
		//jika list kosong
		addFirst(nim,nama,nilai,L);
	}else{
		//jika list tidak kosong
		elemen *prev = (*L).first;
		while(prev->next != NULL){
			prev = prev->next;
		}
		addAfter(prev,nim,nama,nilai,L);
	}
}	

void delFirst(list *L){
	if((*L).first != NULL){
		elemen *hapus  = (*L).first;
		
		if(countElement(*L) == 1){
			(*L).first = NULL;
		}else{
			(*L).first = (*L).first->next;
		}
		
		free(hapus);
	}
}

void delAfter(elemen *prev,list *L){
	elemen *hapus  = prev -> next;
	
	if(hapus != NULL){ 
		if(hapus->next == NULL){
			prev->next = NULL; 
		}else{
			prev->next = hapus->next;
			hapus->next = NULL;
		}
		free(hapus);
	}
}

void delLast(list *L){
	if((*L).first != NULL){
		if(countElement(*L) == 1){
			delFirst(L);				//jika satu elemen
		}else{
			elemen *hapus = (*L).first;
			elemen *prev = NULL;
			
			while (hapus->next != NULL){		//iterasi
				prev = hapus;
				hapus = hapus->next;
			}
			delAfter(prev, L);							//elemen sebelum elemen terakhir menjadi elemen terakhir
		}
	}
}

void printElement(list L){
	
	if(L.first != NULL){
		//inisialisasi	
		elemen* elmt = L.first;
		int i = 1;
		
		while(elmt != NULL){
			
			printf("elemen ke : %d\n",i);
			printf("nim    : %s\n",elmt->elmt.nim);
			printf("nama   : %s\n",elmt->elmt.nama);
			printf("nilai  : %s\n",elmt->elmt.nilai);
			printf("next   : %d\n",elmt->next);
			printf("L.first   : %d\n",L.first);
			
			//iterasi
			elmt = elmt->next;
			i++;
		}			
	}
	else {
		printf("list kosong\n");
	}
}
void delAll(list *L){
	
	int i;
	for(i=countElement(*L);i>=1;i--){
		delLast(L);
	}
	
}