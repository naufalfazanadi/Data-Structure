#include "header.h"

int main(){
	stack S;
	stack S2;
	createStack(&S);
	createStack(&S2);
	/* Creating Stack */
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
	for(i=0;i<m;i++){
		scanf("%f",&inputs[i].numb);
	}
	printStack(S);
	printf("0\n");
	
	/* Tandain dengan -2 */
	/* I cant delete stack, sorry :( */
	if(S.top != NULL){
		elemen *elmt = S.top;
		
		while(elmt != NULL){
			for(i=0;i<m;i++){					
				if(elmt->elmt.numb == inputs[i].numb){
					elmt->elmt.numb = -2;
				}
			}
			
			elmt = elmt->next;
		}
	}
	int counter = 0;
	elemen *elmt = S.top;
	while(elmt != NULL){
		if(elmt->elmt.numb == -2){
			counter++;
		}else{
			printf("%.2f\n",elmt->elmt.numb);
		}
		elmt = elmt->next;
	}
	if(counter == countElement(S)){
		printf("stack kosong\n");
	}
	
	
	// for(i=0;i<m;i++){		
		// if(S.top != NULL){
			// elemen *elmt = S.top;
			
			// while(elmt != NULL){
				// if(elmt->elmt.numb ==inputs[i].numb){
					// if(elmt == S.top){
						// printf(".");
						// pop(&S);
						// elmt = elmt->next;
					// }
				// }
				
				// elmt = elmt->next;
			// }
		// }
	// }
	// hmpop(m,inputs,S,S2);
	
	return 0;
}