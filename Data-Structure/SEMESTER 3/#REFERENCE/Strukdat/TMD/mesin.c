#include "header.h"

/*
 * Make N-er tree
 * Sibling and child should be NULL
 * @param struct data.
 * @param current tree.
 */
void makeTree(char name[], tree *T){
	simpul *node;
	node = (simpul *) malloc(sizeof (simpul));
	/* Copying */
	strcpy(node->name,name);
	node->sibling = NULL;
	node->child = NULL;
	(*T).root = node;
}

/*
 * Adding child from root
 * 3 Provitions
 *  -if child is eldest
 *  -if child is second child.
 *  -if child isn't eldest and second child.
 * @param character data.
 * @param current root.
 */
void addChild(char name[], simpul *root){
	if(root != NULL){
		/*jika root tidak kosong*/
		simpul *node;
		node = (simpul *) malloc(sizeof (simpul));
		strcpy(node->name,name);
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
 * Delete child
 * Find the node first
 * Condition if 1 child, 2child, or many child
 * @param info char.
 * @param deleted root.
 */
void delChild(char name[], simpul *root){
	simpul *node = root->child;
	
	if(node != NULL){
		if(node->sibling == NULL){
			/*jika hanya mempunyai satu anak*/
			if(strcmp(root->child->name,name)==0){
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
				if(strcmp(node->name,name)==0){
					ketemu = 1;
				}else{
					prec = node;
					node = node->sibling;
				}
			}
			
			/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
			if((ketemu == 0)&&(strcmp(node->name,name)==0)){
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
 * Find Simpul
 * search selected name from whole tree.
 * recursive
 * @param selected name/info.
 * @param highest root(T.root).
 * 		@return selected node pointer.
 */
simpul* findSimpul(char name[], simpul *root){
	simpul *hasil = NULL;
	if(root != NULL){
		if(strcmp(root->name,name)==0){
			hasil = root;
		}else{
			simpul *node = root->child;
			if(node != NULL){
				if(node->sibling == NULL){
					/*jika memiliki satu anak*/ 
					if(strcmp(node->name,name)==0){
						hasil = node;
					}else{
						hasil = findSimpul(name, node);
					}						
				}else{					
					/*jika memiliki banyak anak*/
					int ketemu = 0;
					while((node->sibling != root->child)&&(ketemu == 0)){
						if(strcmp(node->name,name)==0){
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
						if(strcmp(node->name,name)==0){
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
 * Split 1 String into two string.
 * Splitted by '#'
 * Return family (parent as string, child as string)
 * @param to be splitted string.
 *		@return splitted string (2 string) in one struct.
 */
family splitString(char string[]){
	int i;
	family temp;
	int counter1 = 0;
	int counter2 = 0;
	int stats = 0;
	for(i=0;i<strlen(string);i++){
		if(string[i] != '#'){
			if(stats == 0){
				/* Get child (b4 '#') */
				temp.child[counter1] = string[i];
				temp.child[counter1+1] = '\0';
				counter1++;				
			}else{
				/* Get parent (after '#') */
				temp.parent[counter2] = string[i];
				temp.parent[counter2+1] = '\0';
				counter2++;				
			}
		}else{
			/* Stats variable for break after '#' */
			stats = 1;
		}
	}
	
	return temp;
}

/*
 * PRINT TREE (INDENTATION METHOD)
 * Using global variable maxLen(max len every level).
 * Print indentation plus '|' b4 string, e.g. (		|nana).
 * @param highest root(usually T.root).
 * @param indetation space for every level. 
 * @param level counter.
 */
void printTreePreOrder(simpul *root,int spasi,int count){
	if(root != NULL){
		int i;
		for(i=0;i<spasi;i++){
			printf(" ");
		}
		printf("|%s\n", root->name);
		// printf("%d,%d\n",count,maxlen[count]);
		spasi+=maxlen[count];
		count++;
		
		simpul *node  = root->child;
		if(node != NULL){
			if(node->sibling == NULL){
				/*jika memiliki satu anak*/
				printTreePreOrder(node,spasi,count);
			}else{
				/*jika memiliki banyak anak*/
				/*mencetak simpul anak*/
				while(node->sibling != root->child){
					printTreePreOrder(node,spasi,count);
					node = node->sibling;
				}
				
				/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
				printTreePreOrder(node,spasi,count);
			}
		}
	}
}

/*
 * Visit Node
 * Visit selected info/name and get node's route.
 * Placing node's route into array of simpul.
 * @param to be visited node.
 * @param highest root(usually T.root).
 * @param array for save the right visitation route.
 * @param indeks for array things.
 * @param index as many visits will be carried out.
 */
void visitSimpul(char name[], simpul *root,simpul *visitasi[],int indeks,int index){
	simpul *hasil = NULL;
	/* jika pointer tidak kosong*/
	if(root != NULL && stats == 0){
		/* tambahkan ke array */
		visitasi[indeks]=root;
		
		if(strcmp(root->name, name)==0){
			/* jika ketemu maka simpan hasil */
			hasil = root;
			stats = 1;
		}else{
			/* jika belum ketemu terus telusuri */
			simpul *node = root->child;
			if(node != NULL && stats == 0){
				if(node->sibling == NULL){
					/* Jika anak cuma 1 */
					indeks++;
					visitasi[indeks]=node;
					/* jika masih belum ketemu maka telusuri ke anak nya lagi */
					if(strcmp(node->name,name)==0){
						hasil = node;
						stats = 1;
					}else{
						visitSimpul(name, node, visitasi, indeks,index);
					}
				}else{
					indeks++;
					/* jika anak banyak */
					/* cari di setiap anak */
					while((node->sibling != root->child) && (stats == 0)){
						visitasi[indeks]=node;
						if(strcmp(node->name,name)==0){
							hasil = node;
							stats = 1;
						}else{
							visitSimpul(name,node,visitasi,indeks,index);
							node = node->sibling;
						}
					}
					/* pengecualian karena anak terakhir belum terproses */
					if(stats == 0){
						visitasi[indeks]=node;
						if(strcmp(node->name, name)==0){
							hasil = node;
							stats = 1;
						}else{
							visitSimpul(name,node,visitasi,indeks,index);
						}
					}
				}
			}
		}
	}
	/* Jika visitasi berhasil,Maka kirimkan panjang route ke global */
	/* Karena program membutuhkan panjang route untuk delete. */
	if(stats == 1 && hasil != NULL){
		inx[index] = indeks;
	}
} 

/*
 * Delete Child
 * I make my own delete :D.
 * We can call this procedure with delFirst.
 * Delete every child below his parent.
 * @param parent node.
 */
void del(simpul *root){
	simpul *node = root->child;
	if(node != NULL){
		/* 1 */
		if(node->sibling == NULL){
			root->child = NULL;
			free(node);
		}else{
			/* banyak anak */
			/* pasti anak pertama */
			simpul *prec = NULL;
			simpul *last = root->child;
			while(last->sibling != root->child){
				last=last->sibling;
			}
			if((node->sibling == last) && (last->sibling == root->child)){
				root->child = last;
				last->sibling = NULL;
			}else{
				root->child = node->sibling;
				last->sibling = root->child;
			}
		}
	}
}

/*
 * Refine Len.
 * Refine length of the tree, b4 printing.
 * getMax every level of the tree.
 * @param highest root(usually T.root).
 * @param level counter.
 */
void refineLength(simpul *root,int count){
	if(root != NULL){
		if(strlen(root->name)+2 > maxlen[count]){
			maxlen[count] = strlen(root->name)+2;
		}
		
		count++;
		simpul *node  = root->child;
		if(node != NULL){
			if(node->sibling == NULL){
				/*jika memiliki satu anak*/
				refineLength(node,count);
			}else{
				/*jika memiliki banyak anak*/
				while(node->sibling != root->child){
					refineLength(node,count);
					node = node->sibling;
				}
				
				/*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
				refineLength(node,count);
			}
		}
	}
}

/*
 * Reset Len
 * Reset maxLength every level into zero.
 * Cause we need to find highest max for every level, the have to reset into zero
 * assume max lvl  = 64 :)
 */
void resetLen(){
	int i;
	int buffLength = 64;
	for(i=0;i<buffLength;i++){
		maxlen[i] = 0;
	}
}