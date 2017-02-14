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
//=== right ===//
void addRight(char c, simpul *root){
	cr++;
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
//=== left ===//
void addLeft(char c, simpul *root){
	cr++;
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
//=== right ===//
void delRight(simpul *root){
	cr--;
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
//=== left ===//
void delLeft(simpul *root){
	cr--;
	if(root->left != NULL){
		/* check if left-child is available */
		if((root->left->right == NULL) && (root->left->left == NULL)){
			/* check if child didnt have any child */
			simpul *node = root->left;
			root->left = NULL;
			free(node);
		}else{
			printf("punteun teu tiasa dihapus da gaduh budak\n");
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
//=== preorder ===//
void printTreePreOrder(simpul *root){
	if(root != NULL){
		printf("%c", root->info);
		c1++;
		if(c1 < cr){
			printf(" - ");
		}
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
//=== inorder ===//
void printTreeInOrder(simpul *root){
	if(root != NULL){
		printTreeInOrder(root->left);
		printf("%c", root->info);
		c2++;
		if(c2<cr){
			printf(" - ");
		}
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
//=== postorder ===//
void printTreePostOrder(simpul *root){
	if(root != NULL){
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%c", root->info);
		c3++;
		if(c3<cr){
			printf(" - ");
		}
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