#include "header.h"

int main(){
	graph G;
	createEmpty(&G);
	addSimpul('A',&G);
	addSimpul('B',&G);
	addSimpul('C',&G);
	addSimpul('E',&G);
	addSimpul('F',&G);
	addSimpul('G',&G);
	addJalur(findSimpul('B',G),findSimpul('A',G));
	addJalur(findSimpul('E',G),findSimpul('A',G));
	addJalur(findSimpul('G',G),findSimpul('A',G));
	addJalur(findSimpul('G',G),findSimpul('F',G));
	addJalur(findSimpul('F',G),findSimpul('E',G));
	addJalur(findSimpul('E',G),findSimpul('B',G));
	addJalur(findSimpul('C',G),findSimpul('B',G));
	char del;
	scanf(" %c",&del);
	printGraph(G);
	delSimpul(del,&G);
	printf("=============\n");
	printGraph(G);
	return 0;
}