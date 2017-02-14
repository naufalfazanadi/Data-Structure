#include "header.h"

int main(){
	list L;
	createList(&L);
	
	int n,i;
	char nama[100],matkul[100];
	int sks;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(" %s %s %d",&nama,&matkul,&sks);
		fillList(nama,matkul,sks,&L);
	}
		
	printElement(L);
	return 0;
}