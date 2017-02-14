#include "header.h"

int main(){
	
	n = 5;
	
	list L;
	
	createList(&L);
	
	data input[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%s %s %s",&input[i].tipe,&input[i].nama,&input[i].hp);
	}
		
	addFirst(input[0].tipe,input[0].nama,input[0].hp,&L);
	addFirst(input[1].tipe,input[1].nama,input[1].hp,&L);
	
	
	addLast(input[2].tipe,input[2].nama,input[2].hp,&L);
	
	delLast(&L);
	
	printElement(L);
	
	addAfter(L.data[L.data[L.first].next].next,input[3].tipe,input[3].nama,input[3].hp,&L);
	
	
	printElement(L);
	
	addFirst(input[4].tipe,input[4].nama,input[4].hp,&L);
	delAfter(L.first,&L);
	delLast(&L);
	printElement(L);
	
	delAll(&L);
	printElement(L);
	
	
	
	return 0;
}