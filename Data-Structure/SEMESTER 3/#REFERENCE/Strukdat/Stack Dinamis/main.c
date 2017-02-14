#include "header.h"

int main(){
 
    stack S1,S2;
 
    createStack(&S1);
    createStack(&S2);
	int i;
	int angka[5];
	for(i=0;i<4;i++){
		scanf("%d",&angka[i]);
	}
	push(angka[0],&S1);
	push(angka[1],&S2);
	popIsi(&S1,&S2);
	printf("s1 - ");printStack(S1);
	printf("s2 - ");printStack(S2);
	
	push(angka[2],&S2);
	push(angka[3],&S2);
	pop(&S2);
	popIsi(&S2,&S1);
	printf("s1 - ");printStack(S1);
	printf("s2 - ");printStack(S2);
	
    return 0;
}