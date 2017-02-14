#include "head.h"

/*
 *Make N-er tree
 *Sibling and child should be NULL
 *@param struct data.
 *@param current tree.
 */
void makeTree(object fx, tree *T) {
  node *var;
  var = (node *) malloc(sizeof (node));

  var->info = fx;
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
void addChild(object fx, node *parent) {
  if (parent != NULL) {
    /*jika parent tidak kosong*/
    node *var;
    var = (node *) malloc(sizeof (node));

    var->info = fx;
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
void delChild(object fx, node *parent) {
  node *var = parent->child;

  if (var != NULL) {
    if (var->sibling == NULL) {
      /*jika hanya mempunyai satu anak*/
      if (strcmp(parent->child->info.nama, fx.nama) == 0) {
        parent->child = NULL;
        free(var);
      } else {
        printf("tidak ada node anak dengan info karakter masukan\n");
      }
    } else {
      /*jika memiliki banyak anak*/
      node *prec = NULL;

      /*mencari node yang akan dihapus*/
      int ketemu = FALSE;
      while ((var->sibling != parent->child) && (ketemu == FALSE)) {
        if (strcmp(var->info.nama, fx.nama) == 0) {
          ketemu = TRUE;
        } else {
          prec = var;
          var = var->sibling;
        }
      }

      /*memproses node anak terakhir karena belum terproses dalam pengulangan*/
      if ((ketemu == FALSE) && (strcmp(var->info.nama, fx.nama) == 0)) {
        ketemu = TRUE;
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
OUTPUT THE TREE IN PRE-ORDER
 */
void printTreePreOrder(node *parent) {
  if (parent != NULL) {
    if (counterNode == 0) { // if awalmula or another thing that parent null
      printf("%s\n", parent->info.nama);
    } else { // else use space and |%s
      int counter;

      int spasi = 0;
      for (counter = parent->info.level-1; counter >= 0; counter--) {
        spasi += space[counter]; // sum the space with level below
      }
      for (counter = 0; counter < spasi; counter++) {
        printf(" "); // output space
      }

      printf("|%s\n", parent->info.nama);
    }

    /* OUTPUT DOSA */
    int i;
    for (i = 0; i < parent->info.m; i++) {
      int counter;

      int spasi = 0;
      for (counter = parent->info.level-1; counter >= 0; counter--) {
        spasi += space[counter];
      }
      for (counter = 0; counter < spasi; counter++) {
        printf(" ");
      }

      printf(" %s\n", parent->info.minus[i]);
    }

    /* OUTPUT PAHALA */
    for (i = 0; i < parent->info.p; i++) {
      int counter;

      int spasi = 0;
      for (counter = parent->info.level-1; counter >= 0; counter--) {
        spasi += space[counter];
      }
      for (counter = 0; counter < spasi; counter++) {
        printf(" ");
      }

      printf(" %s\n", parent->info.plus[i]);
    }

    // The condition to stop the \n in the end
    if (counterNode != nNode-1) {
      printf("\n");
    }

    /* RECURSIVE !!! */
    node *var  = parent->child;

    if (var != NULL) {
      if (var->sibling == NULL) {
        /*jika memiliki satu anak*/
        counterNode++;
        printTreePreOrder(var);
      } else {
        /*jika memiliki banyak anak*/
        /*mencetak node anak*/
        while (var->sibling != parent->child) {
          counterNode++;
          printTreePreOrder(var);
          var = var->sibling;
        }

        /*memproses node anak terakhir karena belum terproses dalam pengulangan*/
        counterNode++;
        printTreePreOrder(var);
      }
    }
  }
}

/**
 * Find Node Func
 * @param  search [the searched name]
 * @param  parent [parent nya]
 * @return        [hasil->node]
 */
node *findNode(char search[], node *parent) {
  node *hasil = NULL;

  if (parent != NULL) {
    if (strcmp(parent->info.nama, search) == 0) {
      hasil = parent;
    } else {
      node *var = parent->child;
      if (var != NULL) {
        if (var->sibling == NULL) {
          /*jika memiliki satu anak*/
          if (strcmp(var->info.nama, search) == 0) {
            hasil = var;
          } else {
            hasil = findNode(search, var);
          }
        } else {
          /*jika memiliki banyak anak*/
          int ketemu = FALSE;

          while ((var->sibling != parent->child) && (ketemu == FALSE)) {
            if (strcmp(var->info.nama, search) == 0) {
              hasil = var;
              ketemu = TRUE;
            } else {
              if (hasil == NULL) {
                hasil = findNode(search, var);
                var = var->sibling;
              } else {
                ketemu = TRUE;
              }
            }
          }

          /*memproses node anak terakhir karena belum terproses dalam pengulangan*/
          if (ketemu == FALSE) {
            if (strcmp(var->info.nama, search) == 0) {
              hasil = var;
            } else {
              if (hasil == NULL) {
                hasil = findNode(search, var);
                var = var->sibling;
              } else {
                ketemu = TRUE;
              }
            }
          }
        }
      }
    }
  }

  return hasil; // return the hasil of searched node
}

/* ----------------------- TMD FUNCTION AND PROC ---------------------------- */
/**
 * Add to N-er Tree, separate the strCommand
 * @param command [input the command]
 * @param T       [the tree]
 */
void addToTree (char command[], tree *T) {
  int i;

  char strParent[32]; // var to filled by parent of the added
  object added; // the object of added to tree

  // TEMP FOR ATOI
  char tempT[8];
  char tempK[8];

  // counter
  int counter = 0;
  int counterChar = 0;

  /* START SEPARATING THE COMMAND */
  for (i = 0; i < strlen(command); i++) {
    switch (counter) {
      case 0 : { // if the first word
        if (command[i] != '#') {
          // move char to strParent
          strParent[counterChar] = command[i];
          counterChar++;
        } else {
          strParent[counterChar] = '\0';
          counterChar = 0;
          counter++;
        }
      } break;

      case 1 : { // if the second word
        if (command[i] != '#') {
          // move char to struct.nama
          added.nama[counterChar] = command[i];
          counterChar++;
        } else {
          added.nama[counterChar] = '\0';
          counterChar = 0;
          counter++;
        }
      } break;

      case 2 : { // if the third word
        if (command[i] != '#') {
          // move to temp first
          tempT[counterChar] = command[i];
          counterChar++;
        } else {
          // if it's the end then convert it to int
          tempT[counterChar] = '\0';
          added.m = atoi(tempT); // move to struct.m

          counterChar = 0;
          counter++;
        }
      } break;

      case 3 : { // if the last word
        // move to temp first
        tempK[counterChar] = command[i];
        counterChar++;

        if (i+1 == strlen(command)) { // if the end of the string of command
          // convert it
          tempK[counterChar] = '\0';
          added.p = atoi(tempK); // move the converted to struct.p

          counterChar = 0;
          counter++;
        }
      } break;
    }
  }

  /* INPUT FOR MINUS */
  for (i = 0; i < added.m; i++) {
    scanf("%s", &added.minus[i]);
  }

  /* INPUT FOR PLUS */
  for (i = 0; i < added.p; i++) {
    scanf("%s", &added.plus[i]);
  }

  /* ADD TO TREE HERE */
  if (strcmp(strParent, "null") == 0) { // if parent null then..
    makeTree(added, T); // make a tree
    setLevel(added.nama, (*T).parent);
    nNode++; // iterate the n of Node
  } else {
    if (nNode != 0) {
      // just add child by parent
      addChild(added, findNode(strParent, (*T).parent));

      /* SET LEVEL */
      setLevel(added.nama, (*T).parent);
      nNode++; // iterate the n of Node
    }
  }
}

/**
 * Set the level of the node and get the maxLevel
 * @param nama   [the searched]
 * @param parent [parent]
 */
void setLevel(char nama[], node *parent) {
  // find the node first
  findNode(nama, parent)->info.level = getLevel(parent, nama, 0);

  if (maxLevel < getLevel(parent, nama, 0)) {
    maxLevel = getLevel(parent, nama, 0);
  }
}

/* Returns level of given data value */
// --------------------------------------------------
/* TY to  StackOverflow, i got this function :D*/
// --------------------------------------------------
int getLevel(node *parent, char nama[], int level) {
  // init
  node *temp = parent;
  node *var;

  int downlevel;

  // if just that node
  if (parent == NULL)
    return 0;

  if (parent->sibling == NULL) { // if not have sibling
    if (strcmp(parent->info.nama, nama) == 0)
      return level;

    var = parent->child;

    if (var != NULL) {
      // downlevel (recursive)
      downlevel = getLevel(var, nama, level+1);
      // if the result is not 0, then return the result
      if (downlevel != 0)
        return downlevel;
    }
  } else { // if have sibling then check all
    while (parent->sibling != temp) {
      if (strcmp(parent->info.nama, nama) == 0)
        return level;

      var = parent->child;

      if (var != NULL) {
        downlevel = getLevel(var, nama, level+1);
        if (downlevel != 0)
          return downlevel;
      }

      parent = parent->sibling;
    }

    if (strcmp(parent->info.nama, nama) == 0)
      return level;

    var = parent->child;

    if (var != NULL) {
      downlevel = getLevel(var, nama, level+1);
      if (downlevel != 0)
        return downlevel;
    }
  }

  return downlevel; // return the result
}

/**
 * Delete the string (like eval 1 alpro1)
 */
void delArrStr(int index, int n, char str[32][64]) {
  int i;
  for (i = index; i < n-1; i++) {
    strcpy(str[i], str[i+1]); // geser
  }
}

/**
 * Deleting the dosa (minus)
 * @param tanggungJawab [the struct (of minus and plus) here minus]
 * @param keberuntungan [the struct (of minus and plus) here plus to add]
 * @param parent        [parent]
 */
void delMinus(behavior tanggungJawab, behavior keberuntungan, node *parent) {
  if (parent != NULL) {
    int find = FALSE; // set to FALSE first

    if (strcmp(parent->info.nama, "awalmula") != 0) { // if not awalmula
      int i, j;
      // find in the node of all tree...
      for (i = 0; i < tanggungJawab.n; i++) {
        for (j = 0; j < parent->info.m; j++) {
          if (strcmp(tanggungJawab.str[i], parent->info.minus[j]) == 0) {
            find = TRUE; // set to TRUE if found

            // Then delete the array of string
            delArrStr(j, parent->info.m, parent->info.minus);
            parent->info.m--; // the counter dec
          }
        }
      }
    }

    // if true have a deleted array then add plus
    if (find) {
      addPlus(keberuntungan, parent);
      find = FALSE; // set to false again before recursive
    }

    /* RECURSIVE HERE TO NEXT NODE */
    node *var  = parent->child;

    if (var != NULL) {
      if (var->sibling == NULL) {
        /*jika memiliki satu anak*/
        delMinus(tanggungJawab, keberuntungan, var);
      } else {
        /*jika memiliki banyak anak*/
        /*mencetak node anak*/
        while (var->sibling != parent->child) {
          delMinus(tanggungJawab, keberuntungan, var);
          var = var->sibling;
        }

        /*memproses node anak terakhir karena belum terproses dalam pengulangan*/
        delMinus(tanggungJawab, keberuntungan, var);
      }
    }
  }
}

/**
 * Add the plus that having deleted minus
 * @param keberuntungan [the plus thing]
 * @param parent        [parent]
 */
void addPlus(behavior keberuntungan, node *parent) {
  int i;
  // Add to array of string of plus
  for (i = 0; i < keberuntungan.n; i++) {
    strcpy(parent->info.plus[parent->info.p], keberuntungan.str[i]);
    parent->info.p++;
  }
}

/* SPACING HERE */

/**
 * Set the max length of string in the node, check the nama plus and minus
 * @param parent [description]
 */
void setMaxLength(node *parent) {
  // max nama
  if (maxLength < strlen(parent->info.nama)) {
    maxLength = strlen(parent->info.nama);
  }

  // max minus
  int i;
  for (i = 0; i < parent->info.m; i++) {
    if (maxLength < strlen(parent->info.minus[i])) {
      maxLength = strlen(parent->info.minus[i]);
    }
  }

  // max plus
  for (i = 0; i < parent->info.p; i++) {
    if (maxLength < strlen(parent->info.plus[i])) {
      maxLength = strlen(parent->info.plus[i]);
    }
  }
}

/**
 * Get the max space in that level
 * @param level  [what level is it]
 * @param parent [parent]
 */
void getSpaceLevel(int level, node *parent) {
  if (parent != NULL) {
    if (parent->info.level == level) {
      setMaxLength(parent);
    }

    node *var  = parent->child;

    if (var != NULL) {
      if (var->sibling == NULL) {
        /*jika memiliki satu anak*/
        getSpaceLevel(level, var);
      } else {
        /*jika memiliki banyak anak*/
        /*mencetak node anak*/
        while (var->sibling != parent->child) {
          getSpaceLevel(level, var);
          var = var->sibling;
        }

        /*memproses node anak terakhir karena belum terproses dalam pengulangan*/
        getSpaceLevel(level, var);
      }
    }
  }
}

/**
 * Set the space all of the tree
 * @param T [Tree]
 */
void setSpace(tree T) {
  int i;
  for (i = 0; i < maxLevel; i++) {
    maxLength = 0;
    getSpaceLevel(i, T.parent);
    space[i] = maxLength;

    if (i != 0) {
      space[i]++;
    }
  }
}