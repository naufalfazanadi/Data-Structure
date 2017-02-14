#include "head.h"

/**
 * Create graph
 * @param G
 */
void createEmpty(graph *G) {
  // init to null
  (*G).first = NULL;
}

/**
 * Add the node to graph
 * @param c the added char
 * @param G the graph
 */
void addNode(char c, graph *G) {
  // init
  node *var;
  var = (node *) malloc (sizeof (node));

  // add
  var->info = c;
  var->next = NULL;
  var->arc = NULL;

  // set the pointer
  if ((*G).first == NULL) {
    /* jika graph kosong */
    (*G).first = var;
  } else {
    /* Menambahkan node baru pada akhir graph */
    node *last = (*G).first;

    while (last->next != NULL) {
      /* cari elemen terakhir */
      last = last->next;
    }

    last->next = var;
  }
}

/**
 * Add the lane to other node
 * @param dest    the node destination
 * @param initial the initial node
 */
void addLane(node *dest, node *initial) {
  if (dest != NULL && initial != NULL) {
    // init
    lane *arc;
    arc = (lane *) malloc (sizeof (lane));

    // add
    arc->next = NULL;
    arc->var = dest;

    // set the pointer
    if (initial->arc == NULL) {
      /* jika kosong */
      initial->arc = arc;
    } else {
      /* menambahkan lane baru pada akhir list lane */
      lane *last = initial->arc;

      while (last->next != NULL) {
        last = last->next;
      }

      last->next = arc;
    }
  }
}

/**
 * Delete the node from graph
 * @param c the delete char
 * @param G the graph
 */
void delNode(char c, graph *G) {
  // init
  node *var = (*G).first;

  if (var != NULL) {
    node *prec = NULL; // prec

    int ketemu = 0;
    while ((var != NULL) && (ketemu == 0)) {
      if (var->info == c) {
        ketemu = 1;
      } else {
        prec = var;
        var = var->next;
      }
    }

    if (ketemu == 1) {
      //------------------------------------- Start here
      /* Hapus lane yang mengarah ke node */
      node* hapus = (*G).first;
      while (hapus != NULL) {
        if (hapus->info != var->info) {
          /* skip jika node yang sama */
          lane *hapus2 = hapus->arc;

          int stats = 0;
          while (hapus2 != NULL && stats == 0) {
            /* Cari yang mengarah ke node deleted */
            if (hapus2->var->info == var->info) {
              stats = 1;
              delLane(var->info,hapus);
            } else {
              hapus2 = hapus2->next;
            }
          }
        }
        hapus = hapus->next;
      }
      /* Hapus semua lane yang node miliki*/
      while (var->arc != NULL) {
        delLane(var->arc->var->info,var);
      }
      //----------------------------------------- End here
      if (prec == NULL) {
        /* hapus node initial */
        (*G).first = var -> next;
      } else {
        if (var -> next == NULL) {
          /* hapus node terakhir */
          prec->next = NULL;
        } else {
          /* hapus node di tengah */
          prec->next = var->next;
          var->next = NULL;
        }
      }
      free(var);
    }
    else{
      printf("empty\n");
    }
  } else {
    printf("empty\n");
  }
}

/**
 * Delete the lane from graph
 * @param cDest   char destination
 * @param initial from. . .
 */
void delLane(char cDest, node *initial) {
  // init
  lane *arc = initial->arc;

  if (arc != NULL) {
    lane *prec = NULL; // prec

    int ketemu = 0; // boolean
    while ((arc != NULL) && (ketemu == 0)) {
      /* cari lane */
      if (arc->var->info == cDest) {
        ketemu = 1;
      } else {
        prec = arc;
        arc = arc->next;
      }
    }

    if (ketemu == 1) { // true
      if (prec == NULL) {
        if (arc->next == NULL) {
          /* jika hanya ada 1 lane */
          initial->arc = NULL;
        } else {
          initial->arc = arc->next;
        }
      } else { // false
        if (arc->next == NULL) {
          /* hapus lane terakhir */
          prec->next = NULL;
        } else {
          /* Hapus lane ditengah */
          prec->next = arc->next;
          arc->next = NULL;
        }
      }

      free(arc);
    } else {
      printf("empty\n");
    }
  } else {
    printf("empty\n");
  }
}

/**
 * Search the node / find the node
 * @param  c the searched char
 * @param  G the graph
 * @return   node hasil
 */
node *findNode(char c, graph G) {
  node *hasil = NULL;
  node *var = G.first;

  int ketemu = 0; // boolean
  while ((var != NULL) && (ketemu == 0)) {
    if (var->info == c) { // if find
      hasil = var;
      ketemu = 1;
    } else {
      var = var->next; // iterate
    }
  }

  return hasil;
}

/**
 * Print the graph
 * @param G the graph
 */
void printGraph(graph G) {
  // init
  node *var = G.first;

  if (var != NULL) {
    // loop var
    while (var != NULL) {
      printf("var %c\n",var->info);
      // loop arc
      lane *arc = var->arc;

      while (arc != NULL) {
        printf("lane %c ke %c\n", var->info, arc->var->info);
        arc=arc->next;
      }
      var = var->next;
    }
  } else {
    printf("graph kosong\n");
  }
}

/**
 * Count the graph
 * @param  G the graph
 * @return   the count of node
 */
int countGraph(graph G) { // just count graph
  int counter = 0;
  node *var = G.first;

  if (var != NULL) {
    while (var != NULL) {
      counter++;
      lane *arc = var->arc;
      while (arc != NULL) {
        counter++;
        arc=arc->next;
      }
      var = var->next;
    }
  }
  return counter;
}

/* QUEUE FUNC PROC */
void createQueue(queue *Q) {
  // set to null
  (*Q).first = NULL;
  (*Q).last = NULL;
}

int countElement(queue Q) { // count the queue
  int hasil = 0;

  if (Q.first != NULL) {
    elemen *var;
    var = Q.first;

    while (var != NULL) {
      hasil++; // count
      var = var->next; // iterate
    }
  }
  return hasil;
}

void add(char fx, queue *Q) {
  /* INIT */
  elemen *var;
  var = (elemen *) malloc (sizeof (elemen));

  // Move
  var->elmt = fx;
  var->next = NULL;

  if ((*Q).first == NULL) {
    (*Q).first = var;
  } else {
    (*Q).last->next = var;
  }

  (*Q).last = var;
  // set to null
  var = NULL;
}

void del(queue *Q) {
  if ((*Q).first != NULL) {
    if (countElement(*Q) == 1) { // del if just 1 elmt
      (*Q).first = NULL; // just set to null
      (*Q).last = NULL; // just set to null
    } else {
      elemen *var = (*Q).first;

      (*Q).first = (*Q).first->next; // move the first
      var->next = NULL; // delete..

      free(var);
    }
  }
}

void delAll(queue *Q) {
  queue Q2;
  createQueue(&Q2);

  int bol = 0;

  while (countElement(*Q) != 0) {
    if (bol == 0 && (*Q).first->elmt != temp[counterTemp-1]) {
      add((*Q).first->elmt, &Q2);
    } else if(bol == 0) {
      bol = 1;
    }
    del(Q);
  }

  // printf("%d\n", countElement(Q2));
  // printQueue(Q2);

  elemen *var = Q2.first;

  while(var != NULL) { // loop all elmt
    add(var->elmt, Q);
    del(&Q2);
    var = Q2.first; // iterate
  }

  counterTemp--;
}

void printQueue(queue Q) {
  if (Q.first != NULL) { // if not empty
    elemen *var = Q.first;

    while(var != NULL) { // loop all elmt
      if (var == Q.first) {
        printf("%c", var->elmt);
      } else {
        printf(" %c", var->elmt);
      }

      var = var->next; // iterate
    }

    printf("\n");
  } else { // if empty
    printf("Kosong!\n");
  }
}

/* MY FUNCTION AND PROC HERE !!! */
void addToGraph(char c1, char c2, graph *G) {
  // IF NOT IN GRAPH THEN ADD node
  if (findNode(c1,*G) == NULL) {
    addNode(c1,G);
  }
  if (findNode(c2,*G) == NULL) {
    addNode(c2,G);
  }

  // Add lane c1->c2
  addLane(findNode(c2,*G), findNode(c1,*G));
}

void findWay(char initial, char dest, graph G, queue *Q) {
  node *var = findNode(initial, G);
  add(var->info, Q); // add to queue

  // init arc
  lane *arc = var->arc;

  // loop arc
  while (arc != NULL) {
    // chekcpoint of node
    if (arc->next != NULL) {
      temp[counterTemp] = findNode(arc->var->info, G)->info;
      counterTemp++;
    }

    // if found
    if (arc->var->info == dest) {
      add(arc->var->info, Q); // add to queue

      // OUTPUT
      printQueue((*Q));
      delAll(Q); // dell to checkpoint
    } else if (arc->var->info != dest && arc->var->next == NULL) {
      delAll(Q);
    } else {
      // recursive
      findWay(arc->var->info, dest, G, Q);
    }
    arc = arc->next; // iterate
  }
}