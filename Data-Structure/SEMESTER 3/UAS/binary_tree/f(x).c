#include "head.h"

void makeTree(object fx, tree *T) {
  // INIT
  node *child;
  child = (node *) malloc (sizeof (node));

  // ADDING
  child->info = fx;
  child->right = NULL;
  child->left = NULL;
  (*T).root = child;

  // countTree = 1;
}

void addRight(object fx, node *root) {
  if (root->right == NULL) {
    node *child;
    child = (node *) malloc (sizeof (node));

    // ADDING
    child->info = fx;
    child->right = NULL;
    child->left = NULL;
    root->right = child;

    // countTree++;
  } else {
    printf("sub pohon kanan telah terisi\n");
  }
}

void addLeft(object fx, node *root) {
  if (root->left == NULL) {
    node *child;
    child = (node *) malloc (sizeof (node));

    // ADDING
    child->info = fx;
    child->right = NULL;
    child->left = NULL;
    root->left = child;

    // countTree++;
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

  // countTree--;
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

  // countTree--;
}

void printTreePreOrder(node *root) { // print to wide
  if (root != NULL) {
    printf("%c", root->info.nama);
    printf(" %d", root->info.num1);
    printf(" %d\n", root->info.num2);
    // if (countPre != countTree-1) {
    //   printf(" - ");
    //   countPre++;
    // } else {
    //   printf("\n");
    // }

    // Recursive
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
  }
}

void printTreeInOrder(node *root) { // print to height from left to right
  if (root != NULL) {
    printTreeInOrder(root->left);

    printf("%c", root->info);
    // if (countIn != countTree - 1) {
    //   printf(" - ");
    //   countIn++;
    // } else {
    //   printf("\n");
    // }

    printTreeInOrder(root->right);
  }
}

void printTreePostOrder(node *root) {
  if (root != NULL) {
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);

    printf("%c", root->info);
    // if (countPost != countTree - 1) {
    //   printf(" - ");
    //   countPost++;
    // } else {
    //   printf("\n");
    // }
  }
}

/* ---------------- MY FUNC AND PROC HERE ! ---------------- */
void findAndAdd(char nama[], object fx, node *root, int pos) {
  // if founded
  if (bol == 0 && root->info.nama == nama[0]) {
    if (pos == 1) { // left
      addLeft(fx, root);
    } else if (pos == 2) { // right
      addRight(fx, root);
    }
    bol = 1;
  } else { // else  recursive!
    if (root->left != NULL) { // left
      findAndAdd(nama, fx, root->left, pos);
    }
    if (root->right != NULL) { // right
      findAndAdd(nama, fx, root->right, pos);
    }
  }
}

void addToTree(char before[], object fx, char position[], tree *T) {
  // if null make tree
  if (strcmp(before, "null") == 0) {
    makeTree(fx, T);
  } else { // else
    if (strcmp(position, "kanan") == 0) { // add right
      findAndAdd(before, fx, (*T).root, 1);
    } else if (strcmp(position, "kiri") == 0) { // add left
      findAndAdd(before, fx, (*T).root, 2);
    }
  }
}

// COunt the leaf
void countLeaf(node *root) {
  if (root->left == NULL && root->right == NULL) { // the leaf
    countDaun++;
  } else { // recursive to next
    if (root->left != NULL) { // left
      countLeaf(root->left);
    }
    if (root->right != NULL) { // right
      countLeaf(root->right);
    }
  }
}

void checkMultiple(node *root) {
  // check the multiple
  if (root->left == NULL && root->right == NULL &&
      (root->info.num1 % root->info.num2 == 0 ||
       root->info.num2 % root->info.num1 == 0)) {
    bol++;
  } else { // recursive
    if (root->left != NULL) { // left
      checkMultiple(root->left);
    }
    if (root->right != NULL) { // right
      checkMultiple(root->right);
    }
  }
}