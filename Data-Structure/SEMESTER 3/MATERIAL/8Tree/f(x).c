#include "head.h"

void makeTree(object fx, tree *T) {
  // INIT
  node *child;
  child = (node *) malloc (sizeof (node));

  // ADDING
  child->info = fx;
  child->right = NULL;
  child->left = NULL;
  (*T).parent = child;
}

void addRight(object fx, node *parent) {
  if (parent->right == NULL) {
    node *child;
    child = (node *) malloc (sizeof (node));

    // ADDING
    child->info = fx;
    child->right = NULL;
    child->left = NULL;
    parent->right = child;
  } else {
    printf("sub pohon kanan telah terisi\n");
  }
}

void addLeft(object fx, node *parent) {
  if (parent->left == NULL) {
    node *child;
    child = (node *) malloc (sizeof (node));

    // ADDING
    child->info = fx;
    child->right = NULL;
    child->left = NULL;
    parent->left = child;
  } else {
    printf("sub pohon kiri telah terisi\n");
  }
}

void delRight(node *parent) {
  node *child = parent->right;

  // RECURSIVE DELETING THE CHILD
  if (child->right != NULL) {
    delRight(child);
  } else if (child->left != NULL) {
    delLeft(child);
  }

  parent->right = NULL;
  free(child);
}

void delLeft(node *parent) {
  node *child = parent->left;

  if (child->right != NULL) {
    delRight(child);
  } else if (child->left != NULL) {
    delLeft(child);
  }

  parent->left = NULL;
  free(child);
}

void printTreePreOrder(node *parent) { // print to wide
  if (parent != NULL) {
    printf("%c\n", parent->info.ch);

    // Recursive
    printTreePreOrder(parent->left);
    printTreePreOrder(parent->right);
  }
}

void printTreeInOrder(node *parent) { // print to height from left to right
  if (parent != NULL) {
    printTreeInOrder(parent->left);

    printf("%c\n", parent->info.ch);

    printTreeInOrder(parent->right);
  }
}

void printTreePostOrder(node *parent) {
  if (parent != NULL) {
    printTreePostOrder(parent->left);
    printTreePostOrder(parent->right);

    printf("%c", parent->info.ch);
  }
}

void copyTree(node *parent1, node *parent2) {
  if (parent1 != NULL) {

    /* Check left */
    if (parent1 != NULL) {
      parent2 = (simpul *) malloc (sizeof (simpul));
      parent2->info = parent1->info;

      if (parent1->left != NULL) {
        copyTree(parent1->left, parent2->left);
      } else {
        parent2->left = NULL;
      }
      if (parent1->right != NULL) {
        copyTree(parent1->right, parent2->right);
      } else {
        parent2->right = NULL;
      }
    }
  } else {
    parent2 = NULL;
  }
}

int isEqual(node *parent1, node *parent2) {
  int bol = 1;

  if (parent1 != NULL && parent2 != NULL && bol) {
    if (parent1->info.ch != parent2->info.ch) {
      bol = 0;
    }else{
      isEqual(parent1->left, parent2->left);
      isEqual(parent1->right, parent2->right);
    }
  }else{
    bol = 0;
  }

  return bol;
}