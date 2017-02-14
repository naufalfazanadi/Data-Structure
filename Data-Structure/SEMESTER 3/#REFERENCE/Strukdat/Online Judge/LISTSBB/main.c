#include "header.h" //panggil kepala(header)
 
int main(){
 
    list L;
    createList(&L);
    int n,i;
    char masuk[30][30];
    scanf("%d",&n); // banyak bilangan pecahan
    for(i=0;i<n;i++){
        scanf("%s",&masuk[i]);
        addLast(masuk[i],&L); // memasukkan pecahan di akhir
    }
	for(i=0;i<n;i++){
		addLast(masuk[i],&L);
	}
 
	reverseString(&L);
    printElement(L); // print list
 
    return 0;
}
