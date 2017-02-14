#include "header.h" //panggil kepala(header)
 
int main(){
	nilai input[7];
    list L;
    createList(&L);
	
	int i;
	for(i=0;i<6;i++){
		scanf("%s %s",&input[i].nim,&input[i].nama);
	}
	addFirst(input[0].nim,input[0].nama,&L);
	addLast(input[1].nim,input[1].nama,&L);
	addFirst(input[2].nim,input[2].nama,&L);
	addAfter(L.first->next,input[3].nim,input[3].nama,&L);
	printElement(L);
	printf("-----\n");
	delLast(&L);
	delAfter(L.first->next->prev,&L);
	printElement(L);
	printf("-----\n");
	delFirst(&L);
	addFirst(input[4].nim,input[4].nama,&L);
	addAfter(L.first->next,input[5].nim,input[5].nama,&L);
	delLast(&L);
	printElementToHead(L);
	//s printf("-----\n");
	
	// addLast("1403356","Faisal Syaiful anwar","13",&L);
	// printElement(L);
    return 0;
}
