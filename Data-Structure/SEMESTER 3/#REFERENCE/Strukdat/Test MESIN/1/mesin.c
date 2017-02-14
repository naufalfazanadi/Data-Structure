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

void addFirst(char nim[],char nama[],char nilai[],list *L){
	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		
		strcpy((*L).data[baru].elmt.tipe, nim);
		strcpy((*L).data[baru].elmt.nama, nama);
		strcpy((*L).data[baru].elmt.hp, nilai);	
		
		if((*L).first == -1){
			//jika list kosong
			(*L).data[baru].next = -1;
		}else{
			//jika list ditengah
			(*L).data[baru].next = (*L).first;
		}
		
		(*L).first = baru;
	}else{
		printf("!sudah tdk dapat ditambahkan\n");
		//array penuh
	}
		
}

void addAfter(int prev,char nim[],char nama[],char nilai[],list *L){
	// printf("%d !\n",countElement(*L));
	if(countElement(*L) < n){
		int baru = emptyElement(*L);

		strcpy((*L).data[baru].elmt.tipe, nim);
		strcpy((*L).data[baru].elmt.nama, nama);
		strcpy((*L).data[baru].elmt.hp, nilai);
		
		if((*L).data[prev].next == -1){
			//kosong
			(*L).data[baru].next = -1;
		}else{
			//list ditengah
			(*L).data[baru].next = (*L).data[prev].next;
		}
		
		(*L).data[prev].next = baru;
	}else{
		printf("@sudah tidak dapat ditambahkan\n");
	}
}

void addLast(char nim[],char nama[],char nilai[],list *L){
	if((*L).first == -1){
		addFirst(nim,nama,nilai,L);
	}else{
		if(countElement(*L) < n){
			int prev = (*L).first;
			
			while((*L).data[prev].next != -1){
				prev = (*L).data[prev].next;
			}
			addAfter(prev,nim,nama,nilai,L);
		}else{
			printf("#sudah tidak dapat ditambahkan\n");
		}
	}
}	

void delFirst(list *L){
	if((*L).first != -1){
		int hapus  = (*L).first;
		
		if(countElement(*L) == 1){
			(*L).first = -1;
		}else{
			(*L).first = (*L).data[(*L).first].next;
		}
		
		(*L).data[hapus].next = -2;
	}else{
			printf("sudah tidak dapat ditambahkan\n");		
	}
}

void delAfter(int prev,list *L){
	int hapus  = (*L).data[prev].next;
	
	if(hapus != -1){ 
		if((*L).data[hapus].next == -1){
			(*L).data[prev].next = -1; 
		}else{
			(*L).data[prev].next = (*L).data[hapus].next;
		}
		(*L).data[hapus].next = -2;
	}
}

void delLast(list *L){
	if((*L).first != -1){
		if(countElement(*L) == 1){
			delFirst(L);				//jika satu elemen
		}else{
			int hapus = (*L).first;
			int prev;
			
			while ((*L).data[hapus].next != -1){		//iterasi
				prev = hapus;
				hapus = (*L).data[hapus].next;
			}
			delAfter(prev, L);							//elemen sebelum elemen terakhir menjadi elemen terakhir
		}
	}
	else {
		printf("list kosong\n");	
	}
}
void printElement(list L){
	
	if(L.first != -1){
		//inisialisasi	
		int elmt = L.first;
		int i = 1;
		
		while(elmt != -1){
			
			// printf("elemen ke : %d\n",i);
			// printf("nim    : %s\n",L.data[elmt].elmt.nim);
			// printf("nama   : %s\n",L.data[elmt].elmt.nama);
			// printf("nilai  : %s\n",L.data[elmt].elmt.nilai);
			// printf("L.first   : %d\n",L.first);
			printf("%s %s %s\n",L.data[elmt].elmt.tipe,L.data[elmt].elmt.nama,L.data[elmt].elmt.hp);
			printf("next   : %d\n",L.data[elmt].next);
			//iterasi
			elmt = L.data[elmt].next;
			i++;
		}			
	}
	else {
		printf("List Kosong!\n");
	}
	newLine();
}
void delAll(list *L){
	
	int i;
	for(i=countElement(*L);i>=1;i--){
		delLast(L);
	}
	
}
void newLine(){
	printf("======\n");
}