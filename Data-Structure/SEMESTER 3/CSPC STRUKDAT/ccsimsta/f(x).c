#include "head.h"

//buat stack kosong
void createStack(stack *S) {
  (*S).top = NULL;
}

//fungsi memeriksa stack kosong atau tidak
int isEmpty(stack S) {
  int bol = 0;

  if(S.top == NULL){ //jika kosong
    bol = 1;
  }

  return bol;
}

//menghitung banyak elemen dalam stack yang tersisa
int countElement(stack S) {
  int sum = 0;

  if (S.top != NULL) { //jika tidak kosong
    elemen *var = S.top; // init

    while(var != NULL){
      sum = sum + 1; // count
      var = var->next;
    }
  }

  return sum;
}

//operator  push
void push(object fx, stack *S) {
  // Create space in memory
  elemen *var;
  var = (elemen *) malloc (sizeof (elemen));

  // Pemindahan
  var->elmt = fx;
  var->next = (*S).top;
  (*S).top = var;

  var = NULL;
}

//operator pop
void pop(stack *S) {
  if ((*S).top != NULL) { //jika tidak kosong
    elemen *var = (*S).top;

    (*S).top = (*S).top->next;
    var->next = NULL;

    free(var);
  }
}

//print stack
void printStack(stack S) {
  if (S.top != NULL) {
    elemen *var = S.top;

    while (var != NULL) {
      printf("%d\n", var->elmt.num);
      var = var->next;
    }
  } else {
    // printf("Stack Kosong\n");
  }
  printf("-1\n");
}

/* MY FX !!! */
void popBanyak(int number, stack *S) {
  elemen *var = (*S).top;

  int i = 0;
  while (var != NULL && i < number) {
    pop(S);

    i++;
    var = (*S).top;
  }
}

void popCari(int number, stack *S) {
  elemen *var = (*S).top;

  int bol = 1;

  while (var != NULL && bol) {
    if (var->elmt.num == number) {
      bol = 0;
    }

    pop(S);

    var = (*S).top;
  }
}