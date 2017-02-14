#include "header.h" //panggil kepala(header)
 
int main(){
 
    list L;
    createList(&L);
	addLast("1403356","Faisal Syaiful anwar","12",&L);
	addLast("1403356","Faisal Syaiful anwar","13",&L);
	printElement(L);
    return 0;
}
