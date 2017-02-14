#include "header.h"

int main(){

	list L;
	scanf("%d",&n);
	createList(&L);

	int i = 0;
	char input[100];
	
	for(i=0;i<n;i++){
		scanf(" %s",&input);
		addLast(input,&L);
	}

	isVocal(L);

	return 0;
}