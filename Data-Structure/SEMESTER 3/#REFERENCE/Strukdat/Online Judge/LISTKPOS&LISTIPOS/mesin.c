 #include "header.h"

void createList(list *L){
	
	(*L).first = -1;
	int i;
	
	for(i=0;i<n;i++){
		//proses menginisialisasi isi array
		(*L).data[i].next = -2;
	}
}

int countElement(list L){
	int hasil = 0;
	
	if(L.first != -1){
		int elmt;
		
		elmt = L.first;
		
		while(elmt != -1){
			hasil++;
			elmt = L.data[elmt].next;
		}
	}
	
	return hasil;
}

int emptyElement(list L){
	int hasil = -1;
	
	if(countElement(L) < n){
		int ketemu = 0;
		
		int i = 0;
		
		while((ketemu == 0) && (i<n)){
			if(L.data[i].next == -2){
				hasil = i;
				ketemu = 1;
			}else{
				i++;
			}
		}
	}
	return hasil;
}

void addFirst(int karakter,list *L){

	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		
		(*L).data[baru].isi = karakter;
		
		if((*L).first == -1){
			//jika list kosong
			(*L).data[baru].next = -1;
		}else{
			//jika list ditengah
			(*L).data[baru].next = (*L).first;
		}
		
		(*L).first = baru;
	}else{
		printf("sudah tdk dapat ditambahkan\n");
		//array penuh
	}
		
}

void addAfter(int prev,int karakter,list *L){
	
	if(countElement(*L) < n){
		int baru = emptyElement(*L);

		// strcpy((*L).data[baru].isi, karakter);
		(*L).data[baru].isi = karakter;
		
		if((*L).data[prev].next == -1){
			//kosong
			(*L).data[baru].next = -1;
		}else{
			//list ditengah
			(*L).data[prev].next = baru;
		}
		
		(*L).data[prev].next = baru;
	}else{
		printf("sudah tidak dapat ditambahkan\n");
	}
}

void addLast(int karakter,list *L){
	if((*L).first == -1){
		addFirst(karakter,L);
	}else{
		if(countElement(*L) < n){
			int prev = (*L).first;
			
			while((*L).data[prev].next != -1){
				prev = (*L).data[prev].next;
				addAfter(prev,karakter,L);
			}
		}else{
			printf("sudah tidak dapat ditambahkan\n");
		}
	}
}	

void printElement(list L){
	
	if(L.first != -1){
		//inisialisasi	
		int elmt = L.first;
		// printf("L FIRST %d",elmt);
		int i = 1;
		
		while(elmt != -1){
			// printf("%d--------\n",elmt);
			// printf("elemen ke : %d\n",i);
			printf("%d",L.data[elmt].isi);
			printf("\n");
			
			//iterasi
			elmt = L.data[elmt].next;
			i++;
		}
	}
}

void delAll(list *L){
	
	int i;
	for(i=countElement(*L);i>=1;i--){
		// delLast(L);
	}
	
}

void replaceIt(int karakter,int step,list *L){
	int i,j; // iterasi
	
	i = 0;
	int stats = 0;
	// int temp = 1;
	// char temp2;
	int move = n-step+1;
	while(i < n && stats == 0){
		if(karakter == (*L).data[i].isi){
			// printf("!");
			if(move-1 > i){ //jika pindah di list bawah bawah dari asal
				// printf("@");
				j = i;
				while(j < move - 1){
					(*L).data[j].isi = (*L).data[j+1].isi;
					// printf("%c",(*L).data[j].isi);
					// printf("%c\n",(*L).data[j+1].isi);
					// printf("%d\n",(*L).data[j+1].next);
					j++;
				}
				// (*L).data[j].isi = ;
				(*L).data[j].isi = karakter;
			}else if(move-1 < i){ //jika pindah di list atas dari asal
				// printf("#");
				j = i;
				while(j > move-1){
					(*L).data[j].isi = (*L).data[j-1].isi;
					j--;
				}
				(*L).data[j].isi = karakter;
			}
			stats = 1;
		}
		i++;
	}

}