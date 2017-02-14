/* Saya Faisal SA tidak melakukan kecurangan seperti yang telah dispesifikasikan pada mata kuliah Struktur Data dalam mengerjakan Queue Trilili S2, jika saya melakukan kecurangan maka Allah/Tuhan adalah saksi saya, dan saya bersedia menerima hukumanNya. Aamiin. */
#include "header.h"
int main(){
	/* Creating queue */
	queue Q;
	createEmpty(&Q);
	int i;
	float inputF;
	int number;
	scanf("%d",&n);
	for(i=0 ; i<n ; i++){
		scanf("%f",&inputF);
		scanf("%d",&number);
		/* Condition if number isn't priority */
		if(number == -222){
			add(inputF,&Q);
		}else{
			addPriority(inputF,number,&Q);
		}
	}
	/* Prompt user to input max process */
	int maxQ;
	scanf("%d",&maxQ);
	
	printQueue(Q);
	printf("0\n");
	
	int j;
	for(j=0;j<maxQ;j++){
		del(&Q);
	}
	printQueue(Q);
	return 0;
}



