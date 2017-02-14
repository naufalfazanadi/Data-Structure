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

  countTree = 1; // init counter
}

void addRight(object fx, node *root) {
  if (root->right == NULL) {
    // INIT
    node *child;
    child = (node *) malloc (sizeof (node));

    // ADDING
    child->info = fx;
    child->right = NULL;
    child->left = NULL;
    root->right = child;

    countTree++; // iterate counter
  } else { // if added in right
    printf("sub pohon kanan telah terisi\n");
  }
}

void addLeft(object fx, node *root) {
  if (root->left == NULL) {
    // INIT
    node *child;
    child = (node *) malloc (sizeof (node));

    // ADDING
    child->info = fx;
    child->right = NULL;
    child->left = NULL;
    root->left = child;

    countTree++; // iterate counter
  } else { // if added in left
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

  // Delete the node
  root->right = NULL;
  free(child);

  countTree--; // dec the counter
}

void delLeft(node *root) {
  node *child = root->left;

  if (child->right != NULL) {
    delRight(child);
  } else if (child->left != NULL) {
    delLeft(child);
  }

  // Deleting the node
  root->left = NULL;
  free(child);

  countTree--; // dec the counter
}

void printTreePreOrder(node *root) { // print from left deep to right
  if (root != NULL) {
    printf("%s\n", root->info.nama);

    // Recursive
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
  }
}

//buat stack kosong
void createStack(stack *S) {
  (*S).top = NULL;
}

// Clear the Stack
void emptyStack(stack *S) {
  while ((*S).top != NULL) {
    pop(S);
  }
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
    elemen *var = S.top;

    while(var != NULL){
      sum = sum + 1;
      var = var->next;
    }
  }

  return sum;
}

//operator  push
void push(object fx, stack *S) {
  // INIT
  elemen *var;
  var = (elemen *) malloc (sizeof (elemen));

  // PUSH
  var->elmt = fx;
  var->next = (*S).top;
  (*S).top = var;

  var = NULL;
}

//operator pop
void pop(stack *S) {
  if ((*S).top != NULL) { //jika tidak kosong
    // INIT
    elemen *var = (*S).top;

    // POP
    (*S).top = (*S).top->next;
    var->next = NULL;

    free(var);
  }
}

//print stack
void printStack(stack S) {
  int totalAmal = 0;

  if (S.top != NULL) {
    elemen *var = S.top;

    while (var != NULL) {
      if (var->next == NULL) { // if in the end
        printf("%s", var->elmt.nama);
      } else { // in the middle
        printf("%s-", var->elmt.nama);
      }

      totalAmal += var->elmt.amal; // total of goodness
      var = var->next; // iterate
    }

    if (strcmp(S.top->elmt.nama, "Null") == 0) { // if not Null count not added
      printf(" %d %d", countElement(S), totalAmal);
    } else { // counter + 1
      printf(" %d %d", countElement(S)+1, totalAmal);
    }

    printf("\n");
  } else {
    printf("Stack Kosong\n");
  }
}

/* ----------------------------- MY OWN MACHINE ----------------------------- */
object fillPerson(char nama[], int amal) { // fill the struct var
  object fx;

  strcpy(fx.nama, nama);
  fx.amal = amal;

  return fx;
}

/**
 * Find the Node procedure
 * @param nama [the searched name]
 * @param root [root]
 * @param S    [the stack]
 * @param T    [tree to throw to findRoot]
 */
void findNode(char nama[], node *root, stack *S, tree *T) {
  // if founded
  if (bol == 0 && strcmp(root->info.nama, nama) == 0) {
    // if just hadi
    if (countElement((*S)) == 0 && strcmp(root->info.nama, "Hadi") == 0) {
      /* INIT STRUCT VAR */
      object nulled;

      strcpy(nulled.nama, "Null");
      nulled.amal = root->info.amal;

      // Then push to Stack
      push(nulled, S);
    } else {
      bolRoot = 0; // init for findRoot boolean

      findRoot(root, S, (*T).root); // find the root of the cur node

      if (countElement((*S)) == 1) { // add the current amal
        (*S).top->elmt.amal += root->info.amal;
      }

      bol = 1; // change to true first to stop
      if (strcmp((*S).top->elmt.nama, (*T).root->info.nama) != 0) { // if not T.root
        bol = 0; // set to false again
        findNode((*S).top->elmt.nama, (*T).root, S, T); // recursive....
      }
    }
  } else { // else  recursive!
    if (root->left != NULL) { // left
      findNode(nama, root->left, S, T);
    }
    if (root->right != NULL) { // right
      findNode(nama, root->right, S, T);
    }
  }
}

/**
 * Find root of the current node (Climbing to the top)
 * @param child [the searched root's child]
 * @param S     [Stack]
 * @param root  [var to find]
 */
void findRoot(node *child, stack *S, node *root) {
  if (bolRoot == 0) {
    if (root->left == child || root->right == child) { // if the child is the searched
      bolRoot = 1; // true
      push(root->info, S); // push to Stack
    } else { // else
      if (root->left != NULL) { // recursive to left
        findRoot(child, S, root->left);
      }
      if (root->right != NULL) { // recursive to right
        findRoot(child, S, root->right);
      }
    }
  }
}

// int getLevelUtil(node *root, char nama[], int level) {
//   if (root == NULL)
//     return 0;

//   if (strcmp(root->info.nama, nama) == 0)
//     return level;

//   int downlevel = getLevelUtil(root->left, nama, level+1);
//   if (downlevel != 0)
//     return downlevel;

//   downlevel = getLevelUtil(root->right, nama, level+1);

//   return downlevel;
// }

// /* Returns level of given data value */
// int getLevel(node *root, char nama[]) {
//   return getLevelUtil(root, nama, 1);
// }