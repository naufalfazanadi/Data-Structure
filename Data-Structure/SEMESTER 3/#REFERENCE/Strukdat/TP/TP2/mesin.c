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

void addFirst(char kata[],list *L){
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	
	strcpy(baru->word,kata);
	
	if((*L).first == NULL){
		baru->next = NULL;
	}else{
		baru->next = (*L).first;
	}
	(*L).first = baru;
	baru = NULL;
		
}

void addAfter(elemen *prev,char kata[],list *L){
	
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	
	strcpy(baru->word,kata);
	
	if(prev->next== NULL){
		baru->next = NULL;
	}else{
		baru->next = prev->next;
	}
	prev->next = baru;
	baru = NULL;
}

void addLast(char kata[],list *L){
	if((*L).first == NULL){
		//jika list kosong
		addFirst(kata,L);
	}else{
		//jika list tidak kosong
		elemen *prev = (*L).first;
		while(prev->next != NULL){
			prev = prev->next;
		}
		addAfter(prev,kata,L);
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
			
			printf("%s\n",elmt->word);
			
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

void selectionSort (list *L){
	int i,j;
	elemen *elmt_akhir, *elmt_awal, *prev_akhir,*prev_awal, *final_akhir, *data_awal, *indeks_sebelum;
	elmt_awal=(*L).first; //pointer data elmt_awal
	
	prev_awal=NULL; //pointer sebelum data elmt_awal
	
	while (elmt_awal!=NULL){
		
		data_awal=elmt_awal;
		final_akhir=elmt_awal;
		elmt_akhir=elmt_awal->next; //pointer data yang dibandingin
		indeks_sebelum=data_awal;
		
		prev_akhir=indeks_sebelum;
		//mencari nilai tukar
		while (elmt_akhir!=NULL){
			//bandingkan cari yg paling kecil
			if(strcmp(elmt_akhir->word,final_akhir->word)<0){
				final_akhir=elmt_akhir; //pointer data yang ingin ditukar
				prev_akhir=indeks_sebelum;
			}
			indeks_sebelum=elmt_akhir;
			elmt_akhir=elmt_akhir->next; //increment			
		}
		elmt_awal = elmt_awal -> next; //increment
		
		
		
		//jika indeks beda maka pointer ada yang ditukar
		if(final_akhir!=data_awal){
			
			//jika data yang ingin ditukar bersebelahan
			if(data_awal->next==final_akhir){
				//jika data bukan di pertama
				if(data_awal!=(*L).first){
					prev_awal->next=data_awal->next;
				}else{
					(*L).first=final_akhir;
				}
				
				prev_akhir->next=final_akhir->next; //lepas dulu elmt_akhir
				final_akhir->next=data_awal; 
				
				prev_awal=final_akhir;
				elmt_awal=data_awal;
					
			}else{ //jika data yang ingin ditukar tidak bersebelahan
			
				if(data_awal==(*L).first){ //jika data diawal
				
					prev_akhir->next=final_akhir->next; //lepas elmt_akhir
					final_akhir->next=data_awal->next; //elmt_akhir next ke elmt_awal next
					data_awal->next=prev_akhir->next; //elmt_awal next ke elmt_akhir next
					prev_akhir->next=data_awal;
					data_awal=final_akhir; //supaya perulangan diulang dari data yang ditukar
					prev_awal=data_awal;
					(*L).first=final_akhir;
				}else{
					//A B C D E F G H I
					prev_awal->next=data_awal->next;
					prev_akhir->next=final_akhir->next;
					
					final_akhir->next=prev_awal->next;
					data_awal->next=prev_akhir->next;
					prev_awal->next=final_akhir;
					prev_akhir->next=data_awal;
					
					data_awal=final_akhir; //supaya perulangan diulang dari data yang ditukar
					prev_awal=data_awal;
				}
			}
		}else{
			prev_awal=data_awal; //increment	
		}
	}
}

/**
  * Search some element from a hint word.
  * @param hint Word.
  * @param current List.
  *	@return 	pointer element.
  */
elemen *searchData(char find[],list L){
	if((L).first!=NULL){
		elemen *elmt = (L).first;
		while(elmt != NULL){
			
			if(strcmp(find,elmt->word)==0){ //find the word then return the word
				return elmt;
			}
			elmt = elmt->next;
		}
		return NULL;
		
	}
}

/**
  * Delete some list if required word exist.
  *	Need to call another method for this procedure.
  * @param require word.
  * @param current list.
  */
void delSearch(char word[],list *L){
	if((*L).first != NULL){
		elemen *elmt = (*L).first;
		elemen *prev = NULL;
		//while as many as amout of data
		while(elmt != NULL){
			//if word exist delete the word!
			if(strcmp(word,elmt->word)==0){
				if(prev == NULL){
					delFirst(L);
				}else{
					delAfter(prev,L);
				}
			}
			prev = elmt;
			elmt = elmt->next;
		}
		
	}
}

/** Add Word/List if condition fulfilled.
  * New List is between two list.
  * addAfter method is needed.
  * @param condition word.
  * @param newWord for List.
  * @param current list
 */
void addWordBetween(char req[],char newWord[],list *L){
	if((*L).first != NULL){
		elemen *elmt = (*L).first;
		//while as many as amout of data
		while(elmt != NULL){
			if(strcmp(req,elmt->word)==0){
				elemen *temp = elmt->next;
				if(temp != NULL){ //if temp at the end of list.
					if(strcmp(temp->word,req)==0){
						addAfter(elmt,newWord,L);
					}					
				}
			}
			
			elmt = elmt->next;
		}
	}
	
}