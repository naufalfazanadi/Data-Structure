#include "header.h"

int main(){

	n = 10;
	list L;
	// delAll(&L);
	createList(&L);
	// printElement(L);
	
	printf("=====================\n");
	
	// printf("%d 1\n",L.first);
	addFirst("1403356","FaisalSA","A",&L);
	// addFirst("1403356","FaisalSA","A",&L);
	// addFirst("1403356","FaisalSA","A",&L);
	
	
	addAfter(L.first,"1403333","FikryA","C",&L);
	// addAfter(L.first,"1403333","FikryA","C",&L);
	// addAfter(L.first,"1403333","FikryA","C",&L);
	// addAfter(0,"1403333","FikryA","C",&L);
	// printf("%d 2\n",L.first);	
	
	// addAfter(5,"1403123","AsuA","X",&L);
	// printf("%d 3\n",L.first);	
	// printElement(L);
	
	// printf("===================== %d\n",L.first);
	// delLast(&L);
	// printf("%d 1\n",L.first);	
	
	// delAfter(L.first, &L);
	// printf("%d 2\n",L.first);	
	
	// delFirst(&L);
	// printf("%d 3\n",L.first);	
	
	printElement(L);
	
	printf("=====================\n");

	return 0;
}