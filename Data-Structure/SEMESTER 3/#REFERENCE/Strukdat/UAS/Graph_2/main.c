#include "header.h"

int main(){
	graph G;
	createEmpty(&G);
	
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
		addJalur(findSimpul(right,G),findSimpul(left,G));
	}
	
	printGraph(G);
	int m;
	scanf("%d",&m);
	char string[100];
	char result[m][100];
	for(i=0;i<m;i++){
		scanf("%s",&string);
		if(cek(string,G) == 1){
			strcpy(result[i],"ada");
		}else{
			strcpy(result[i],"tidak ada");
		}
	}
	for(i=0;i<m;i++){
		printf("%s\n",result[i]);
	}
	
	
	
	return 0;
}