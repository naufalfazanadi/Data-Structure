#include "header.h"
int main(){
	queue Q;
	createEmpty(&Q);	
	int i;
	char input[10][250];
	for(i=0;i<8;i++){
		scanf("%s",&input[i]);
	}
	printQueue(Q);
	add(input[0],&Q);
	add(input[1],&Q);
	addPriority(input[2],3,&Q);
	printQueue(Q);
	printf("-----------------\n");
	add(input[3],&Q);
	del(&Q);
	addPriority(input[4],1,&Q);
	printQueue(Q);
	printf("-----------------\n");
	
	del(&Q);
	del(&Q);
	add(input[5],&Q);
	add(input[6],&Q);
	addPriority(input[7],10,&Q);
	printQueue(Q);
	printf("-----------------\n");
	
	del(&Q);
	printQueue(Q);
	printf("-----------------\n");
	
	return 0;
}



