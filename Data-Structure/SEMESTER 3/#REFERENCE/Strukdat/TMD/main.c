#include "header.h"

int main(){
	/* Declare Tree */
	tree T;
	int i;
	int n;
	int m;
	int j;
	char inputString[100];
	family tempInput;
	
	
	/* Make Tree awalmula */
	makeTree("awalmula",&T);
	//================
	
	/* INPUT PHASE */
	scanf("%d",&n);
	
	/*
	 * Split String into 2 pieces.
	 * Find parent simpul to get the pointer.
	 * Adding child into tree.
	 */
	for(i=0;i<n;i++){
		scanf("%s",&inputString);
		if(strcmp(inputString,"awalmula#null")!=0){
			/* Skip the first query */
			tempInput = splitString(inputString);
			if(findSimpul(tempInput.parent, T.root) != NULL){
				addChild(tempInput.child,(findSimpul(tempInput.parent, T.root)));
			}			
		}else{
			
		}
	}
	/* Visitation */
	scanf("%d",&m);
	char kids[m][100];
	for(i=0;i<m;i++){
		scanf("%s",&kids[i]);
	}
	/* PRINT SECTION | before visitation */
	/*
	 * Reset len (space indentation) for every level.
	 * Define / Refine new length based on current tree.
	 * Print tree pre order (Depictation with indetation method)
	 */
	resetLen();
	refineLength(T.root,0);
	printTreePreOrder(T.root,0,0);
	printf("\n");
	
	/* VISIT SECTION */
	/*
	 * Define inx for save length of the path taken.
	 * Visit kids from current tree.
	 * Save the final route for every kids.
	 * Print every route by route.
	 */
	simpul *route[m][100]; //for save route every kids visitation.
	for(i=0;i<m;i++){
		inx[i] = 0;
		stats = 0;
		visitSimpul(kids[i],T.root, route[i],0,i);
		for(j=0;j<inx[i];j++){
			printf("%s - ",route[i][j]->name);
		}
		printf("%s\n",kids[i]);
	} 
	/* DELETE SECTION */
	/*
	 * Delete every kid by kid from highest level until lvl 1.
	 * We need (var) route to delete whole kids.
	 * Delete child from every parent until NULL.
	 * del(procedure) process is delete child for every parent with delete first method.
	 */
	for(i=0;i<m;i++){
		for(j=inx[i]-1;j>0;j--){
			while(route[i][j]->child != NULL){
				/* del until parent haven't child anymore */
				/* I hope no zombie again XD */
				del(route[i][j]);
			}
		}
		/* Exception for parent in lvl 1, just delete 1 tree, not whole child */
		delChild(route[i][1]->name,T.root);
	}
	/* PRINT SECTION | After visitation */
	/*
	 * Reset len (space indentation) for every level.
	 * Define / Refine new length based on current tree.
	 * Print tree pre order (Depictation with indetation method)
	 */
	printf("\n");
	resetLen();
	refineLength(T.root,0);
	printTreePreOrder(T.root,0,0);
	
	return 0;
	
}