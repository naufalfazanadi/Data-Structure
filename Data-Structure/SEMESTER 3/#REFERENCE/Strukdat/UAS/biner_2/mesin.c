#include "header.h"

/*
 * MAKE TREE.
 * Place Root above tree.
 */
void makeTree(char c, tree *T){
	simpul *node;
	node = (simpul *) malloc(sizeof (simpul));
	
	node->info = c;
	node->right = NULL;
	node->left = NULL;
	/* Place root above tree. */
	(*T).root = node;
}

/*
 * Add right
 * Adding another node(child) right after the parent.
 * @param input character.
 * @param current root.
 */
void addRight(char c, simpul *root){
	if(root->right == NULL){
		/*jika sub pohon kanan kosong*/
		simpul *node;
		node = (simpul *) malloc(sizeof (simpul));
		
		node->info = c;
		node->right = NULL;
		node->left = NULL;
		root->right = node;
	}else{
		/* jika telah terisi */
		printf("sub pohon kanan telah terisi\n");
	}
}

/*
 * Add left
 * Adding another node(child) left after the parent.
 * @param data simpul.
 * @param current root.
 */
void addLeft(char c, simpul *root){
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
 * Delete Right
 * Delete parent's child.
 * Child should'nt have child too.
 * @param current root.
 */
void delRight(simpul *root){
	if(root->right != NULL){
		/* check if right-child is available */
		if((root->right->right == NULL) && (root->right->left == NULL)){
			/* check if child didnt have any child */
			simpul *node = root->right;
			root->right = NULL;
			free(node);
		}else{
			printf("punteun teu tiasa dihapus da gaduh budak\n");
		}
	}
		
}

/*
 * Delete Left.
 * Delete parent's child.
 * Child should'nt have child too.
 * @param current root.
 */
void delLeft(simpul *root){
	if(root->left != NULL){
		/* check if left-child is available */
		if((root->left->right == NULL) && (root->left->left == NULL)){
			/* check if child didnt have any child */
			simpul *node = root->left;
			root->left = NULL;
			free(node);
		}
	}
}

/*
 * Print tree Pre Order..
 * Recursive.
 * Parent, left-child, right-child.
 * stop while root equals NULL.
 * @param current root.
 */
void printTreePreOrder(simpul *root){
	if(root != NULL){
		printf("%c\n", root->info);

		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
}

/*
 * Print tree Pre In order
 * Recursive.
 * Left-child, parent, right-child.
 * stop while root equals NULL.
 * @param current root.
 */
void printTreeInOrder(simpul *root){
	if(root != NULL){
		printTreeInOrder(root->left);
		printf("%c", root->info);
		printTreeInOrder(root->right);
	}
}

/*
 * Print tree Post Order..
 * Recursive.
 * Parent, left-child, right-child.
 * stop while root equals NULL.
 * @param current root.
 */
void printTreePostOrder(simpul *root){
	if(root != NULL){
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%c", root->info);
	}
}

/*
 * Copy tree.
 * Duplicate root to another root.
 * recursive, stop while root1 equal NULL.
 * @param current root.
 * @param new root.
 */
void copyTree(simpul *root1, simpul **root2){
	if(root1 != NULL){
		(*root2) = (simpul *) malloc(sizeof (simpul));
		
		(*root2)->info = root1->info;
		
		/* Check left */
		if(root1->left != NULL){
			copyTree(root1->left, &(*root2)->left);
		}else{
			(*root2)->left = NULL;
		}
		
		/* Check right */
		if(root1->right != NULL){
			copyTree(root1->right, &(*root2)->right);
		}else{
			(*root2)->right = NULL;
		}
	}
}

/*
 * Find Selected char you want to.
 * Function with recursive.
 * @param selected char.
 * @param current node.
 * 		@return selected node.
 */
simpul* findSimpul(char cari,simpul* root){
	simpul* hasil = NULL;
	if(root->info == cari){
		/* conditional if current node equals selected char */
		hasil = root;
	}else{
		if(root->left != NULL && hasil == NULL){
			/* Recursive left */
			hasil = findSimpul(cari,root->left);
		}
		if(root->right != NULL && hasil == NULL){
			/* recursive right */
			hasil = findSimpul(cari,root->right);
		}
	}
	return hasil;
}

/*
 * check if current node has 2 child below it.
 * mark with not equals NULL.
 * @param current node.
 * 		@return TRUE or FALSE.
 */
int isTwo(simpul *root){
	if((root->left != NULL) && (root->right != NULL)){
		/* return true if provition accepted */
		return 1;
	}else{
		return 0;
	}
}

/*
 * Check Whole Child to get selected node with provition.
 * used result variable (global) to count this.
 * @param current node
 */
void isTwoChild(simpul *root){
	if(isTwo(root)==1){
		/* if function is TRUE */
		result++;
	}
	if(root->left != NULL){
		/* recursive left */
		isTwoChild(root->left);
	}
	if(root->right != NULL){
		/* recursive right */
		isTwoChild(root->right);
	}
}
