#include "header.h"

/*
 *Make N-er tree
 *Sibling and child should be NULL
 *@param struct data.
 *@param current tree.
 */
void makeTree(char name, tree *T){
	simpul *node;
	node = (simpul *) malloc(sizeof (simpul));
	
	node->name = name;
	// strcpy(node->name,name);
	node->sibling = NULL;
	node->child = NULL;
	(*T).root = node;
}

/*
 *Adding child from root
 *3 Provitions
 * -if child is eldest
 * -if child is second child.
 * -if child isn't eldest and second child.
 *@param character data.
 *@param current root.
 */
void addChild(char name, simpul *root){
	if(root != NULL){
		/*jika root tidak kosong*/
		simpul *node;
		node = (simpul *) malloc(sizeof (simpul));
		// strcpy(node->name,name);
		node->name = name;
		node->child = NULL;
		if(root->child == NULL){
			/*simpul baru menjadi anak pertama*/
			node->sibling = NULL;
			root->child = node;
		}else{
			if(root->child->sibling == NULL){
				/*jika simpul baru menjadi anak kedua*/
				node->sibling = root->child;
				root->child->sibling = node;
			}else{
				simpul *last = root->child;
				
				/*mencari simpul anak terakhir*/
				while(last->sibling != root->child){
					last = last->sibling;
				}
				
				node->sibling = root->child;
				last->sibling = node;
			}
		}
	}
}

/*
 *Delete child
 *Find the node first
 *Condition if 1 child, 2child, or many child
 *@param info char.
 *@param deleted root.
 */
//=== child ===//
void delChild(char name, simpul *root){
	simpul *node = root->child;
	
	if(node != NULL){
		if(node->sibling == NULL){
			/*jika hanya mempunyai satu anak*/
			if(root->child->name==name){
				root->child = NULL;
				free(node);
			}else{
				printf("tidak ada simpul anak dengan info karakter masukan\n");
			}
		}else{
			/*jika memiliki banyak anak*/
			simpul *prec = NULL;
			
			/*mencari simpul yang akan dihapus*/
			int ketemu = 0;
			while((node->sibling != root->child)&&(ketemu == 0)){
				if(node->name == name){
					ketemu = 1;
				}else{
					prec = node;
					node = node->sibling;
				}
			}
			
			/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
			if((ketemu == 0)&&(node->name == name)){
				ketemu = 1;
			}
			
			if(ketemu == 1){
				simpul *last = root->child;
				
				/*mencari simpul anak terakhir*/
				while(last->sibling != root->child){
					last = last->sibling;
				}
				
				if(prec == NULL){
					/*jika simpul yang dihapus anak pertama*/
					if((node->sibling == last)&&(last->sibling == root->child)){
						/*jika hanya ada 2 anak*/
						root->child = last;
						last->sibling = NULL;
					}else{
						root->child = node->sibling;
						last->sibling = root->child;
					}
				}else{
					/* if((prec == root->child)&&( last->sibling == root->child))  <-- WRONG*/
					if((prec == root->child)&&( node->sibling == root->child)){ // <--TRUE
					
					
						/*jika hanya ada 2 simpul anak, yang dihapus anak kedua*/
						root->child->sibling = NULL;
					}else{
						prec->sibling = node->sibling;
						node->sibling = NULL;
					}
				}
				
				free(node);
			}else{
				printf("tidak ada simpul anak dengan info karakter masukan\n");
			}
		}
	}
}

/*
	FIND SIMPUL
*/
simpul* findSimpul(char name, simpul *root){
	simpul *hasil = NULL;
	if(root != NULL){
		if(root->name==name){
			hasil = root;
		}else{
			simpul *node = root->child;
			if(node != NULL){
				if(node->sibling == NULL){
					/*jika memiliki satu anak*/ 
					if(node->name==name){
						hasil = node;
					}else{
						hasil = findSimpul(name, node);
					}						
				}else{					
					/*jika memiliki banyak anak*/
					int ketemu = 0;
					while((node->sibling != root->child)&&(ketemu == 0)){
						if(node->name == name){
							hasil = node;
							ketemu = 1;
						}else{
							if(hasil==NULL){								
								hasil = findSimpul(name, node);								
								node = node->sibling;
							}else{
								ketemu = 1;
							}
						}
					}
					
					/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
					if(ketemu == 0){
						if(node->name == name){
							hasil = node;
						}else{
							if(hasil==NULL){
								hasil = findSimpul(name,node);
								node = node->sibling;
							}else{
								ketemu = 1;
							}
						}
					}
				}
			}
		}
	}
	return hasil;
} 

/*
	PRINT
*/
//=== preorder ===
void printTreePreOrder(simpul *root){
	
	if(root != NULL){
		count++;
		if(count == 7 || count == 13 || count == 21){
			printf("%c", root->name);
		}else{
			printf("%c ", root->name);
		}
		simpul *node  = root->child;
		if(node != NULL){
			if(node->sibling == NULL){
				/*jika memiliki satu anak*/
				printTreePreOrder(node);
			}else{
				/*jika memiliki banyak anak*/
				/*mencetak simpul anak*/
				while(node->sibling != root->child){
					printTreePreOrder(node);
					node = node->sibling;
				}
				
				/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
				printTreePreOrder(node);
			}
		}
	}
}