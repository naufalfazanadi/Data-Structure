#include "header.h"

int main(){
	stack S;
	stack S2;
	createStack(&S);
	createStack(&S2);
	
	int n;
	int i;
	scanf("%d",&n);
	notfloat input;
	for(i=0;i<n;i++){
		scanf("%f",&input.numb);
		push(input.numb,&S);
	}
	int m;
	scanf("%d",&m);
	notfloat inputs[m];
	printf("0\n");
	for(i=0;i<m;i++){
		scanf("%f",&inputs[i].numb);
	}
	printStack(S);
	for(i=0;i<m;i++){
		popProvition(inputs[i].numb,&S,&S2);
	}
	
	printStack(S);
	
	int j,k;
	return 0;
}