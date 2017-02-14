#include "header.h"

int main(){
	tree T;
	
	cr = 1;
	c1 = 0;
	c2 = 0;
	c3 = 0;
	
	//=== INPUT ===//
	char huruf1;
	char huruf2;
	char huruf3;
	char huruf4;
	char huruf5;
	char huruf6;
	char huruf7;
	char huruf8;
	char huruf9;
	char huruf10;
	char huruf11;
	char huruf12;
	char huruf13;
	char huruf14;
	char huruf15;
	scanf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c",&huruf1,&huruf2,&huruf3,&huruf4,&huruf5,&huruf6,&huruf7,&huruf8,&huruf9,&huruf10,&huruf11,&huruf12,&huruf13,&huruf14);
		
	//=== PROSES ===//
	makeTree(huruf1, &T);
	addLeft(huruf2,T.root);
	addRight(huruf3,T.root);
	addLeft(huruf4,T.root->left);
	addRight(huruf5,T.root->left);
	addRight(huruf6,T.root->right);
	addLeft(huruf7,T.root->left->left);
	addRight(huruf8,T.root->left->left);
	addRight(huruf9,T.root->left->right);
	addLeft(huruf10,T.root->right->right);
	addRight(huruf11,T.root->right->right);
	addLeft(huruf12,T.root->left->left->right);
	addRight(huruf13,T.root->left->left->right);
	addLeft(huruf14,T.root->right->right->left);
	
	//=== OUTPUT ===//
	printf("Pre\n");
	printTreePreOrder(T.root);
	delLeft(T.root->left->left->right);//L Hilang
	printf("\n");
	
	printf("In\n");
	printTreeInOrder(T.root);
	delRight(T.root->left->right);//I Terhapus
	printf("\n");
	
	printf("Post\n");
	printTreePostOrder(T.root);
	printf("\n");
	
	return 0;
}