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
	if(Q.last == (n - 1)){
		hasil = 1;
	}
	return hasil;
}

void add(float numb,queue *Q){
	if(isEmpty(*Q) == 1){
		(*Q).first = 0;
		(*Q).last = 0;
		(*Q).data[0].numb = numb;
		// strcpy((*Q).data[0].nama,nama);
	}
	else{
		if(isFull(*Q) != 1){
			(*Q).last = (*Q).last + 1;
			(*Q).data[(*Q).last].numb = numb;
			// strcpy((*Q).data[(*Q).last].nama,nama);
		}else{
			printf("Queue penuh!\n");
		}
	}
}
/*
 *Adding priority
 *Add into stack with parameter index
 *@param data
 *@param priority index
 *@param current queue
 */
void addPriority(float numb,int prioritas,queue *Q){
	if(isEmpty(*Q) == 1){
		(*Q).first = 0;
		(*Q).last = 0;
		(*Q).data[0].numb = numb;
	}else{
		if((*Q).last+1 < prioritas){
			(*Q).last += 1;
			(*Q).data[(*Q).last].numb = numb;
			// strcpy((*Q).data[(*Q).last].nama,nama);
		}else{
			prioritas -= 1;
			int i;
			(*Q).last+=1;
			for(i=((*Q).last);i>prioritas;i--){
				(*Q).data[i].numb = (*Q).data[i-1].numb;
				// strcpy((*Q).data[i].nama,(*Q).data[i-1].nama);
			}
			(*Q).data[i].numb = numb;
			// strcpy((*Q).data[i].nama,nama);
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
			(*Q).data[i-1].numb = (*Q).data[i].numb;
			// strcpy((*Q).data[i-1].numb,(*Q).data[i].nama);
		}
		(*Q).last = (*Q).last - 1;
	}
}

void printQueue(queue Q){
	if(Q.first != -1){
		int i;
		for(i=Q.first;i<=Q.last;i++){
			printf("%.2f\n",Q.data[i].numb);
		}
	}
	else{
		printf("queue kosong\n");
	}
}

