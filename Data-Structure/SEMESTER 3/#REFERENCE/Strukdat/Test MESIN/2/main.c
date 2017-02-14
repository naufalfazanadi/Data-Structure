#include "header.h"

int main(){

	list L;
	createList(&L);
	nilaiMatKul input[6];
	int i;
	for(i=0;i<5;i++){
		scanf("%s %s %d",&input[i].nim , &input[i].nama, &input[i].gaji);
	}
	
	
	//TEST MESIN 2 LIST DINAMIS 
	addFirst(input[0].nim,input[0].nama,input[0].gaji,&L);
	addLast(input[1].nim, input[1].nama, input[1].gaji, &L);
	addAfter(L.first->next,input[2].nim, input[2].nama, input[2].gaji,&L);
	printElement(L);
	printf("=====\n");
	
	delFirst(&L);
	addFirst(input[3].nim,input[3].nama,input[3].gaji,&L);
	printElement(L);
	printf("=====\n");
	
	addLast(input[4].nim, input[4].nama, input[4].gaji, &L);
	printElement(L);
	printf("=====\n");
	
	delAfter(L.first,&L);
	delLast(&L);
	printElement(L);
	printf("=====\n");
	
	delAll(&L);
	printElement(L);
	printf("=====\n");

	return 0;
}