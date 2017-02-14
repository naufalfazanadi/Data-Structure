#include "header.h"

int main(){

	list L;
	createList(&L);	 //creating list
	int i;
	int n;
	scanf("%d",&n);
	char input[250];
	for(i=0;i<n;i++){
		scanf(" %s",&input);
		addLast(input,&L); //adding last
	}
	check(L);
	return 0;
}