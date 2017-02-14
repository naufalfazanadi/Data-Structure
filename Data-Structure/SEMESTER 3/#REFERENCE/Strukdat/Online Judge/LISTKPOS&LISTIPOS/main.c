#include "header.h"

int main(){
	list L;
	scanf("%d",&n);
	createList(&L);
	
	int i; //iterasi
	int temp;
	
	// printf("%d",n);
	for(i=0;i<n;i++){
		scanf(" %d",&temp);
		// if(i == 0){
			// addFirst(temp,&L);
		// }else{
			// addAfter(i-1,temp,&L);
		// }
		addAfter(i-1,temp,&L);
	}
	int langkah;
	// printElement(L);
	scanf("%d",&langkah);
	
	problem data[langkah];
	
	for(i=0;i<langkah;i++){
		scanf("%d",&data[i].huruf);
		scanf("%d",&data[i].move);
		replaceIt(data[i].huruf,data[i].move,&L);
	}
		printElement(L);
	return 0;
}