#include "header.h"

int main(){
	int i;
	list L;
	
	scanf("%d",&n); 
	//buat list
	createList(&L);
	
	dataBank input[n]; 
	//input data
	for(i=0;i<n;i++){
		scanf("%s",&input[i].nama);
		scanf("%s",&input[i].rekening);
		scanf("%d",&input[i].saldo);
		
		//masukan data ke list
		addLast(input[i].nama,input[i].rekening,input[i].saldo,&L);
	}
	char undian[15];
	scanf(" %s",&undian);

	bonusManager(undian,&L);
	sorting(&L);
	printElement(L);
	
	return 0;
}