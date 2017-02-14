#include "header.h"

void createStack(stack *S){
	(*S).top = -1;
}

int isEmpty(stack S){
	int hasil = 0;
	
	if(S.top == -1){
		hasil = 1;
	}
	return hasil;
}

int isFull(stack S){
	int hasil = 0;
	if(S.top == MAX_STACK -1){
		hasil = 1;
	}
	return hasil;
}

void push(char nim, stack *S){
	if(isFull(*S) == 1){
		printf("Stack Overflow\n");
	}else{
		if(isEmpty(*S) == 1){
			(*S).top = 0;
		}else{
			(*S).top = (*S).top + 1;
		}
		(*S).data[(*S).top].huruf = nim;
	}
}

void pop(stack *S){
	if((*S).top == 0){
		(*S).top = -1;
	}else{
		if((*S).top != -1){
			(*S).top = (*S).top - 1;
		}
	}
}

/**
 *Return container b4 pop the stack
 *@param current stack.
 *		@return container.
 */
// nilaiMatkul getPop(stack *S){
	// nilaiMatkul temp;
	// strcpy(temp.nim,(*S).data[(*S).top].nim);
	// strcpy(temp.nama,(*S).data[(*S).top].nama);
	// temp.nilai = (*S).data[(*S).top].nilai;
	// if((*S).top == 0){
		// (*S).top = -1;
	// }else{
		// if((*S).top != -1){
			// (*S).top = (*S).top - 1;
		// }
	// }
	
	// return temp;
// }

void printStack(stack S){
	if(S.top != -1){
		int i;
		for(i=S.top;i>=0;i--){
			printf("%c\n",S.data[i].huruf);
		}
	}else{
		printf("stack kosong\n");
	}
}