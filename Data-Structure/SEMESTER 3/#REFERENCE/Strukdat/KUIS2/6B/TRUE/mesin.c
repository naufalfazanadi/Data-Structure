#include "header.h"
void createStack(stack *S){
	(*S).top = NULL;
}

int isEmpty(stack S){
	int hasil = 0;
	if(S.top == NULL){
		hasil = 1;
	}
	return hasil;
}

int countElement(stack S){
	int hasil = 0;
	
	if(S.top != NULL){
		elemen *elmt;
		elmt = S.top;
		
		while(elmt != NULL){
			hasil += 1;
			
			elmt = elmt->next;
		}
	}
	return hasil;
}

void push(float numb,stack *S){
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));
	elmt->elmt.numb = numb;
	elmt->next = (*S).top;
	(*S).top = elmt;
	elmt = NULL;
}

void pop(stack *S){
	
	if((*S).top != NULL){
		elemen *elmt = (*S).top;
		(*S).top = (*S).top->next;
		elmt->next = NULL;
		free(elmt);
	}
}

elemen* getPop(stack *S){
	
	elemen* temp = NULL;
	if((*S).top != NULL){
		if(countElement(*S) == 1){
			temp = (*S).top;
			(*S).top = NULL;
		}else{
			elemen *elmt = (*S).top;
			temp = elmt;
			(*S).top = (*S).top->next;
			elmt->next = NULL;
			free(elmt);
		}
	}
	return temp;
}

void printStack(stack S){
	if(S.top != NULL){
		elemen *elmt = S.top;
		while(elmt != NULL){
			printf("%.2f\n",elmt->elmt.numb);
			
			elmt = elmt->next;
		}
	}else{
		printf("stack kosong\n");
	}
}

void popIsi(stack *S1,stack *S2){
	elemen* elmt = getPop(S1);
	
	elmt->next = (*S2).top;
	(*S2).top = elmt;
	elmt = NULL;
}


elemen *getIndex(stack *S){
	if((*S).top != NULL){		
		elemen *elmt = (*S).top;
		elemen *ret = (*S).top;
		
		if(countElement(*S) == 1){
			(*S).top = NULL;
		}else{
			(*S).top = (*S).top->next;
			elmt->next = NULL;
		}
		
		free(elmt);
		return ret;
	}
}

void popProvition(float numb, stack *S, stack *S2){
	elemen *elmt = (*S).top;
	int i ;
	int x = countElement(*S);
	for(i=0;i<x;i++){
		elemen *elmt = getIndex(S);
		if(elmt->elmt.numb != numb){
			push(elmt->elmt.numb, S2);
		}
	}
	pc(S,S2);
}

void pc(stack *S,stack *S2){
	elemen *elmtx = (*S2).top;
	while(elmtx != NULL){
		push(elmtx->elmt.numb, S);
		
		elmtx = elmtx->next;
	}
	int x2 = countElement(*S2);
	for(i=0;i<x2;i++){
		pop(S2);
	}
}