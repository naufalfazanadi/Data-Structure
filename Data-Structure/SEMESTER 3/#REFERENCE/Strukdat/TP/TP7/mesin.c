#include "header.h"

void createEmpty(queue *Q){
	/* Create data structure */
	(*Q).first = NULL;
	(*Q).last = NULL;
}

int isEmpty(queue Q){
	int hasil = 0;
	if(Q.first == NULL){
		/* Return true if empty */
		hasil = 1;
	}
	return hasil;
}

int countElement(queue Q){
	int hasil = 0;
	
	if(Q.first != NULL){
		
		elemen *elmt;
		elmt = Q.first;
		while (elmt != NULL){
			hasil+=1;
			elmt = elmt->next;
		}
	}
	/* Return total of element(count) */
	return hasil;
}

void add(char nama[], int spp, queue *Q){
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.nama,nama);
	elmt->elmt.spp = spp;
	elmt->next = NULL;
	if((*Q).first == NULL){
		(*Q).first = elmt;
	}else{
		(*Q).last->next = elmt;
	}
	(*Q).last = elmt;
	elmt = NULL;
}

void del(queue *Q){
	if((*Q).first != NULL){
		if(countElement(*Q) == 1){
			(*Q).first = NULL;
			(*Q).last = NULL;
		}else{			
			elemen *elmt = (*Q).first;
			(*Q).first = (*Q).first->next;
			elmt->next = NULL;
			free(elmt);
		}
	}
}

void printQueue(queue Q){
	if(Q.first != NULL){
		elemen *elmt = Q.first;
		int i = 1;
		while(elmt != NULL){
			
			printf("%s ",elmt->elmt.nama);
			printf("%d\n",elmt->elmt.spp);
			
			elmt = elmt->next;
		}
	}else{
		printf("QUEUE KOSONG\n");
	}
}

void addPriority(char nama[],int spp,int prioritas, queue *Q){
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.nama,nama);
	baru->elmt.spp = spp;
	if(isEmpty(*Q)){
		(*Q).first = baru;
		(*Q).last = baru;
		baru->next = NULL;
	}else{
		if(countElement(*Q) < prioritas){
			(*Q).last->next = baru;
			(*Q).last = baru;
			baru->next = NULL;
		}else{
			if(prioritas==1){
				baru->next = (*Q).first;
				(*Q).first = baru;
			}else{				
				elemen *elmt;
				elmt = (*Q).first;
				while(elmt != NULL && prioritas!=1){
					prioritas-=1;
					elmt=elmt->next;
				}
				// printf("%s",elmt->elmt.nama);
				baru->next = elmt->next;
				elmt->next = baru;			
			}
		}
	}
}
/*
 *Compare current pointer with q.first each queue
 *tempqyu will change according to spp value
 *Put mark on current temp queue ( to be removed)
 *@param temporary pointer.
 *@param queue comparison.
 */
void compareWith(elemen *tempqyu, queue *Q){
	/* Conditional check if queue isn't empty */
	if(isEmpty(*Q) != 1){
		/* 2 Condition, current spp higher than temporary, or current spp equal temporary */
		if((*Q).first->elmt.spp > tempqyu->elmt.spp){
			tempqyu->elmt.spp = (*Q).first->elmt.spp;
			strcpy(tempqyu->elmt.nama,(*Q).first->elmt.nama);
			choosen = Q;
		}else if((*Q).first->elmt.spp == tempqyu->elmt.spp){
			/* another conditional check for comparing name (ascending) */
			if(strcmp((*Q).first->elmt.nama,tempqyu->elmt.nama)<0){
				tempqyu->elmt.spp = (*Q).first->elmt.spp;
				strcpy(tempqyu->elmt.nama,(*Q).first->elmt.nama);
				choosen = Q;
			}
		}
	}
}