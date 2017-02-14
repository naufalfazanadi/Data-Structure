#include "header.h"

int main(){
	/* 
		Creating dynamic stack 
	*/
	stack S;
	createStack(&S);

	
	form input;
	int n,
		i,
		disbanded;
	char key[5];
	
	/* 
		Prompt user to fill n (number of book)
	*/
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		/* 
			Input -> push -> Replace(input) -> repeat 
		*/
		scanf("%s",&input.code);
		scanf("%s",&input.name);
		/* 
			Push the package of books into stack.
		*/
		push(input.code,input.name,&S);
	}
	/* 
		Prompt the key for comparing with code.
		The key MUST be 2 character.
	*/
	scanf("%s",&key);
	
	/* 
		Initialization
		- number of books will disbanded from stack with 0. 
	*/
	disbanded = 0;
		
	/* 
		Conditional check if stack is empty 
	*/
	if(S.top != NULL){
		/* 
			Create loop for each element of stack.
		*/
		elemen *elmt = S.top;
		
		while(elmt != NULL){
			/* 
				Fill the temporary variable for take a 2 character lead.
			*/
			char temp[]={elmt->elmt.code[0],elmt->elmt.code[1],'\0'};
			
			/* 
				conditional check if function isSame is true or false
				-Return true(1) if code is definitely same with key.
					-Print the books are eligible
				-Return false(0) if code isn't same with key.
					-Increment the variable, for counting book that has been disbanded.
			*/
			if(isSame(temp,key) == 1){
				printf("%s\n",elmt->elmt.name);
			}else{
				disbanded += 1;
			}
			/* 
				You have to next the loop.. XD
				Increment section.
			*/
			elmt = elmt->next;
		}
		/* 
			The program must be print this variable for counting the disbanded books.
		*/
		printf("%d\n",disbanded);
	}
	/* 
		Return the success code, 0.
	*/
	return 0;
}