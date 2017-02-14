#include "header.h"

int main(){
	graph G;
	createEmpty(&G);
	int n;
	scanf("%d",&n);
	int i;
	char from;
	char to;

	for(i=0;i<n;i++){
		scanf(" %c %c",&from ,&to);
		if(findSimpul(from,G) == NULL){
			addSimpul(from,&G);
		}
		if(findSimpul(to,G) == NULL){
			addSimpul(to, &G);
		}
		addJalur(findSimpul(to,G),findSimpul(from,G));
	}
	delSimpul('B',&G);
	printf("%d\n",countGraph(G));
	return 0;
}