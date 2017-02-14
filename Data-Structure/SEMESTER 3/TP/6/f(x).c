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
      printf("%s\n", var->data.nama);
      var = var->next;
    }
  } else {
    printf("Stack Kosong\n");
  }
}

/* MY FX !!! */
void setNULL (object fx, stack *S) {
  elemen *var = (*S).top; // init

  while (var != NULL) {
    // Search
    if (var->data.profit == fx.profit && var->data.waktu == fx.waktu) {
      var->data.profit = -1; // set to null (not really null)
      var->data.waktu = -1; // set to null (not really null)
    }

    var = var->next; // iterate
  }
}

void moveAndPrint(stack *S1, stack *S2) {
  int totalWaktu = 0;
  int totalProfit = 0;

  object max; // value max for waktu and profit

  int i = 0; // init loop
  while (i < countElement(*S1)) { // loop till all the elmt access
    elemen *var = (*S1).top; // init loop elmt

    /* INIT VALUE */
    max.profit = 0;
    max.waktu = 0;

    while (var != NULL) { // loop to get max
      if (((max.profit < var->data.profit) ||
          (max.profit == var->data.profit && max.waktu > var->data.waktu))) {
        max = var->data;
      }

      var = var->next;
    }

    setNULL(max, S1); // after got the max, set to null the elmt in stack

    if ((totalWaktu + max.waktu) <= 250) {
      totalWaktu += max.waktu; // iterate
      totalProfit += max.profit; // iterate

      push(max, S2); // push to second stack
    }

    i++; // iterate
  }

  /* OUTPUT */
  printStack(*S2);
  printf("%d %d\n", totalWaktu, totalProfit);
}
