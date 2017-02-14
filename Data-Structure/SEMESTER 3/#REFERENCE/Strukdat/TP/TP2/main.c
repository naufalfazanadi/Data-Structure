#include "header.h"

int main(){
	int n,
		i=0;
	char temp[50];
	list L;

	createList(&L);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		//input every string on temporary then add into list.
		scanf(" %s",&temp);
		addLast(temp,&L);
	}
	
	selectionSort(&L);
	
	addWordBetween("kamu","TikTok",&L);
	
	if(searchData("aku",L) != NULL){
		delSearch("aku",&L);
	}
	if(searchData("dia",L) != NULL){
		elemen *elmt = searchData("dia",L);
		strcpy(elmt->word,"alpro");
	}
	printElement(L);
	return 0;
}