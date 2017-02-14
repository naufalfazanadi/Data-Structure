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

void addFirst(char nama[],char rekening[],int saldo,list *L){
	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		
		strcpy((*L).data[baru].elmt.nama, nama);
		strcpy((*L).data[baru].elmt.rekening, rekening);
		(*L).data[baru].elmt.saldo = saldo;	
		
		if((*L).first == -1){
			//jika list kosong
			(*L).data[baru].next = -1;
		}else{
			//jika list ditengah
			(*L).data[baru].next = (*L).first;
		}
		
		(*L).first = baru;
	}
		
}
void addAfter(int prev,char nama[],char rekening[],int saldo,list *L){
	// printf(".");
	if(countElement(*L) < n){
		int baru = emptyElement(*L);

		strcpy((*L).data[baru].elmt.nama, nama);
		strcpy((*L).data[baru].elmt.rekening, rekening);
		(*L).data[baru].elmt.saldo = saldo;	
		
		if((*L).data[prev].next == -1){
			//kosong
			(*L).data[baru].next = -1;
		}else{
			//list ditengah
			(*L).data[baru].next = (*L).data[prev].next;
		}
		
		(*L).data[prev].next = baru;
	}else{
		printf("sudah tidak dapat ditambahkan\n");
	}
}

void addLast(char nama[],char rekening[],int saldo,list *L){
	if((*L).first == -1){
		addFirst(nama,rekening,saldo,L);
	}else{
		// printf(".");
		if(countElement(*L) < n){
			int prev = (*L).first;
			
			while((*L).data[prev].next != -1){
				prev = (*L).data[prev].next;
			}
			addAfter(prev,nama,rekening,saldo,L);
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
			// printf("##");
		}else{
			// printf("%d\n",prev);
			// printf("%d\n",(*L).data[prev].next);
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
		// int i = 1;
		
		while(elmt != -1){
			
			printf("%s %s %d\n",(L).data[elmt].elmt.nama,(L).data[elmt].elmt.rekening,(L).data[elmt].elmt.saldo);
			// printf("L.first   : %d\n",L.first);
			
			//iterasi
			elmt = L.data[elmt].next;
			// i++;
		}			
	}

}
void bonusManager(char undian[],list *L){

	if((*L).first != -1){
		int elmt = (*L).first;
		int prev = -1;
		int i = 0;
		while(elmt != -1){
			int tabungan = (*L).data[elmt].elmt.saldo;
			if(bonusCheck(undian[0],undian[1],(*L).data[elmt].elmt.rekening[0],(*L).data[elmt].elmt.rekening[1]) == 1){
				(*L).data[elmt].elmt.saldo += (5 * tabungan / 100);
				// printf("1");
			}
			if(bonusCheck(undian[2],undian[3],(*L).data[elmt].elmt.rekening[2],(*L).data[elmt].elmt.rekening[3]) == 1){
				(*L).data[elmt].elmt.saldo += (10 * tabungan / 100);
				// printf("2");
			}
			if(bonusCheck(undian[4],undian[5],(*L).data[elmt].elmt.rekening[4],(*L).data[elmt].elmt.rekening[5]) == 1){
				(*L).data[elmt].elmt.saldo += (15 * tabungan / 100);
				// printf("3");
			}
			if(strcmp(undian,(*L).data[elmt].elmt.rekening) == 0){
				
				(*L).data[elmt].elmt.saldo += (10 * tabungan / 100);
				// printf("====");
			}
			// printf("%s;;",(*L).data[elmt].elmt.rekening);
			// printf("%d",(*L).data[elmt].elmt.saldo);
			if((*L).data[elmt].elmt.saldo == tabungan){
				// printf("%s\n",(*L).data[elmt].elmt.rekening);
				if(elmt == (*L).first){
					//jika data di awal
					delFirst(L);
				}else{
					delAfter(prev,L);
				}
			
			}else{
				prev = (*L).data[prev].next;
			}
			elmt = (*L).data[prev].next;
			
			i++;
		}
	}
	
}
int bonusCheck(char digit1,char digit2,char rek1,char rek2){
	int bool;
	if(digit1 == rek1){
		if(digit2 == rek2){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
	
	return bool;
}

void sorting(list *L){
	//bubble sort list
	int tukar;
	int elmt;
	int elmt2; 
	int prev = -1;
	
	do{
		tukar = 0;
		elmt = (*L).first;  //anggap i
		elmt2 = (*L).data[elmt].next; //anggap j = i+1
		while(elmt2 != -1){
		
			//jika data sebelumnya lebih kecil, maka geser
			if((*L).data[elmt].elmt.saldo < (*L).data[elmt2].elmt.saldo){
				(*L).data[elmt].next = (*L).data[elmt2].next;
				(*L).data[elmt2].next = elmt;
				
				if(elmt == (*L).first){
					// keadaan awal
					(*L).first = elmt2;
				}else{
					//ditengah list
					(*L).data[prev].next = elmt2;
				}
				
				elmt = elmt2;
				tukar = 1;
				// printElement(*L);
			}else{
				//jika tidak lebih kecil
				//geser
				prev = elmt;
				elmt = elmt2;
				elmt2 = (*L).data[elmt2].next;
			}
		}
	}while(tukar == 1);

}

//dibawah ini adalah selection sort gagal 
/*  void sorting(list *L){
	int i,j,
		elmt2,elmt,prevmax,prevelmt,
		max, //elemen maximal selection sort
		temp_elmt, //patokan akhir apakah dia punya lebih max nya
		previndeks;
		
	elmt = (*L).first;
	prevelmt = -2;
	for(i=0;i<countElement(*L)-1;i++){
		temp_elmt = elmt;
		max = elmt;
		elmt2 = (*L).data[elmt].next;
		previndeks = temp_elmt;
		prevmax = previndeks;
		for(j=i+1;j<countElement(*L);j++){
			if((*L).data[elmt2].elmt.saldo > (*L).data[max].elmt.saldo){
				max = elmt2;
				prevmax = previndeks;
			}
			previndeks = elmt2;
			elmt2 = (*L).data[elmt2].next;
			// printf("%d\n\n",j);
		}
		elmt = (*L).data[elmt].next;
		// printf("%d %d %d %d %d %d %d\n\n",elmt,elmt2,prevmax,prevelmt,previndeks,temp_elmt,max);
		if(max!=temp_elmt){
			if(i == 0){
				// diawal
				(*L).first = max;
			}
			// sebelahan
			if((*L).data[temp_elmt].next == max){
				(*L).data[prevelmt].next = (*L).data[temp_elmt].next;
				(*L).data[prevmax].next = (*L).data[max].next;
				(*L).data[max].next = temp_elmt;
				prevelmt = max;
				elmt = temp_elmt;
			}else{
				// gasebelahan
				(*L).data[prevelmt].next = (*L).data[temp_elmt].next;
				(*L).data[prevmax].next = (*L).data[max].next;
				(*L).data[max].next = (*L).data[prevelmt].next;
				(*L).data[temp_elmt].next = (*L).data[prevmax].next;
				(*L).data[prevelmt].next = max;
				(*L).data[prevmax].next = temp_elmt;
				
				temp_elmt = max;
				prevelmt = temp_elmt;
				
			}
		}else{
			prevelmt = temp_elmt;
		}
		
	}
		
 }
  */