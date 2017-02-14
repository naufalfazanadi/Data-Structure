#include "header.h"
int main(){
	/* Declaring 5 Queue */
	queue Q1;
	queue Q2;
	queue Q3;
	queue Q4;
	queue Q5;
	/* Crete empty queue */
	createEmpty(&Q1);	
	createEmpty(&Q2);	
	createEmpty(&Q3);	
	createEmpty(&Q4);	
	createEmpty(&Q5);	
	
	/* Prompt user to fill 4 queue */
	int n;
	scanf("%d",&n);
	int i;
	char name[150];
	int spp;
	for(i=0;i<n;i++){
		scanf("%s",&name);
		scanf("%d",&spp);
		add(name,spp,&Q1);
	}
	for(i=0;i<n;i++){
		scanf("%s",&name);
		scanf("%d",&spp);
		add(name,spp,&Q2);
	}
	for(i=0;i<n;i++){
		scanf("%s",&name);
		scanf("%d",&spp);
		add(name,spp,&Q3);
	}
	for(i=0;i<n;i++){
		scanf("%s",&name);
		scanf("%d",&spp);
		add(name,spp,&Q4);
	}
	/* Process */
	/* Logic : same as looking for maximum value, we need a temporary pointer to wrap it up. */
	elemen *tempqyu;
	tempqyu = (elemen *) malloc (sizeof (elemen));

	do{
		/* We have to put temporary to 0 (for max) */
		tempqyu->elmt.spp = 0; 
		
		/* Compare every queue - temporary will change according to conditions */
		compareWith(tempqyu,&Q1);
		compareWith(tempqyu,&Q2);
		compareWith(tempqyu,&Q3);
		compareWith(tempqyu,&Q4);
		/* Del choosen queue */
		del(choosen); 
		
		/* Add into new queue */
		add(tempqyu->elmt.nama,tempqyu->elmt.spp,&Q5);

		/* looping until whole queue has been empty */
	}while(isEmpty(Q1) != 1 || isEmpty(Q2) != 1 || isEmpty(Q3) != 1 || isEmpty(Q4) != 1);
	 
	printQueue(Q5);
	return 0;
}



