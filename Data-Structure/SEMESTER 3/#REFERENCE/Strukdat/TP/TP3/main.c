#include "header.h"

int main(){

	int i,j;
	list L;
	
	scanf("%d",&n); //number of book
	createList(&L);
	dataBook input;
	for(i=0;i<n;i++){
		scanf(" %s %d %d",&input.title,&input.price,&input.rating);
		addLast(input.title,input.price,input.rating,&L); //adding into list
	}
	
	int currentMoney;
	scanf("%d",&currentMoney);
	
	//priority books
	int m;
	scanf("%d",&m);
	dataBook prior[m]; //using array instead of list
	
	for(i=0;i<m;i++){
		scanf("%s %d",&prior[i].title,&prior[i].rating);
	}
	
	combineBook.total = 0;
	for(i=0;i<m;i++){
		temp = 0; //temp variable for temporary price combination.
		printf("%d\n",i+1);
		
		//if initial element equals to final element.
		//thats mean mata will buy books with the same rating.
		if((search(prior[i].title,L)) == (search2(prior[i].rating,L))){
			sameRate(prior[i].rating,L);
		}
		//normal case
		else{
			direction(search(prior[i].title,L),search2(prior[i].rating,L),L);
		}
		//check every money for every combination.
		checkMoney(i+1,currentMoney);
	}
	printf("Kombinasi buku yang dapat dibeli nomor: %d\nTotal : %d\n",combineBook.number,combineBook.total);
	return 0;
}