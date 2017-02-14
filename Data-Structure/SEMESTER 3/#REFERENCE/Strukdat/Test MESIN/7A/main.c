#include "header.h"
int main(){
	queue Q;
	createEmpty(&Q);
	int i;
	char input[15][250];
	for(i=0;i<9;i++){
		scanf("%s",&input[i]);
	}
	
	printQueue(Q);
	printf("-----------------\n");
	add(input[0],&Q);
	add(input[1],&Q);
	addPriority(input[2],2,&Q);
	printQueue(Q);
	printf("-----------------\n");
	add(input[3],&Q);
	del(&Q);
	del(&Q);
	addPriority(input[4],3,&Q);
	printQueue(Q);
	printf("-----------------\n");
	
	del(&Q);
	del(&Q);
	add(input[5],&Q);
	add(input[6],&Q);
	addPriority(input[7],1,&Q);
	printQueue(Q);
	printf("-----------------\n");
	
	del(&Q);
	add(input[8],&Q);
	
	printQueue(Q);
	printf("-----------------\n");
	return 0;
}



