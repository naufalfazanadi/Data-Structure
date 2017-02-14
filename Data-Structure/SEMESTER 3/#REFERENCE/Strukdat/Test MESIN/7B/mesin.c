#include "header.h"

void createEmpty(queue *Q){
	(*Q).first = NULL;
	(*Q).last = NULL;
}

int isEmpty(queue Q){
	int hasil = 0;
	if(Q.first == NULL){
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
	return hasil;
}

void add(char nama[], queue *Q){
	elemen *elmt;
	elmt = (elemen *) malloc (sizeof (elemen));
	strcpy(elmt->elmt.nama,nama);
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
			
			printf("%s\n",elmt->elmt.nama);
			
			elmt = elmt->next;
			i++;
		}
	}else{
		printf("QUEUE KOSONG\n");
	}
}

void addPriority(char nama[],int prioritas, queue *Q){
	elemen *baru;
	baru = (elemen *) malloc (sizeof (elemen));
	strcpy(baru->elmt.nama,nama);
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
					printf(".");
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