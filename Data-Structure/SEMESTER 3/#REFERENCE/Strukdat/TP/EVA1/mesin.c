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

void addFirst(char depan[],list *L){
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	
	strcpy(baru->nama,depan);
	
	if((*L).first == NULL){
		baru->next = NULL;
	}else{
		baru->next = (*L).first;
	}
	(*L).first = baru;
	baru = NULL;
		
}

void addAfter(elemen *prev,char depan[],list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	
	strcpy(baru->nama,depan);
	
	if(prev->next== NULL){
		baru->next = NULL;
	}else{
		baru->next = prev->next;
	}
	prev->next = baru;
	baru = NULL;
}

void addLast(char depan[],list *L){
	if((*L).first == NULL){
		//jika list kosong
		addFirst(depan,L);
	}else{
		//jika list tidak kosong
		elemen *prev = (*L).first;
		while(prev->next != NULL){
			prev = prev->next;
		}
		addAfter(prev,depan,L);
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
			printf("nim    : %s\n",elmt->nama);
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
/**
  *Searching some string that contain number.
  *return 1 if contain number.
  *return 0 if haven't number.
  *@param word.
  *		@return true or false (with integer).
 */
int isNumber(char string[]){
	int i = 0;
	int stats = 0;
	while(i<strlen(string) && stats == 0){
		// check if one of character is number
		if(string[i] == '1' || 
		string[i] == '2' ||
		string[i] == '3' ||
		string[i] == '4' ||
		string[i] == '5' ||
		string[i] == '6' ||
		string[i] == '7' ||
		string[i] == '8' ||
		string[i] == '9' ||
		string[i] == '0'){
			stats = 1;
			return 1;
			
		}
		i++;
	}
	if(stats == 0){
		return 0;
	}
}
/**
  *check condition then print.
  *using isNumber function.
  *print valid or Tidak Valid.
  *@param current list.
 */
void check(list L){
	elemen *elmt = L.first;
	int i  = 0;
	int atas = 0;
	int bawah = 0;
	while(i < countElement(L)/2){
		// summing atas if contain number
		// assuming 0 if half Top really haven't number.
		atas += isNumber(elmt->nama);
		elmt = elmt->next;
		i++;
	}
	while(i < countElement(L)){
		// summing bawah if contain number.
		// summing bawah if every one of string contain number.
		bawah += isNumber(elmt->nama);
		elmt=elmt->next;
		i++;
	}
	
	if(atas == 0 && (bawah == countElement(L)/2)){
		printf("Valid\n");
	}else{
		printf("Tidak Valid\n");
	}
}
