#include "head.h"

int main () {
  /* INIT TREE */
  tree T;

  /* INPUT */
  int n;
  scanf("%d", &n);

  int i;

  char before[8];
  object add; // struct
  char position[8];

  // input
  for (i = 0; i < n; i++) {
    scanf("%s %c %d %d %s", &before, &add.nama, &add.num1, &add.num2, &position);
    bol = 0;
    // add to tree
    addToTree(before, add, position, &T);
  }
  /* COUNT THE LEAF */
  countDaun = 0;
  countLeaf(T.root);

  /* CHECK THE LEAF OF MULTIPLE */
  bol = 0;
  checkMultiple(T.root);

  /* OUTPUT */
  if (bol != countDaun) {
    printf("|bukan telolet om|\n");
  } else {
    printf("|om telolet om|\n");
  }

  return 0;
}