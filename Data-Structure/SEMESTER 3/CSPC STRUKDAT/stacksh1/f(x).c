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
  var->data = fx;
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
      printf("%.2f\n", var->data.num);
      var = var->next;
    }
  } else {
    printf("Stack Kosong\n");
  }
}

/* MY FX !!! */
void printInverse(stack S) {
  stack inverse;
  createStack(&inverse);

  elemen *var = S.top;
  while (var != NULL) {
    push(var->data, &inverse);

    var = var->next;
  }

  printStack(inverse);
}

void checkAndOutput(stack *S1, stack *S2) {
  stack fusion;
  createStack(&fusion);

  elemen *var1 = (*S1).top;
  elemen *var2 = (*S2).top;

  while (var1 != NULL || var2 != NULL) {
    if (var1 == NULL) {
      push(var2->data, &fusion);
      var2 = var2->next;
    } else if (var2 == NULL) {
      push(var1->data, &fusion);
      var1 = var1->next;
    } else {
      push(var1->data, &fusion);
      push(var2->data, &fusion);
      var1 = var1->next;
      var2 = var2->next;
    }

  }

  printStack(fusion);
}
