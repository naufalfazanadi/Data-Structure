//main
#include "header.h"

int main(){
	/* Creating list of list */
	list L;
	createList(&L);

	int n,i;
	scanf("%d",&n); //total band

	/* I was scare, for run Error:( 500 is enough right ? XD */
	char input1[500];
	char input2[500];
	char input3[500];
	int input4;
	for(i=0;i<n;i++){
		scanf(" %s %s",&input1 , &input2);
		addLastB(input1,input2,&L); //adding band and category into list->row.
	}
	int m;
	scanf("%d",&m); //instruction
	for(i=0;i<m;i++){
		scanf(" %s",&input1);
		scanf(" %s",&input2);
		scanf(" %s",&input3);

		if(strcmp(input1,"INSERT")==0){ //INSERT FUNCTION
 			scanf("%d",&input4);
			if(isAvail(input2,L) != NULL){
				//checking if band, is already exist.
				addLastK(input3,input4,isAvail(input2,L));
			}
		}
		else if(strcmp(input1,"DELETE")==0){
			if(isAvail(input2,L) != NULL){
				// check if band, is exist
				if(isExist(input3,isAvail(input2,L)) != NULL){
					/* check if aspec, is exist too */
					/* if exist, then we can delete it! */
					if(getPrev(input3,isAvail(input2,L)) == isAvail(input2,L)->col){
						delFirstK(isAvail(input2,L));
					}else{
						delAfterK(getPrev(input3,isAvail(input2,L)),isAvail(input2,L));
					}
				}
			}
		}
		else if(strcmp(input1,"UPDATE")==0){
			scanf(" %d",&input4);
			if(isAvail(input2,L) != NULL){
				/* if we want to update some aspect, we need to check that band or aspect is exist */
				if(isExist(input3,isAvail(input2,L)) != NULL){
					isExist(input3,isAvail(input2,L))->elmt.score = input4;
				}
			}
		}
	}
	/* SORT & PRINT */
	selectionSort(&L);
	delAllB(&L);
	printRanking(L);
	return 0;
}
