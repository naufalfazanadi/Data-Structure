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

void addFirst(char title[],int price, int rating, list *L){
	if(countElement(*L) < n){
		int baru = emptyElement(*L);
		
		strcpy((*L).data[baru].elmt.title, title);
		(*L).data[baru].elmt.price = price;	
		(*L).data[baru].elmt.rating = rating;	
		
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

void addAfter(int prev,char title[],int price, int rating,list *L){
	
	if(countElement(*L) < n){
		int baru = emptyElement(*L);

		strcpy((*L).data[baru].elmt.title, title);
		(*L).data[baru].elmt.price = price;	
		(*L).data[baru].elmt.rating = rating;	
		
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

void addLast(char title[],int price, int rating,list *L){
	
	if((*L).first == -1){
		addFirst(title,price,rating,L);
	}else{
		if(countElement(*L) < n){
			addAfter((*L).tail,title,price,rating,L);
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
		int elmt = L.first;
		// int i = 1;		
		while(elmt != -1){
			// iterasi
			
			printf("%s %d %d\n",L.data[elmt].elmt.title,L.data[elmt].elmt.price,L.data[elmt].elmt.rating);
			elmt = L.data[elmt].next;
			// i++;
		}			
		// printf("total : %d\n",total);
	}
	else {
		printf("list kosong\n");
	}
} 

/**
  *Looking for element in question.
  *Searching by word.
  *No cases have the same two words.
  *@param req word.
  *@param current list.
  *@return 		number of element.
 */
int search(char word[],list L){
	if(L.first != -1){
		int elmt = L.first;
		while(elmt != -1){
			//if books title equals req word
			if(strcmp(L.data[elmt].elmt.title,word)==0){
				return elmt; //return numb of element.
			}
			elmt = L.data[elmt].next;
		}
		return -1;
	}
}
/**
  *Looking number of element in question.
  *Searching by rate
  *@param rate sought.
  *@param current list.
  *@return		number of element.
 */
int search2(int rate,list L){
	if(L.first != -1){
		int elmt = L.first;
		while(elmt != -1){

			//if books rate equals rate sought.
			if(L.data[elmt].elmt.rating == rate){
				return elmt; //return numb of element.
			}
			elmt = L.data[elmt].next;
		}
		return -1;
	}
}
/**Printing element from @param, to @param.
  *The concept of the data structures used.
  *Printing while summing price of the book of the distance.
  *@param init element.
  *@param final elemnt.
  *@param current list.
 */
void direction(int from,int to,list L){

	int elmt = from;
	//i dont need array for combination.
	//just print it then summing the price.
	
	//if init element less than final element
	//print element to tail!
	if(elmt < to){
		while(elmt != L.data[to].next){
			
			temp += L.data[elmt].elmt.price; //summing the price for every combination.
			printf("%s %d\n",L.data[elmt].elmt.title,L.data[elmt].elmt.price);
			elmt = L.data[elmt].next;
		} 
	}
	//if init element greater than final element
	//print element to head!
	else{
		
		while(elmt != L.data[to].prev){
			
			printf("%s %d\n",L.data[elmt].elmt.title, L.data[elmt].elmt.price);
			temp += L.data[elmt].elmt.price;
		
			elmt = L.data[elmt].prev;
		}
	}
	
}
/**
  *Check whether the price of each combination, enough to get paid. 
  *@param combination number.
  *@param current price until last combination.
 */
void checkMoney(int i,int current){

	if(temp > combineBook.total){
		if(temp <= current){
			combineBook.number = i;
			combineBook.total = temp;
		}
	}
}
/**
  *Case if priority books in the first element
  *Case if if the same rating to be purchased.
  *@param rate number.
  *@param current list.
 */
void sameRate(int rate,list L){
	if(L.first != -1){
		int elmt = L.first;
		while(elmt != -1){
			//print every element with the same rate.
			if(L.data[elmt].elmt.rating == rate){
				printf("%s %d\n",L.data[elmt].elmt.title,L.data[elmt].elmt.price);
				temp += L.data[elmt].elmt.price; //summing the price either.
			}
			elmt = L.data[elmt].next;
		}
	}
}
