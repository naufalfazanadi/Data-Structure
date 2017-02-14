#include "head.h"

void createStack(stack *S) {
  (*S).top = -1;
}

int isEmpty(stack S) {
  int bol = 0;

  if (S.top == -1) {
    bol = 1;
  }
  return bol;
}

int isFull(stack S) {
  int sum = 0;
  if (S.top == MAX -1) {
    sum = 1;
  }
  return sum;
}

void push(object fx, stack *S) {
  if (isFull(*S) == 1) {
    printf("Stack Overflow\n");
  } else {
    if (isEmpty(*S) == 1) {
      (*S).top = 0;
    } else {
      (*S).top++;
    }

    (*S).elmt[(*S).top] = fx;
  }
}

void pop(stack *S) {
  if ((*S).top == 0) {
    (*S).top = -1;
  } else {
    if ((*S).top != -1) {
      (*S).top = (*S).top - 1;
    }
  }
}

void printStack(stack S) {
  if (S.top != -1) {
    int i;
    for(i = S.top; i >= 0; i--) {
      if (i == 0) {
        printf("%s", S.elmt[i].nama);
      } else {
        printf("%s ", S.elmt[i].nama);
      }
    }
    printf("\n");
  } else {
    printf("Stack Kosong\n");
  }
}

void move(stack *S1, stack *S2) {
  if ((*S1).top != -1) {
    int var = (*S1).top;

    push((*S1).elmt[var], S2);
    pop(S1);
  }
}