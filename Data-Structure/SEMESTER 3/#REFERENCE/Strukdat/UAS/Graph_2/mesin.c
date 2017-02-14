#include "header.h"
/*
 * Create empty graph.
 * @param current Graph.
 */
void createEmpty(graph *G){
	(*G).first = NULL;
}

/*
 * Adding new simpul into graph.
 * 2 provition.
 *  -if graph is still empty.
 *  -if graph isn't empty.
 * @param new char.
 * @param current Graph.
 */
void addSimpul(char c, graph *G){
	simpul *node;
	node = (simpul *) malloc (sizeof (simpul));
	node->info = c;
	node->next = NULL;
	node->arc = NULL;
	
	if((*G).first  == NULL){
		/* jika graph kosong */
		(*G).first = node;
	}else{
		/* Menambahkan simpul baru pada akhir graph */
		simpul *last = (*G).first;
		
		while(last->next != NULL){
			/* cari elemen terakhir */
			last = last->next;
		}
		
		last->next = node;
	}
}

/*
 * Adding new route from tujuan node's, into awal node's.
 * New route is child from awal's pointer.
 * 2 provition
 * - if graph is empty.
 * - if graph isn't empty, addlast.
 * @param goal node.
 * @param from(first city) node.
 */
void addJalur(simpul *tujuan, simpul *awal){
	
	if(tujuan != NULL && awal != NULL){		
		/* if current simpul isn't NULL */
		jalur *arc;
		arc = (jalur *) malloc (sizeof (jalur));
		arc->next = NULL;
		arc->node = tujuan;
		
		if(awal->arc == NULL){
			/* jika kosong */
			awal->arc = arc;
		}else{
			/* menambahkan jalur baru pada akhir list jalur */
			jalur *last = awal->arc;
			
			while(last->next != NULL){
				last=last->next;
			}
			
			last->next = arc;
		}
	}
	
}

/*
 * Delete route
 * 3 provition
 * - if there's only 1 route.
 * - if there are many route, but the selected pointer in the last.
 * - if there are many route, but the selected pointer in the middle.
 * @param deleted route.
 * @param parent node(simpul).
 */
void delJalur(char ctujuan, simpul *awal){
	
	jalur *arc = awal->arc;
	if(arc != NULL){
		/* if to be deleted route isn't empty */
		jalur *prec = NULL;
		int ketemu = 0;
		while((arc!= NULL) && (ketemu == 0)){
			/* cari jalur */
			if(arc->node->info == ctujuan){
				ketemu = 1;
			}else{
				prec = arc;
				arc = arc->next;
			}
		}
		if(ketemu == 1){
			if(prec==NULL){
				if(arc->next == NULL){
					/* jika hanya ada 1 jalur */
					awal->arc = NULL;
				}else{
					awal->arc = arc->next;
				}
			}else{
				if(arc->next == NULL){
					/* hapus jalur terakhir */
					prec->next = NULL;
				}else{
					/* Hapus jalur ditengah */
					prec->next = arc->next;
					arc->next = NULL;
				}
			}
			free(arc);
		}else{
			printf("empty\n");
		}
	}else{
		printf("empty\n");
	}
}

/*
 * **IMPORTANT** : Bu maaf kalau delete simpul nya pada sama (sekelas), kemarin faisal nge share delete simpulnya ke sekelas, ke c1 juga :D
 * Delete simpul
 * Before delete node(simpul) we have to do 2 things:
 *  first : we have to delete whole route TO that NODE.
 * 	second : we have to delete whole route FROM that NODE.
 * @param selected char(node).
 * @param current graph.
 */
void delSimpul(char c, graph *G){
	simpul* elmt = (*G).first;
	if(elmt != NULL){
		simpul *prec = NULL;
		
		int ketemu = 0;
		while((elmt != NULL) && (ketemu == 0)){
			if(elmt->info == c){
				ketemu = 1;
			}else{
				prec = elmt;
				elmt = elmt->next;
			}
		}
		
		if(ketemu == 1){
			/* from start here until end here, this is my code and shared to whole class */
			//------------------------------------- Start here
			/* Hapus jalur yang mengarah ke simpul */
			simpul* hapus = (*G).first;
			while(hapus != NULL){
				if(hapus->info != elmt->info){
					/* skip jika simpul yang sama */
					jalur* hapus2 = hapus->arc;
					int stats = 0;
					while(hapus2 != NULL && stats == 0){
						/* Cari yang mengarah ke simpul deleted */
						if(hapus2->node->info == elmt->info){
							stats = 1;
							delJalur(elmt->info,hapus);
						}else{
							hapus2 = hapus2->next;
						}
					}
				}
				hapus=hapus->next;
			}
			/* Hapus semua jalur yang simpul miliki*/
			while(elmt->arc != NULL){
				delJalur(elmt->arc->node->info,elmt);
			}
			//----------------------------------------- End here
			if(prec == NULL){
				/* hapus simpul awal */
				(*G).first = elmt -> next;
			}else{
				if(elmt -> next == NULL){
					/* hapus simpul terakhir */
					prec->next = NULL;
				}else{
					/* hapus simpul di tengah */
					prec->next = elmt->next;
					elmt->next = NULL;
				}
			}
			free(elmt);
		}
		else{
			printf("empty\n");
		}
	}else{
		printf("empty\n");
	}
}

/*
 * Find Simpul
 * find current pointer you need to.
 * @param current character you want to.
 * @param current Graph.
 */
simpul* findSimpul(char c, graph G){
	simpul *hasil = NULL;
	simpul *node = G.first;
	int stats = 0;
	while((node != NULL) && (stats == 0)){
		/* Loop into whole tree and find the character */
		if(node->info == c){
			hasil = node;
			stats = 1;
		}else{
			node = node->next;
		}
	}
	/* return pointer */
	return hasil;
}

/* 
 * PRINT GRAPH
 * Print node(simpul) first then route(jalur);
 * @param current Graph
 */
void printGraph(graph G){
	simpul *node = G.first;
	if(node != NULL){
		while(node != NULL){
			printf("simpul : %c\n",node->info);
			jalur *arc = node->arc;
			while(arc != NULL){
				printf(" - ada jalur ke simpul : %c\n",arc->node->info);
				arc=arc->next;
			}
			node = node->next;
		}
	}else{
		printf("graph kosong\n");
	}
}

int cek(char string[],graph G){
	int i;
	int counter = 0;
	int stats = 0;
	for(i=0;i<strlen(string);i++){
		if(string[i] != '-'){
			if(findSimpul(string[i],G) != NULL){
				if(i+2 < strlen(string)){					
					char temp = string[i+2];
					jalur *arc = findSimpul(string[i],G)->arc;
					while(arc != NULL){
						if(temp == arc->node->info){
							stats++;
						}
						arc = arc->next;
					}
				}
			}
		}
	}
	int count;
	if(strlen(string)%2==0){
		count = strlen(string)/2;
	}else{
		count = (strlen(string)/2)+1;		
	}
	
	if(stats == count-1){
		return 1;
	}else{
		return 0;
	}
}