#include "header.h"

int main(){
	stack S;
	int i;
	createStack(&S);
	char a[5];
	for(i=0;i<5;i++){
		scanf(" %c",&a[i]);
	}
	push(a[0],&S);
	push(a[1],&S);
	printStack(S);
	push(a[2],&S);
	push(a[3],&S);
	printStack(S);
	pop(&S);
	pop(&S);
	push(a[4],&S);
	printStack(S);
	
	return 0;
}