#include "header.h"

int main(){

	// n = 10;
	list L;
	// delAll(&L);
	createList(&L);
	printElement(L);
	
	printf("=====================\n");
	
	// printf("%d 1\n",L.first);
	addFirst("1403356","FaisalSA","A",&L);
	printElement(L);
	addAfter(L.first,"2","RANGGIANJING","C",&L);
	printElement(L);
	addAfter(L.first,"3","RANGGIBABI","D",&L);
	printElement(L);
	
	printf("=====================\n");

	return 0;
}