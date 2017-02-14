#include "header.h"

void createEmpty(graph *G){
	(*G).first = NULL;
}

void addSimpul(char c, graph *G){
	simpul *node;
	node = (simpul *) malloc (sizeof (simpul));
	node->info = c;
	node->next = NULL;
	node->arc = NULL;
	
	if((*G).first == NULL){
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

void addJalur(simpul *tujuan, simpul *awal){
	if(tujuan != NULL && awal != NULL){		
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

void delJalur(char ctujuan, simpul *awal){
	jalur *arc = awal->arc;
	if(arc != NULL){
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

simpul* findSimpul(char c, graph G){
	simpul *hasil = NULL;
	simpul *node = G.first;
	int ketemu = 0;
	while((node != NULL) && (ketemu == 0)){
		if(node->info == c){
			hasil = node;
			ketemu = 1;
		}else{
			node = node->next;
		}
	}
	
	return hasil;
}

void printGraph(graph G){
	simpul *node = G.first;
	if(node != NULL){
		while(node != NULL){
			printf("simpul : %c\n",node->info);
			jalur *arc = node->arc;
			while(arc != NULL){
				printf("- ada jalur ke simpul : %c\n",arc->node->info);
				arc=arc->next;
			}
			node = node->next;
		}
	}else{
		printf("graph kosong\n");
	}
}

int countGraph(graph G){
	int counter = 0;
	simpul *node = G.first;
	if(node != NULL){
		while(node != NULL){
			counter++;
			jalur *arc = node->arc;
			while(arc != NULL){
				counter++;
				arc=arc->next;
			}
			node = node->next;
		}
	}
	return counter;
}
