#include "header.h" //calling header.h

void createList(list *L){
	(*L).first = NULL;
}

int countElementB(list L){

	int hasil = 0;
	if(L.first != NULL){
		/*list tidak kosong*/
		eBaris *elmt;

		/*inisialisasi*/
		elmt = L.first;
		
		while(elmt != NULL){
			/*proses*/
			hasil = hasil + 1;

			/*iterasi*/
			elmt = elmt->next;
		}
	}

	return hasil;

}

int countElementK(eBaris L){

	int hasil = 0;
	if(L.col != NULL){
		/*list tidak kosong*/
		eKolom *elmt;

		/*inisialisasi*/
		elmt = L.col;
		
		while(elmt != NULL){
			/*proses*/
			hasil = hasil + 1;

			/*iterasi*/
			elmt = elmt->next;
		}
	}

	return hasil;

}

void addFirstB(char category[], char name[], list *L){
		eBaris *elmt;
		elmt = (eBaris *) malloc (sizeof (eBaris));
		strcpy(elmt->elmt.category,category);
		strcpy(elmt->elmt.name,name);
		elmt->col = NULL;
		
		if((*L).first == NULL){
			/*jika list kosong*/
			elmt->next = NULL;
		}else{

			/*jika list tidak kosong*/
			elmt->next = (*L).first;
		}

		(*L).first = elmt;
		elmt = NULL;
}

void addFirstK(char aspect[], int score, eBaris *L){

	
		eKolom *baru;
		baru = (eKolom *) malloc (sizeof (eKolom));
		strcpy(baru->elmt.aspect,aspect);
		baru->elmt.score = score;

		if((*L).col == NULL){
			/*jika list kosong*/
			baru->next = NULL;
		}else{

			/*jika list tidak kosong*/
			baru->next = (*L).col;
		}

		(*L).col = baru;
		baru = NULL;
}

void addAfterB(eBaris* prev, char category[], char name[]){
		
		eBaris *baru;
		baru = (eBaris *) malloc (sizeof (eBaris));
		baru->col = NULL;
		strcpy(baru->elmt.category,category);
		strcpy(baru->elmt.name,name);

		if(prev->next == NULL){
			/*jika list kosong*/
			baru->next = NULL;
		}else{

			/*jika list tidak kosong*/
			baru->next = prev->next;
		}

		prev->next = baru;
		baru = NULL;
}

void addAfterK(eKolom* prev, char aspect[],int score){
		
		eKolom *baru;
		baru = (eKolom *) malloc (sizeof (eKolom));
		strcpy(baru->elmt.aspect,aspect);
		baru->elmt.score = score;		
		if(prev->next == NULL){
			/*jika list kosong*/
			baru->next = NULL;
		}else{

			/*jika list tidak kosong*/
			baru->next = prev->next;
		}

		prev->next = baru;
		baru = NULL;
}

void addLastB(char category[],char name[],list *L){
	if((*L).first == NULL){
		/*jika list adalah list kosong*/
		addFirstB(category,name,L);
	}else{

		/*jika list tidak kosong 
		mencari elemen terakhir list*/
		eBaris *prev = (*L).first;
		while(prev->next != NULL){
			/*iterasi*/
			prev = prev->next;
		}

		addAfterB(prev,category,name);
	}
}

void addLastK(char aspect[],int score, eBaris *L){
	if((*L).col == NULL){
		/*jika list adalah list kosong*/
		addFirstK(aspect,score,L);
	}else{
		
		/*jika list tidak kosong 
		mencari elemen terakhir list*/
		eKolom *prev = (*L).col;
		while(prev->next != NULL){
			/*iterasi*/
			prev = prev->next;
		}

		addAfterK(prev,aspect,score);
	}
}

void delFirstB(list *L){
	if((*L).first != NULL){
		/*jika list bukan list kosong*/
		eBaris *hapus = (*L).first;
		if(countElementB(*L) == 1){
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
		/*jika list bukan list kosong*/
		eKolom *hapus = (*L).col;
		if(countElementK(*L) == 1){
			(*L).col = NULL;
		}else{
			(*L).col = (*L).col->next;
			hapus->next = NULL;
		}

		free(hapus);
	}
}

void delAfterB(eBaris* prev, list *L){

	eBaris *hapus = prev -> next;

	if(hapus != NULL){
		if(hapus->next == NULL){
			prev->next = NULL;
		}else{
			prev->next = hapus -> next;
			hapus->next = NULL;
		}

		free(hapus);
	}
}

void delAfterK(eKolom* prev, list *L){

	eKolom *hapus = prev -> next;

	if(hapus != NULL){
		if(hapus->next == NULL){
			prev->next = NULL;
		}else{
			prev->next = hapus -> next;
			hapus->next = NULL;
		}

		free(hapus);
	}
}

void delLastB(list *L){
	if((*L).first != NULL){
		//jika list tidak kosong
		if(countElementB(*L) == 1){
			/*proses jika list hanya berisi satu elemen*/

			delFirstB(L);
		}else{
			//mencari elemen terakhir list 
			eBaris *last = (*L).first;
			eBaris *prev;

			while(last->next != NULL){

				/*iterasi*/
				prev = last;
				last = last -> next;
			}
				prev->next = NULL;
				free(last);
			/*elemen sebelum elemen terakhir menjadi elemen terakhir*/
			//delAfter(prev, L);

		}
	}
}

void delLastK(eBaris *L){
	if((*L).col != NULL){
		//jika list tidak kosong
		if(countElementK(*L) == 1){
			/*proses jika list hanya berisi satu elemen*/

			delFirstK(L);
		}else{
			//mencari elemen terakhir list 
			eKolom *last = (*L).col;
			eKolom *prev;

			while(last->next != NULL){

				/*iterasi*/
				prev = last;
				last = last -> next;
			}
				prev->next = NULL;
				free(last);
			/*elemen sebelum elemen terakhir menjadi elemen terakhir*/
			//delAfter(prev, L);

		}
	}
}

void printElement(list L){
	if(L.first != NULL){
		/* print total value */
		eBaris *elmt = L.first;
		while(elmt != NULL){
			/* Print fruit name. */
			printf("%s ", elmt->elmt.category);
			printf("%s\n", elmt->elmt.name);
			
			eKolom *elmt2 = elmt->col;
			if(elmt2 != NULL){				
				while(elmt2 != NULL){
					printf("%s ",elmt2->elmt.aspect);
					printf("%d\n",elmt2->elmt.score);
					elmt2 = elmt2->next;
				}
			}
			/*iterasi*/
			elmt = elmt->next;
		}
	}else{
		/*proses jika ist kosong*/
		printf("list kosong\n");
	}
}

void delAllB(list *L){

	if(countElementB(*L) != 0){
		int i;
		for (i = countElementB(*L); i >=1 ; i--)
		{
			/*proses menghapus elemen list*/
			delLastB(L);
		}
	}		
}

void delAllK(eBaris *L){

	if(countElementK(*L) != 0){
		int i;
		for (i = countElementK(*L); i >=1 ; i--)
		{
			/*proses menghapus elemen list*/
			delLastK(L);
		}
	}		
}

/**
 *isAvail = isAvailable, but too long XD.
 *Searching some pointer in a row.
 *Using big elemen list of list.
 *No cases with same name.
 *@param string word.
 *@param current list.
 *		@return choosen pointer.
 */
eBaris* isAvail(char name[], list L){
	eBaris *elmt = L.first;
	if(elmt != NULL){		
		while(elmt != NULL){
			// checking list with param word
			if(strcmp(elmt->elmt.name,name)==0){
				return elmt;
			}
			
			elmt = elmt->next;
		}
	}
	// return NULL, if pointer is NULL
	return NULL;
}

/**
 *searching some pointer in a collumn.
 *Using small elemen list of list.
 *No cases with same aspect.
 *@param aspect word.
 *@param current list->row.
 *		@return choose pointer.
 */
eKolom* isExist(char aspect[],eBaris* L){
	eKolom *elmt = (*L).col;
	if(elmt != NULL){		
		while(elmt != NULL){
			if(strcmp(elmt->elmt.aspect,aspect)==0){
				return elmt;
			} 
			elmt=elmt->next;
		}
	}
	//return NULL, if pointer is NULL.
	return NULL;
}

/**
 *Create to help delete function.
 *Using small elemen list of list.
 *search pointer b4 the selected word.
 *No cases with same aspect.
 *@param aspect word.
 *@param current list->row.
 *		@return choosen pointer.
 */
eKolom* getPrev(char aspect[], eBaris* L){
	eKolom *elmt = (*L).col;
	eKolom *prev;
	if(elmt != NULL){		
		while(elmt != NULL){
			if(strcmp(elmt->elmt.aspect,aspect)==0){
				if(elmt == (*L).col){
					return (*L).col;
				}else{
					return prev;
				}
			}
			prev = elmt;
			elmt=elmt->next;
		}
		return NULL;
	}else{
		return NULL;
	}
}

/**
 *Print Ranking each category.
 *Print band, that contain 3 aspects.
 *@param current List.
 */
void printRanking(list L){
	eBaris* elmt = L.first;
	//-----------------------------------------------
	/* this thing for checking the list, contain solo / group / both */
	/* i have no idea to do this :D */
	int statsS = 0; //Boolean casting with integer :v
	int statsG = 0; //re: Boolean, but with integer :(
	while(elmt != NULL){
		if(strcmp(elmt->elmt.category,"SOLO")==0){
			statsS = 1; //return true when solo either.
		}else if(strcmp(elmt->elmt.category,"GROUP")==0){
			statsG = 1; //return true when group either.
		}
		elmt = elmt->next;
	}
	//-------------------------------------------------
	int i;
	if(statsS == 1){		
		i=0;
		elmt = L.first;
		printf("===Kategori Solo===\n");
		while(elmt != NULL){
			/* print band name, which only have 3 aspects. */
			if(strcmp(elmt->elmt.category,"SOLO")==0 && countElementK(*elmt) == 3){
				printf("%d. %s\n",i+1,elmt->elmt.name);
				i++;
			} 
			elmt = elmt->next;
		}
	}
	if(statsG == 1){
		if(statsS == 1){
			//new line to separate solo and group
			printf("\n");
		}
		i=0;
		elmt = L.first;
		printf("===Kategori Group===\n");
		while(elmt != NULL){
			/* print band name, which only have 3 aspects. */
			if(strcmp(elmt->elmt.category,"GROUP")==0 && countElementK(*elmt) == 3){
				printf("%d. %s\n",i+1,elmt->elmt.name);
				i++;
			} 
			elmt = elmt->next;
		}		
	}
	
}

/**
 *Get score from small element.
 *Score is taking via big element (row).
 *there just only 3 aspect "KGM","EKS" and "IGT".
 *@param aspect word.
 *@param current list->row.
 *		@return score.
 */
int getScore(char aspect[],eBaris *L){
	eKolom* elmt = (*L).col;
	while(elmt != NULL){
		if(strcmp(elmt->elmt.aspect,aspect)==0){
			return elmt->elmt.score;
		}
		elmt=elmt->next;
	}
}

/**
 *PURE SELECTION SORT FROM ALPRO 2.
 *I've done this with TP2 XD.
 *Check condition with priority KGM > EKS> IGT.
 *@param current List.
 */
void selectionSort (list *L){
	int i,j;
	eBaris *elmt_akhir, *elmt_awal, *prev_akhir,*prev_awal, *final_akhir, *data_awal, *indeks_sebelum;
	elmt_awal=(*L).first; //pointer data elmt_awal
	
	prev_awal=NULL; //pointer sebelum data elmt_awal
	
	while (elmt_awal!=NULL){
		
		data_awal=elmt_awal;
		final_akhir=elmt_awal;
		elmt_akhir=elmt_awal->next; //pointer data yang dibandingin
		indeks_sebelum=data_awal;
		
		prev_akhir=indeks_sebelum;
		// mencari nilai tukar
		while (elmt_akhir!=NULL){
			// bandingkan cari yg paling kecil
			if( (getScore("KGM",elmt_akhir) > getScore("KGM",final_akhir)) ||
				((getScore("KGM",elmt_akhir) == getScore("KGM",final_akhir)) && (getScore("EKS",elmt_akhir) > getScore("EKS",final_akhir))) ||
				((getScore("KGM",elmt_akhir) == getScore("KGM",final_akhir)) && (getScore("EKS",elmt_akhir) == getScore("EKS",final_akhir)) && (getScore("IGT",elmt_akhir) > getScore("IGT",final_akhir))) ){
				final_akhir=elmt_akhir; //pointer data yang ingin ditukar
				prev_akhir=indeks_sebelum;
			}
			indeks_sebelum=elmt_akhir;
			elmt_akhir=elmt_akhir->next; //increment			
		}
		elmt_awal = elmt_awal -> next; //increment
		
		
		
		// jika indeks beda maka pointer ada yang ditukar
		if(final_akhir!=data_awal){
			
			// jika data yang ingin ditukar bersebelahan
			if(data_awal->next==final_akhir){
				// jika data bukan di pertama
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
					// A B C D E F G H I
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