#include "head.h"

/*
 *Make N-er tree
 *Sibling and child should be NULL
 *@param struct data.
 *@param current tree.
 */
void makeTree(char c, tree *T) {
  node *var;
  var = (node *) malloc(sizeof (node));

  var->info = c;
  var->sibling = NULL;
  var->child = NULL;
  (*T).parent = var;
}

/*
 *Adding child from parent
 *3 Provitions
 * -if child is eldest
 * -if child is second child.
 * -if child isn't eldest and second child.
 *@param character data.
 *@param current parent.
 */
void addChild(char c, node *parent) {
  if (parent != NULL) {
    /*jika parent tidak kosong*/
    node *var;
    var = (node *) malloc(sizeof (node));

    var->info = c;
    var->child = NULL;

    if (parent->child == NULL) {
      /*node baru menjadi anak pertama*/
      var->sibling = NULL;
      parent->child = var;
    } else {
      if (parent->child->sibling == NULL) {
        /*jika node baru menjadi anak kedua*/
        var->sibling = parent->child;
        parent->child->sibling = var;
      } else {
        node *last = parent->child;

        /*mencari node anak terakhir*/
        while (last->sibling != parent->child) {
          last = last->sibling;
        }

        var->sibling = parent->child;
        last->sibling = var;
      }
    }
  }
}

/*
 *Delete child
 *Find the var first
 *Condition if 1 child, 2child, or many child
 *@param info char.
 *@param deleted parent.
 */
//=== child ===//
void delChild(char c, node *parent) {
  node *var = parent->child;

  if (var != NULL) {
    if (var->sibling == NULL) {
      /*jika hanya mempunyai satu anak*/
      if (parent->child->info == c) {
        parent->child = NULL;
        free(var);
      } else {
        printf("tidak ada node anak dengan info karakter masukan\n");
      }
    } else {
      /*jika memiliki banyak anak*/
      node *prec = NULL;

      /*mencari node yang akan dihapus*/
      int ketemu = 0;
      while ((var->sibling != parent->child) && (ketemu == 0)) {
        if (var->info == c) {
          ketemu = 1;
        } else {
          prec = var;
          var = var->sibling;
        }
      }

      /*memproses node anak terakhir karena belum terproses dalam pengulangan*/
      if ((ketemu == 0) && (var->info == c)) {
        ketemu = 1;
      }

      if (ketemu == 1) {
        node *last = parent->child;

        /*mencari node anak terakhir*/
        while (last->sibling != parent->child) {
          last = last->sibling;
        }

        if (prec == NULL) {
          /*jika node yang dihapus anak pertama*/
          if ((var->sibling == last) && (last->sibling == parent->child)) {
            /*jika hanya ada 2 anak*/
            parent->child = last;
            last->sibling = NULL;
          } else {
            parent->child = var->sibling;
            last->sibling = parent->child;
          }
        } else {
          if ((prec == parent->child) && (last->sibling == parent->child)) {
            /*jika hanya ada 2 node anak, yang dihapus anak kedua*/
            parent->child->sibling = NULL;
          } else {
            prec->sibling = var->sibling;
            var->sibling = NULL;
          }
        }

        free(var);
      } else {
        printf("tidak ada node anak dengan info karakter masukan\n");
      }
    }
  }
}

/*
  FIND node
*/
node *findNode(char c, node *parent) {
  node *hasil = NULL;
  if (parent != NULL) {
    if (parent->info == c) {
      hasil = parent;
    } else {
      node *var = parent->child;
      if (var != NULL) {
        if (var->sibling == NULL) {
          /*jika memiliki satu anak*/
          if (var->info == c) {
            hasil = var;
          } else {
            hasil = findNode(c, var);
          }
        } else {
          /*jika memiliki banyak anak*/
          int ketemu = 0;
          while ((var->sibling != parent->child) && (ketemu == 0)) {
            if (var->info == c) {
              hasil = var;
              ketemu = 1;
            } else {
              hasil = findNode(c, var);
              var = var->sibling;
            }
          }

          /*memproses node anak terakhir karena belum terproses dalam pengulangan*/
          if (ketemu == 0) {
            if (var->info == c) {
              hasil = var;
            } else {
              hasil = findNode(c, var);
            }
          }
        }
      }
    }
  }

  return hasil;
}

/*
  PRINT
*/
//=== preorder ===//
void printTreePreOrder(node *parent) {
  if (parent != NULL) {
    printf(" %c \n", parent->info);

    node *var  = parent->child;

    if (var != NULL) {
      if (var->sibling == NULL) {
        /*jika memiliki satu anak*/
        printTreePreOrder(var);
      } else {
        /*jika memiliki banyak anak*/
        /*mencetak node anak*/
        while (var->sibling != parent->child) {
          printTreePreOrder(var);
          var = var->sibling;
        }

        /*memproses node anak terakhir karena belum terproses dalam pengulangan*/
        printTreePreOrder(var);
      }
    }
  }
}

//=== postorder ===//
void printTreePostOrder(node *parent) {
  if (parent != NULL) {
    node *var = parent->child;
    if (var != NULL) {
      if (var->sibling == NULL) {
        /*jika memiliki satu anak*/
        printTreePostOrder(var);
      } else {
        /*jika memiliki banyak anak*/
        /*mencetak node anak*/
        while (var->sibling != parent->child) {
          printTreePostOrder(var);
          var = var->sibling;
        }
        /*memproses node anak terakhir karena belum terproses dalam pengulangan*/
        printTreePostOrder(var);
      }
    }
    printf(" %c ", parent->info);
  }
}

/*
  COPY
*/
void copyTree(node *parent1, node **parent2) {
  if (parent1 != NULL) {
    (*parent2) = (node *) malloc(sizeof (node));

    (*parent2)->info = parent1->info;
    (*parent2)->sibling = NULL;
    (*parent2)->child = NULL;

    if (parent1->child != NULL) {
      if (parent1->child->sibling == NULL) {
        /*jika memiliki satu anak*/
        copyTree(parent1->child, &(*parent2)->child);
      } else {
        /*jika memiliki banyak anak*/
        node *var1 = parent1->child;
        node **var2 = &(*parent2)->child;

        while (var1->sibling != parent1->child) {
          copyTree(var1, &(*var2));
          var1 = var1->sibling;
          (*var2) = (*var2)->sibling;
        }
        /*memproses node anak terakhir karena belum terproses dalam pengulangan*/
        copyTree(var1, &(*var2));
      }
    }
  }
}

/*
  ISEQUAL
*/
int isEqual(node *parent1, node *parent2) {
  int hasil = 1;
  if ((parent1 != NULL) && (parent2 != NULL)) {
    if (parent1->info != parent2->info) {
      hasil = 0;
    } else {
      if ((parent1->child != NULL) && (parent2->child != NULL)) {
        if (parent1->child->sibling == NULL) {
          /*jika memiliki satu anak*/
          hasil = isEqual(parent1->child, parent2->child);
        } else {
          /*jika memiliki banyak anak*/
          node *var1 = parent1->child;
          node *var2 = parent2->child;

          while (var1->sibling != parent1->child) {
            if ((var1 != NULL) && (var2 != NULL)) {
              hasil = isEqual(var1, var2);
              var1 = var1->sibling;
              var2 = var2->sibling;
            } else {
              hasil = 0;
              break;
            }
          }

          /*memproses node anak terakhir karena belum terproses dalam pengulangan*/
          hasil = isEqual(var1, var2);
        }
      }
    }
  } else {
    if ((parent1 != NULL)||(parent2 != NULL)) {
      hasil = 0;
    }
  }
  return hasil;
}

