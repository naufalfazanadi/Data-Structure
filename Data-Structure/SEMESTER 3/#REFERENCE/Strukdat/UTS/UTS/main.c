//main
#include "header.h" 

int main(){
	
	list L;
	createList(&L);
	int n,i;
	char puzzle[500];
	/* Prompt user to input n */
	scanf("%d",&n);
	for(i=0;i<n;i++){
		/* Prompt user to input fruit ( name,price,vitamin content */
		scanf("%s",&puzzle);
		/* Add List */
		if(isNull(puzzle[0],L) != NULL){
			addLastB(puzzle[0],&L);
		}
	}
	int m;
	scanf("%d",&m);
	int input[500], input2[500];
	for(i=0;i<m;i++){
		scanf("%s %s",&input,&input2);
		if(isNull(puzzle[0],
	}
	
		
	printElement(L);
	return 0;
}