#include "header.h"

int main(){

	int i;
	list L;
	total = 0;
	
	scanf("%d",&n);
	createList(&L);
	
	dataCity temp[n];
	for (i=0;i<n;i++){
		scanf(" %s %d",&temp[i].city , &temp[i].value);

		addLast(temp[i].city,temp[i].value,&L);
	}
	int m;
	scanf("%d",&m);
	scanf(" %s",&nextC);
	char track[m][50];
	for(i=0;i<m;i++){
		scanf(" %s",&track[i]);
	}
	printf("\n\n");
	for(i=0;i<m;i++){
		nextCity(search(nextC,L),track[i],L);
		if(i == m-1){
			total += L.data[search(nextC,L)].elmt.value;
		}
	}
	// printElement(L);

	return 0;
}