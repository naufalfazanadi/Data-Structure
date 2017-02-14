#include "header.h"

int main(){
	tree T;
	makeTree('A', &T);
	addChild('B', T.root);
	addChild('C', T.root);
	addChild('D', T.root);
	
	simpul *node = findSimpul('B', T.root);
	if(node != NULL){
		addChild('E', node);
		addChild('F', node);
	}
	
	node = findSimpul('C', T.root);
	if(node != NULL){
		addChild('G', node);
	}
	
	node = findSimpul('D',T.root);
	if(node != NULL){
		addChild('H', node);
		addChild('I', node);
		addChild('J', node);
	}
	
	node = findSimpul('J',T.root);
	if(node != NULL){
		addChild('K', node);
		addChild('L', node);
		addChild('M', node);
	}
	printf("====================\n");
	printf("PreOrder\n");
	printTreePreOrder(T.root);
	printf("\n====================\n");
	printf("PostOrder\n");
	printTreePostOrder(T.root);
	printf("\n====================\n");
	
	tree T2;
	copyTree(T.root, &T2.root);
	if(isEqual(T.root, T2.root)==1){
		printf("pohon sama\n");
	}else{
		printf("pohon tidak sama\n");
	}
	printf("TREE 1\n");
	printTreePreOrder(T.root);
	printf("\nTREE 2\n");
	printTreePreOrder(T2.root);
	
	node = findSimpul('J', T.root);
	if(node != NULL){
		delChild('K',node);
		delChild('L',node);
		delChild('M',node);
	}
	printf("====================\n");
	printf("PreOrder setelah dihapus\n");
	printTreePreOrder(T.root);
	printf("\n====================\n");
	
	return 0;
}