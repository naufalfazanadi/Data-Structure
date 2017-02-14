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

    (*S).top = (*S).top->next; // pindahkan ke selanjutnya
    var->next = NULL; // set null

    free(var); // freeMem
  }
}

//print stack
void printStack(stack S) {
  if (S.top != NULL) { // if not empty
    elemen *var = S.top;

    while (var != NULL) {
      printf("%s = %d\n", var->data.skrip, var->data.nilai);
      var = var->next; // iterate
    }
  } else {
    printf("Stack Kosong\n");
  }
}

/* MY FX !!! */
void processCommand(int n, stack *S) {
  // Init Stack for output
  stack SHasil;
  createStack(&SHasil);

  object hasil; // struct for result

  int i;
  for (i = 0; i < n; i++) { // loop base on n
    hasil.nilai = 0; // init to 0

    /* Loop while not null, and not '=' */
    while ((*S).top != NULL && strcmp((*S).top->data.skrip, "=") != 0) {

      // add to hasil.nilai if not '+' (number)
      if (strcmp((*S).top->data.skrip, "+") != 0) {
        hasil.nilai += atoi((*S).top->data.skrip); // iterate with atoi()
      }

      pop(S); // pop for check the next
    }

    pop(S); // pop for get the var of command
    strcpy(hasil.skrip, (*S).top->data.skrip);

    push(hasil, &SHasil); // push to output stack

    if (i != n - 1) { // if not the last then pop once again
      pop(S);
    }
  }

  printStack(SHasil); // output the result
}