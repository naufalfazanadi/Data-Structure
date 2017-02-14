#include "header.h"

int main()
{
	list L;
	createList(&L);
	
	huruf input[100][100];
	scanf("%d", &n);
	kata input2[100];
	int i, j;
	for(i=0; i<n; i++){
		scanf("%s", &input2[i].nama);
		for(j=0; j<5; j++){
			scanf("%s", &input[i][j].word);
			//printf("%s\n", input[i][j].word);
		}
		addLastB(input2[i].nama, &L);
	}
	
		eBaris* elmt = L.first;
	for(i=0; i<n; i++){
			addLastK(input[i][0].word, elmt);
			addAfterK(elmt->col, input[i][1].word);
			addLastK(input[i][2].word, elmt);
			addFirstK(input[i][3].word, elmt);
			addFirstK(input[i][4].word, elmt);
			
			elmt = elmt->next;
	}
		
	
	printElement(L);
	
	
	
	return 0;
}