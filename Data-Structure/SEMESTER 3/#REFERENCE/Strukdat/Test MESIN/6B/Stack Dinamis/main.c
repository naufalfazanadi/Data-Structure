#include "header.h"

int main(){
	stack S1;
	stack S2;
	createStack(&S1);
	createStack(&S2);
	int i;
	int angka[5];
	for(i=0;i<4;i++){
		scanf("%d",&angka[i]);
		printf("%d",angka[i]);
	}
	push(angka[0],&S1);
	// push(angka[1],&S2);
	// printf("%d\n",countElement(S1));
	// printf("%d\n",countElement(S2));
	// popIsi(&S1,&S2);
	// printStack(S1);
	// printStack(S2);
	
	// push(a[2],&S2);
	// push(a[3],&S2);
	// pop(&S2);
	// popIsi(&S2,&S1);	
	// printStack(S1);
	// printStack(S2);
	return 0;
}