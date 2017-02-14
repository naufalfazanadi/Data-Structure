#include "header.h"

void createEmpty(queue *Q){
	(*Q).first = -1;
	(*Q).last = -1;
}

int isEmpty(queue Q){
	int hasil = 0;
	if(Q.first == -1){
		hasil =1;
	}
	return hasil;
}

int isFull(queue Q){
	int hasil = 0;
	if(Q.last == (MAX_QYU - 1)){
		hasil = 1;
	}
	return hasil;
}

void add(char nama[],queue *Q){
	if(isEmpty(*Q) == 1){
		(*Q).first = 0;
		(*Q).last = 0;
		strcpy((*Q).data[0].nama,nama);
	}
	else{
		if(isFull(*Q) != 1){
			(*Q).last = (*Q).last + 1;
			strcpy((*Q).data[(*Q).last].nama,nama);
		}else{
			printf("Queue penuh!\n");
		}
	}
}

void del(queue *Q){
	if((*Q).last == 0){
		(*Q).first = -1;
		(*Q).last = -1;		
	}else{
		int i;
		for(i=((*Q).first +1);i<=(*Q).last;i++){
			strcpy((*Q).data[i-1].nama,(*Q).data[i].nama);
		}
		(*Q).last = (*Q).last - 1;
	}
}

void printQueue(queue Q){
	if(Q.first != -1){
		int i;
		for(i=Q.first;i<=Q.last;i++){
			printf("%s\n",Q.data[i].nama);
		}
	}
	else{
		printf("Queue Kosong!\n");
	}
}

void addPriority(char nama[],int prioritas,queue *Q){
	if(isEmpty(*Q) == 1){
		(*Q).first = 0;
		(*Q).last = 0;
		strcpy((*Q).data[0].nama,nama);
	}else{
		if((*Q).last+1 < prioritas){
			(*Q).last += 1;
			strcpy((*Q).data[(*Q).last].nama,nama);
		}else{
			prioritas -= 1;
			int i;
			(*Q).last+=1;
			for(i=((*Q).last);i>prioritas;i--){
				strcpy((*Q).data[i].nama,(*Q).data[i-1].nama);
			}
			strcpy((*Q).data[i].nama,nama);
		}
	}
}
