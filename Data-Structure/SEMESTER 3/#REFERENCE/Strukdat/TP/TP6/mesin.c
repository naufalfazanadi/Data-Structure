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

void push(char nim[],char nama[],stack *S){
	/* 
		Push the element into the list.
	*/
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.code,nim);
	strcpy(elmt->elmt.name,nama);
	if(isEmpty(*S) == 1){
		(*S).top = elmt;
	}else{		
		elmt->next = (*S).top;
		(*S).top = elmt;
		elmt = NULL;
	}
}

void pop(stack *S){
	
	if((*S).top != NULL){
		if(countElement(*S) == 1){
			(*S).top = NULL;
		}else{			
			elemen *elmt = (*S).top;
			(*S).top = (*S).top->next;
			elmt->next = NULL;
			free(elmt);
		}
	}
}

void printStack(stack S){
	if(S.top != NULL){
		elemen *elmt = S.top;
		
		int i = 1;
		while(elmt != NULL){
			printf("%d\n",i);
			printf("%s\n",elmt->elmt.code);
			printf("%s\n",elmt->elmt.name);
			
			elmt = elmt->next;
			i++;
		}
	}else{
		printf("stack kosong\n");
	}
}

/* 
 *Function will check between 2 string.
 *@param books code.
 *@param borrower key.
 *		@return true or false
 */
int isSame(char primary[],char key[]){
	/* 
		Condtional check if strings are same.
		e.g. BK == BK , BK != EG
	*/
	if(strcmp(primary,key)==0){
		return 1;
	}else{
		return 0;
	}
}