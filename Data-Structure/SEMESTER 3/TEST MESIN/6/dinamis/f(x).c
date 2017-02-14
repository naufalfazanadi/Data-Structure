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
    elemen *var = S.top;

    while(var != NULL){
      sum = sum + 1;
      var = var->next;
    }
  }

  return sum;
}

//operator  push
void push(object fx, stack *S) {
  elemen *var;
  var = (elemen *) malloc (sizeof (elemen));

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
      if (var->next == NULL) {
        printf("%s", var->elmt.nama);
      } else {
        printf("%s ", var->elmt.nama);
      }
      var = var->next;
    }
    printf("\n");
  } else {
    printf("Stack Kosong\n");
  }
}

void move(stack *S1, stack *S2) {
  if ((*S1).top != NULL) {
    elemen *var = (*S1).top;

    push(var->elmt, S2);
    pop(S1);
  }
}