#include "header.h"

/*
	MAKE TREE
*/
void makeTree(char c, tree *T){
	simpul *node;
	node = (simpul *) malloc(sizeof (simpul));
	
	node->info = c;
	node->right = NULL;
	node->left = NULL;
	(*T).root = node;
}

/*
	ADD
*/
//=== right ===//
void addRight(char c, simpul *root){
	count_root++;
	if(root->right == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node;
		node = (simpul *) malloc(sizeof (simpul));
		
		node->info = c;
		node->right = NULL;
		node->left = NULL;
		root->right = node;
	}else{
		printf("sub pohon kanan telah terisi\n");
	}
}
//=== left ===//
void addLeft(char c, simpul *root){
	count_root++;
	if(root->left == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node;
		node = (simpul *) malloc(sizeof (simpul));
		
		node->info = c;
		node->right = NULL;
		node->left = NULL;
		root->left = node;
	}else{
		printf("sub pohon kiri telah terisi\n");
	}
}

/*
	DEL
*/
//=== right ===//
void delRight(simpul *root){
	count_root--;
	if((root->right->right == NULL) && (root->right->left == NULL)){
		simpul *node = root->right;
		root->right = NULL;
		free(node);
	}else{
		printf("punteun teu tiasa dihapus da gaduh budak\n");
	}
}
//=== left ===//
void delLeft(simpul *root){
	count_root--;
	if((root->left->right == NULL) && (root->left->left == NULL)){
		simpul *node = root->left;
		root->left = NULL;
		free(node);
	}else{
		printf("punteun teu tiasa dihapus da gaduh budak\n");
	}
}

/*
	PRINT
*/
//=== preorder ===//
void printTreePreOrder(simpul *root){
	if(root != NULL){
		printf("%c", root->info);
		count1++;
		if(count1 < count_root){
			printf(" - ");
		}
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
}
//=== inorder ===//
void printTreeInOrder(simpul *root){
	if(root != NULL){
		printTreeInOrder(root->left);
		printf("%c", root->info);
		count2++;
		if(count2 < count_root){
			printf(" - ");
		}
		printTreeInOrder(root->right);
	}
}
//=== postorder ===//
void printTreePostOrder(simpul *root){
	if(root != NULL){
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%c", root->info);
		count3++;
		if(count3 < count_root){
			printf(" - ");
		}
	}
}

/*
	COPY
*/
void copyTree(simpul *root1, simpul **root2){
	if(root1 != NULL){
		(*root2) = (simpul *) malloc(sizeof (simpul));
		
		(*root2)->info = root1->info;
		
		//cek kiri
		if(root1->left != NULL){
			copyTree(root1->left, &(*root2)->left);
		}else{
			(*root2)->left = NULL;
		}
		
		//cek kanan
		if(root1->right != NULL){
			copyTree(root1->right, &(*root2)->right);
		}else{
			(*root2)->right = NULL;
		}
	}
}

/*
	ISEQUAL
*/
int isEqual(simpul *root1, simpul *root2){
	int hasil = 1;
	
	if((root1 != NULL)&&(root2 != NULL)){
		if(root1->info != root2->info){
			hasil = 0;
		}else{
			isEqual(root1->left, root2->left);
			isEqual(root1->right, root2->right);
		}
	}else{
		hasil = 0;
	}
	
	return hasil;
}