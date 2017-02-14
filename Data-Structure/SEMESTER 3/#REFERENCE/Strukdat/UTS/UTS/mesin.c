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

void addFirstB(char nama, list *L){
		eBaris *elmt;
		elmt = (eBaris *) malloc (sizeof (eBaris));
		elmt->elmt.code = nama;
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

void addFirstK(char vit[], eBaris *L){

	
		eKolom *baru;
		baru = (eKolom *) malloc (sizeof (eKolom));
		strcpy(baru->elmt.puzz,vit);

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

void addAfterB(eBaris* prev, char nama){
		
		eBaris *baru;
		baru = (eBaris *) malloc (sizeof (eBaris));
		baru->col = NULL;
		
		baru->elmt.code = nama;
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

void addAfterK(eKolom* prev, char vit[]){
		
		eKolom *baru;
		baru = (eKolom *) malloc (sizeof (eKolom));
		strcpy(baru->elmt.puzz,vit);
		
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

void addLastB(char nama,list *L){
	if((*L).first == NULL){
		/*jika list adalah list kosong*/
		addFirstB(nama,L);
	}else{

		/*jika list tidak kosong 
		mencari elemen terakhir list*/
		eBaris *prev = (*L).first;
		while(prev->next != NULL){
			/*iterasi*/
			prev = prev->next;
		}

		addAfterB(prev,nama);
	}
}

void addLastK(char vit[], eBaris *L){
	if((*L).col == NULL){
		/*jika list adalah list kosong*/
		addFirstK(vit, L);
	}else{
		
		/*jika list tidak kosong 
		mencari elemen terakhir list*/
		eKolom *prev = (*L).col;
		while(prev->next != NULL){
			/*iterasi*/
			prev = prev->next;
		}

		addAfterK(prev, vit);
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
		printf("%d\n",total);
		eBaris *elmt = L.first;
		while(elmt != NULL){
			/* Print fruit name. */
			printf("%s ", elmt->elmt.nama);
			eKolom *elmt2 = elmt->col;
			
			while(elmt2 != NULL){
				eKolom *cek = elmt2->next;
				if(cek != NULL){
					/* check whether the data is the latest data. */
					printf("%s ",elmt2->elmt.vit);
				}else{
					printf("%s\n",elmt2->elmt.vit);
				}
				elmt2 = elmt2->next;
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
/*
 *Searching function / isNull Function.
 *check data with name provision.
 *Return pointer if data alrdy exist.
 *Return NULL if data didnt exist.
 *@param clue word.
 *@param current list.
 *		@return pointer.
 */
eBaris *isNull(char nama,list L){
	if(L.first != NULL){
		eBaris* elmt = L.first;
		while(elmt != NULL){
			if(elmt->elmt.code == nama){
				return elmt;
			}
			elmt = elmt->next;
		}
		return NULL;
	}else{
		/* if list currently empty */
		return NULL;		
	}
}
