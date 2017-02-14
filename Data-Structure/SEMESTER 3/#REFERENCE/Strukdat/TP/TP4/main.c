#include "header.h"
int main(){
    list L;
    createList(&L); //creating list
    int n,m,i;
    char name[50];
	//prompt user to input n
    scanf("%d",&n); 
    for(i=0;i<n;i++){
        scanf("%s",&name);
		/* Adding list */
        addLast(name,&L);
    }
	
	scanf("%d",&m);
	char command[m][300];
	cntWhen = 0;
	for(i=0;i<m;i++){
		/* input sentence (pita) */
		scanf(" %299[^\n]s",&command[i]);
		checkCommand(command[i],&L);
	}
    printElement(L); // print list
 
    return 0;
}
