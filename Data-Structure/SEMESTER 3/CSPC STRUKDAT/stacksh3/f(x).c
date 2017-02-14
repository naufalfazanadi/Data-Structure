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
      printf("%d\n", var->data.num);
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
  elemen *var1 = (*S1).top;
  elemen *var2 = (*S2).top;

  int sum1 = 0;
  int sum2 = 0;

  while (var1 != NULL) {
    sum1 += var1->data.num;

    var1 = var1->next;
  }

  while (var2 != NULL) {
    sum2 += var2->data.num;

    var2 = var2->next;
  }

  printf("s1\n");
  if (sum1 % 2 == 1) {
    printInverse(*S1);
  } else {
    printStack(*S1);
  }

  printf("s2\n");
  if (sum2 % 2 == 1) {
    printInverse(*S2);
  } else {
    printStack(*S2);
  }
}
