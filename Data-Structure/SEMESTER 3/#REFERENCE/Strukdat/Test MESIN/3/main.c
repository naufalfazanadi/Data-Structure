#include "header.h"
//alast
// afirst
// aafter(lfirst)
// delAf(first)
// dellast
// delfirst
// afirst
// alast
// afirst
// aafter(lfirst
// print to head
int main(){

	n = 7;
	list L;
	createList(&L);
	int  i;
	dataBank temp[7];
	for(i=0;i<n;i++){
		scanf("%s",&temp[i].kode);
		scanf("%s",&temp[i].nama);
	}
	// printf("=====================\n");
	addLast(temp[0].kode,temp[0].nama,&L);
	addFirst(temp[1].kode,temp[1].nama,&L);
	addAfter(L.first,temp[2].kode,temp[2].nama,&L);
	printElement(L);
	delAfter(L.first,&L);
	
	delLast(&L);
	delFirst(&L);
	printElement(L);
	addFirst(temp[3].kode,temp[3].nama,&L);
	addLast(temp[4].kode,temp[4].nama,&L);
	addFirst(temp[5].kode,temp[5].nama,&L);
	addAfter(L.first,temp[6].kode,temp[6].nama,&L);
	printElementToHead(L);
	// printf("=====================\n");

	return 0;
}