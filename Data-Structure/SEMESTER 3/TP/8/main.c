#include "head.h"

int main () {
  /* INIT TREE */
  tree T;
  makeTree(fillPerson("Hadi", 10), &T);

  // Half Left
  addLeft(fillPerson("Ando", 20),T.root);
  addLeft(fillPerson("Euis", 22),T.root->left);
  addRight(fillPerson("Otun", 23),T.root->left);
  addLeft(fillPerson("Dodi", 30),T.root->left->right);
  addRight(fillPerson("Ebta", 12),T.root->left->right);

  // Half Right
  addRight(fillPerson("Nesa", 15),T.root);
  addLeft(fillPerson("Yeni", 25),T.root->right);
  addRight(fillPerson("Atik", 20),T.root->right);
  addLeft(fillPerson("Kiki", 25),T.root->right->right);
  addRight(fillPerson("Akbar", 21),T.root->right->right);
  // printTreePostOrder(T.root);

  int i;
  int n;
  scanf("%d", &n); // input

  char search[n][32]; // the searched name

  /* INIT STACK */
  stack S;
  createStack(&S);

  // INPUT THE SEARCH
  for (i = 0; i < n; i++) {
    scanf("%s", &search[i]);
  }

  /* PROCESSING */
  for (i = 0; i < n; i++) {
    bol = 0; // init the boolean for findNode
    findNode(search[i], T.root, &S, &T); // PROCESS

    printStack(S); /* OUTPUT */

    emptyStack(&S); /* CLEAR THE STACK */
  }

  return 0;
}