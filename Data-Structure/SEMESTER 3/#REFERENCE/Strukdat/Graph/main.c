#include "header.h"

int main(){
	graph G;
	createEmpty(*G);
	
	int n;
	int i;
	scanf("%d",&n);
	char left,right;
	for(i=0;i<n;i++){
		scanf(" %c",&left);
		scanf(" %c",&right);
		if(findSimpul(left,G) == NULL){
			addSimpul(left,&G);
		}
		if(findSimpul(right,G) == NULL){
			addSimpul(right,&G);
		}
		addJalur
	}
	
	return 0;
}