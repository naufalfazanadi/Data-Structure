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
 
    strcpy(isi->elmt.name,nama);
 
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
	// printf("!\n");
    elemen *isi;
    isi = (elemen *)malloc(sizeof (elemen));
	// printf("@\n");
 
    strcpy(isi->elmt.name,nama);
 
	// printf("*\n");
    isi->next = prev->next;
    isi->prev = prev;
    prev->next->prev = isi;
    prev->next = isi;
 
	// printf("&&&&&&&\n");
}
 
void addLast(char nama[],list *L){
 
    if((*L).head == NULL){
        addFirst(nama, L);
    }else{
    //proses mencari elemen terakhir
        //inisialisas
        elemen *isi;
        isi = (elemen *)malloc(sizeof (elemen));
 
		strcpy(isi->elmt.name,nama);
 
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
            printf("%s\n",depan->elmt.name);
            // belakang = belakang->prev;

            depan = depan->next;
        }
		if(cntWhen != 0){
			int i ;
			for (i=0;i<cntWhen;i++){
				printf("%d\n",arrWhen[i]);
			}
		}
    }
}
 
void delAll(list *L){
    int i; 
    for(i=countElement(*L);i>=1;i--){
        delLast(L);
    }
}
/**
  *Looking for element in question.
  *Searching by word.
  *No cases have the same two words.
  *@param req word.
  *@param current list.
  *		@return pointer of element.
 */
elemen *searchData(char find[],list *L){
	if( (*L).head!=NULL){
		/* initialization */
		elemen *elmt = (*L).head;
		while(elmt != NULL){
			
			if(strcmp(find,elmt->elmt.name)==0){ //find the word then return the word
				return elmt;
			}
			elmt = elmt->next;
		}
		return NULL;
	}
}
/**
  *look for a sequence of numbers from a list.
  *Searching by word.
  *No cases have the same two words.
  *@param req word.
  *@param current list.
  *		@return sequence of number.
 */
int orderList(char find[],list *L){
	
	int x = 1; //variable for counter the list.
	if((*L).head!=NULL){
		/* initialization */
		elemen *elmt = (*L).head;
		while(elmt != NULL){
			if(strcmp(find,elmt->elmt.name)==0){ //find the word then return the number
				return x;
			}
			x++;
			elmt = elmt->next;
		}
		return 0;
		
	}
}
/**
  *Insert Procedure
  *adding a list with two provisions.
  *each provision need to checked by if.
  *@param new data for list.
  *@param provision checked.
  *@param reference data.
  *@param current list.
 */
void insertProc(char att1[],char att2[],char att3[] ,list *L){
	/* initialization */
	elemen *elmt = searchData(att3,L);
	if(strcmp(att2,"After")==0){
		if(elmt != NULL){
			if(elmt == (*L).tail){
				/* if at the end of the list. */
				addLast(att1,L);
			}else{
				addAfter(elmt,att1,L);
			}
		}
	}else if(strcmp(att2,"Before")==0){
		if(elmt != NULL){		
			if(elmt == (*L).head){
				/* if at the first of the list. */
				addFirst(att1,L);
			}else{				
				/* we have to change the pointer to the previous. */
				elmt = elmt->prev;
				addAfter(elmt,att1,L);
			}
		}
	}
}
/**
  *Delete Procedure
  *adding a list with two provisions.
  *each provision need to checked by if.
  *@param deleted data.
  *@param current list.
 */
void deleteProc(char att1[],list *L){
	elemen *elmt = searchData(att1,L);
	if(elmt == (*L).head){
		/* if at the first of the list. */
		delFirst(L);
	}else{
		elmt = elmt->prev;
		delAfter(elmt,L);
	}
}
/**
  *Check each command.
  *should separate the words from a sentence.
  *each provision need to checked by if.
  *@param deleted data.
  *@param current list.
 */
void checkCommand(char comm[],list *L){
	int i;
	char firstWord[50] = "";
	char word[50];
	int count;
	int countWord;
	i = 0,count = 0,countWord = 0;
	//while each character by character.
	while(i <= strlen(comm)){
		if(comm[i] == ' ' || i == strlen(comm)){
			countWord++; //increment for count the word from a sentence
			
			/* need to save the firstWord until finish of the while */
			if(strcmp(firstWord,"")==0){
				strcpy(firstWord,word);
			}
			if(strcmp(firstWord,"Insert")==0){
				char att1[50];
				char att2[50];
				char att3[50];
				
				if(countWord == 2){
					strcpy(att1,word);
				}else if(countWord == 3){
					strcpy(att2,word);
				}else if(countWord == 4){
					strcpy(att3,word);
					insertProc(att1,att2,att3,L);
				}
				
			}else if(strcmp(firstWord,"When")==0){
				char att1[50];
				if(countWord == 2){
					strcpy(att1,word);
					/* we have to save the variable to array */
					arrWhen[cntWhen] = orderList(att1,L);
					cntWhen++;
				}
			}else if(strcmp(firstWord,"Delete")==0){
				char att1[50];
				if(countWord == 2){
					strcpy(att1,word);
					elemen *elmt = searchData(att1,L);
					deleteProc(att1,L);
				}
			}
			count = 0;
		}else{
			/* copying character by character */
			word[count] = comm[i];
			word[count+1] = '\0';						
			count++;
		}
		i++;
	}
	// printf("\n\n\n\n");
}
