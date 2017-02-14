#include "header.h"

int main(){
	tree T;
	int n;
	scanf("%d",&n);
	int i ;
	char parent[25];
	char child;
	char direction[25];
	char temp;
	int same = 0;
	for(i=0;i<n;i++){
		scanf(" %c %s %s",&child ,&parent, &direction);
		if(strcmp(parent,"null")==0 && strcmp(direction,"null")==0){
			makeTree(child,&T);
		}else{
			temp = parent[0];
			if(findSimpul(child,T.root) != NULL){
				same = 1;
			}
			if(strcmp(direction,"kanan")==0){
				addRight(child,findSimpul(temp,T.root));
			}else if(strcmp(direction,"kiri")==0){
				addLeft(child,findSimpul(temp,T.root));
			}
		}
	}
	if(wholeCheck(T.root)==1){
		printf("tidak lengkap ");
	}else{
		printf("lengkap ");
	}
	printf("dan ");
	if(same==1){
		printf("ada yang sama\n");
	}else{
		printf("tidak ada yang sama\n");
	}
	return 0;
}