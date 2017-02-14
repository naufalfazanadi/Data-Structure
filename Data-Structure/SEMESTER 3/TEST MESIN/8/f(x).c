#include "head.h"

void makeTree(char fx, tree *T) {
  // INIT
  node *child;
  child = (node *) malloc (sizeof (node));

  // ADDING
  child->info = fx;
  child->right = NULL;
  child->left = NULL;
  (*T).root = child;

  countTree = 1;
}

void addRight(char fx, node *root) {
  if (root->right == NULL) {
    node *child;
    child = (node *) malloc (sizeof (node));

    // ADDING
    child->info = fx;
    child->right = NULL;
    child->left = NULL;
    root->right = child;

    countTree++;
  } else {
    printf("sub pohon kanan telah terisi\n");
  }
}

void addLeft(char fx, node *root) {
  if (root->left == NULL) {
    node *child;
    child = (node *) malloc (sizeof (node));

    // ADDING
    child->info = fx;
    child->right = NULL;
    child->left = NULL;
    root->left = child;

    countTree++;
  } else {
    printf("sub pohon kiri telah terisi\n");
  }
}

void delRight(node *root) {
  node *child = root->right;

  // RECURSIVE DELETING THE CHILD
  if (child->right != NULL) {
    delRight(child);
  } else if (child->left != NULL) {
    delLeft(child);
  }

  root->right = NULL;
  free(child);

  countTree--;
}

void delLeft(node *root) {
  node *child = root->left;

  if (child->right != NULL) {
    delRight(child);
  } else if (child->left != NULL) {
    delLeft(child);
  }

  root->left = NULL;
  free(child);

  countTree--;
}

void printTreePreOrder(node *root) { // print to wide
  if (root != NULL) {
    printf("%c", root->info);
    if (countPre != countTree-1) {
      printf(" - ");
      countPre++;
    } else {
      printf("\n");
    }

    // Recursive
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
  }
}

void printTreeInOrder(node *root) { // print to height from left to right
  if (root != NULL) {
    printTreeInOrder(root->left);

    printf("%c", root->info);
    if (countIn != countTree - 1) {
      printf(" - ");
      countIn++;
    } else {
      printf("\n");
    }

    printTreeInOrder(root->right);
  }
}

void printTreePostOrder(node *root) {
  if (root != NULL) {
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);

    printf("%c", root->info);
    if (countPost != countTree - 1) {
      printf(" - ");
      countPost++;
    } else {
      printf("\n");
    }
  }
}

void copyTree(node *root1, node **root2) {
  if (root1 != NULL) {
    (*root2) = (node *) malloc (sizeof (node));
    (*root2)->info = root1->info;

    if (root1->left != NULL) {
      copyTree(root1->left, &(*root2)->left);
    } else {
      (*root2)->left = NULL;
    }

    if (root1->right != NULL) {
      copyTree(root1->right, &(*root2)->right);
    } else {
      (*root2)->right = NULL;
    }
  } else {
    (*root2)->right = NULL;
    (*root2)->left = NULL;
  }
}

int isEqual(node *root1, node *root2) {
  int bol = 1;

  if (root1 != NULL && root2 != NULL && bol) {
    if (root1->info != root2->info) {
      bol = 0;
    }else{
      isEqual(root1->left, root2->left);
      isEqual(root1->right, root2->right);
    }
  }else{
    bol = 0;
  }

  return bol;
}