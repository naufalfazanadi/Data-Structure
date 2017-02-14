#include "header.h"

int main(){
	/* Make Tree */
	tree T;
	/* Program Variable */
	int n,i;
	
	char child,
		 parent[50],
		 direction[50];
	
	/* Prompt user to input n */
	scanf("%d",&n);
	
	/* Prompt user to input query (re: tree data)  */
	for(i=0;i<n;i++){
		/* I have to set parent to string, because first query is 'null' */
		scanf(" %c %s %s",&child ,&parent, &direction); 
		
		if(strcmp(direction,"null")==0){
			/* Provition for first query */
			makeTree(child,&T);
		}else{
			/* Taking first char, because this tree is tree of char */ 
			if(strcmp(direction,"kanan")==0){
				addRight(child,findSimpul(parent[0],T.root));
			}else if(strcmp(direction,"kiri")==0){
				addLeft(child,findSimpul(parent[0],T.root));
			}
		}
	}
	/* problem checked things */
	/* we have to count if whole tree has 2 child and compare with this*/
	int provition;
	scanf("%d",&provition);
	
	/* using global variable (result) to count whole tree */
	/* because i dont want to add new parameter :D */
	result = 0;
	isTwoChild(T.root);

	if(result >= provition){
		/* if result greater than selected provition */
		printf("ada\n");
	}else{
		printf("tidak ada\n");
	}
	return 0;
}