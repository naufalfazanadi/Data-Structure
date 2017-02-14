#include "header.h"

void createList(list *L){
	
	(*L).first = -1;
	(*L).tail = -1;
	int i;
	
	for(i=0;i<n;i++){
		//proses menginisialisasi isi array
		(*L).data[i].next = -2;
		(*L).data[i].prev = -2;
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

void addFirst(char city[],int value,list *L){
	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		
		strcpy((*L).data[baru].elmt.city, city);
		(*L).data[baru].elmt.value = value;	
		
		if((*L).first == -1){
			//jika list kosong
			(*L).data[baru].next = -1;
			(*L).data[baru].prev = -1;
			(*L).tail = baru;
		}else{
			//jika list ditengah
			(*L).data[baru].next = (*L).first;
			(*L).data[(*L).first].prev = baru;
			(*L).data[baru].prev = -1;
		}
		
		(*L).first = baru;
	}else{
		printf("sudah tdk dapat ditambahkan\n");
		//array penuh
	}
		
}

void addAfter(int prev,char city[],int value,list *L){
	
	if(countElement(*L) < n){
		int baru = emptyElement(*L);

		strcpy((*L).data[baru].elmt.city, city);
		(*L).data[baru].elmt.value = value;	
		
		if((*L).data[prev].next == -1){
			//dibelakang
			(*L).data[baru].prev = prev;
			(*L).data[prev].next = baru;
			(*L).tail = baru;
			(*L).data[baru].next = -1;
		}else{
			//list ditengah
			(*L).data[baru].next = (*L).data[prev].next;
			(*L).data[baru].prev = prev;
			(*L).data[prev].next = baru;
			(*L).data[(*L).data[baru].next].prev = baru;
		}
	}else{
		printf("sudah tidak dapat ditambahkan\n");
	}
}

void addLast(char city[],int value,list *L){
	
	if((*L).first == -1){
		addFirst(city,value,L);
	}else{
		if(countElement(*L) < n){
			addAfter((*L).tail,city,value,L);
		}else{
			printf("sudah tidak dapat ditambahkan\n");
		}
	}
}	

void delFirst(list *L){
	if((*L).first != -1){
		int hapus  = (*L).first;
		
		if(countElement(*L) == 1){
			(*L).first = -1;
			(*L).tail = -1;
		}else{
			(*L).first = (*L).data[hapus].next;
			(*L).data[(*L).first].prev = -1;
		}
		
		(*L).data[hapus].next = -2;
		(*L).data[hapus].prev = -2;
	}else{
			printf("sudah tidak dapat ditambahkan\n");		
	}
}

void delAfter(int prev,list *L){
	int hapus  = (*L).data[prev].next;
	// | prev | | hapus |
	if(hapus != -1){ 
		if((*L).data[hapus].next == -1){
			(*L).tail = prev;
			(*L).data[prev].next = -1;
			// (*L).data[prev].next = -1; 
		}else{
			(*L).data[prev].next = (*L).data[hapus].next;
			
			(*L).data[(*L).data[hapus].next].prev = prev;
		}
		(*L).data[hapus].prev = -2;
		(*L).data[hapus].next = -2;
	}
}

void delLast(list *L){
	
	if((*L).first != -1){
		if(countElement(*L) == 1){
			delFirst(L);	//jika satu elemen
		}else{
			delAfter((*L).data[(*L).tail].prev, L);//elemen sebelum elemen terakhir menjadi elemen terakhir
		}
	}
	else {
		printf("list kosong\n");	
	}
}

void printElement(list L){
	
	if(L.first != -1){
		//inisialisasi	
		// int elmt = L.first;
		// int i = 1;		
		// while(elmt != -1){
			// iterasi
			// elmt = L.data[elmt].next;
			// i++;
		// }			
		printf("total : %d\n",total);
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
  *Looking for the element in question.
  *@param req word.
  *@param current list.
  *@return 		number of element.
 */
int search(char word[],list L){
	if(L.first != -1){
		int elmt = L.first;
		// printf("");
		// printf(".%d %s %s\n",elmt,word,L.data[elmt].elmt.city);
		while(elmt != -1){
			if(strcmp(L.data[elmt].elmt.city,word)==0){
				return elmt;
			}
			elmt = L.data[elmt].next;
		}
		return -1;
	}
}

void nextCity(int from, char city[],list L){
	if(L.first != -1){
		
		int elmt = from;
		int goal = search(city,L);
		
		if(elmt < goal){ //if begginning city after the next City
			while(elmt != goal){
				total += L.data[elmt].elmt.value;
				
				printf("%s %d\n",L.data[elmt].elmt.city,L.data[elmt].elmt.value);
				elmt = L.data[elmt].next;
			}
		}else{
			while(elmt != goal){
				total += L.data[elmt].elmt.value;
				
				printf("%s %d\n",L.data[elmt].elmt.city,L.data[elmt].elmt.value);
				elmt = L.data[elmt].prev;
			}
			
		}
		strcpy(nextC,city);
	}
}