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
 
void addFirst(char word[],list *L){
 
    elemen *baru;
    baru = (elemen *)malloc(sizeof (elemen));
 
    strcpy(baru->word,word);
    // strcpy(baru->elmt.nama,nama);
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
 
void addAfter(elemen *prev, char word[],list *L){
 
    elemen *baru;
    baru = (elemen *)malloc(sizeof (elemen));
 
    strcpy(baru->word,word);
    // strcpy(baru->elmt.nama,nama);
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
 
void addLast(char word[],list *L){
 
    if((*L).first == NULL){
        addFirst(word,L);
    }else{
    //proses mencari elemen terakhir
		addAfter((*L).tail,word,L);
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
            printf("%s\n",elmt->word);
			
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

void moveList(list *L){
	// delFirst(L);
	
	elemen* ptop = NULL;
	elemen* pbot = (*L).tail->prev;
	
	elemen* top = (*L).first;
	elemen* bot = (*L).tail;
	
	elemen* ttop,tbot;
	elemen* t1;
	elemen* t2;
	int i;
	i = 0;
	while(i < (countElement((*L))/2)){
		// printf("%c\n",top->word[i]);
		// printf("%c\n",bot->word[i]);
		if(top->word[0] != 'a' &&
		top->word[0] != 'i' &&
		top->word[0] != 'u' &&
		top->word[0] != 'e' &&
		top->word[0] != 'o'){
			
			(*L).first->prev = NULL;
			(*L).first->next = top->next->next;
			(*L).first = top->next;
			
			t1 = top;
			t1->prev = NULL;
			t1->next = NULL;
			// printf("@@%s",t1->word);
			top = (*L).first;
		}else{
			top = top->next;
		}
		
		if(bot->word[0] == 'a' ||
		bot->word[0] == 'i' ||
		bot->word[0] == 'u' ||
		bot->word[0] == 'e' ||
		bot->word[0] == 'o'){
			(*L).tail->next = NULL;
			(*L).tail->prev = bot->prev->prev;
			(*L).tail = bot->prev;
			
			t2 = bot;
			t2-> next = NULL;
			t2->prev = NULL;
			
			bot = (*L).tail;
		}else{
			bot = bot->prev;
		}
		
		(*L).tail->next = t1;
		t1->prev = (*L).tail;
		(*L).tail = t1;
		(*L).tail->next = NULL;
		
		(*L).tail->prev = t1->prev;
		
		(*L).first->prev = t2;
		t2->next = (*L).first;
		(*L).first = t2;
		(*L).first->prev = NULL;
		(*L).first->next = t1->next;
		
		// printf("!!%s\n",(*L).tail->word);
		bot->next = t1;
		t1->prev = bot;
		(*L).tail = t1;
		
		
		i++;
		// printf("%s..",(*L).first->word);
		// printf("%s..",(*L).tail->word);
	}
	
}


void mF(list L){
	
}