#include "header.h" //panggil kepala(header)
 
int main(){
 
    list L;
    createList(&L);
	int n,i;
	scanf("%d",&n);
	char word[200];
	for(i=0;i<n;i++){
		scanf(" %s",&word);
		addLast(word,&L);
	}
	// mF(&L);
	moveList(&L);
	printElement(L);
    return 0;
}
