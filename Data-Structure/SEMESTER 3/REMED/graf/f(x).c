#include "head.h"

void createEmpty(graph *G){
  // init to null
  (*G).first = NULL;
}

void addSimpul(char c, graph *G){
  // init
  simpul *node;
  node = (simpul *) malloc (sizeof (simpul));

  // add
  node->info = c;
  node->next = NULL;
  node->arc = NULL;

  // set the pointer
  if((*G).first == NULL){
    /* jika graph kosong */
    (*G).first = node;
  }else{
    /* Menambahkan simpul baru pada akhir graph */
    simpul *last = (*G).first;

    while(last->next != NULL){
      /* cari elemen terakhir */
      last = last->next;
    }

    last->next = node;
  }
}

void addJalur(simpul *tujuan, simpul *awal){
  if(tujuan != NULL && awal != NULL){
    // init
    jalur *arc;
    arc = (jalur *) malloc (sizeof (jalur));

    // add
    arc->next = NULL;
    arc->node = tujuan;

    // set the pointer
    if(awal->arc == NULL){
      /* jika kosong */
      awal->arc = arc;
    }else{
      /* menambahkan jalur baru pada akhir list jalur */
      jalur *last = awal->arc;

      while(last->next != NULL){
        last=last->next;
      }

      last->next = arc;
    }
  }
}

void delJalur(char cTujuan, simpul *awal){
  // init
  jalur *arc = awal->arc;

  if(arc != NULL){
    jalur *prec = NULL; // prec

    int ketemu = 0; // boolean
    while((arc!= NULL) && (ketemu == 0)){
      /* cari jalur */
      if(arc->node->info == cTujuan){
        ketemu = 1;
      }else{
        prec = arc;
        arc = arc->next;
      }
    }

    if(ketemu == 1){ // true
      if(prec==NULL){
        if(arc->next == NULL){
          /* jika hanya ada 1 jalur */
          awal->arc = NULL;
        }else{
          awal->arc = arc->next;
        }
      }else{ // false
        if(arc->next == NULL){
          /* hapus jalur terakhir */
          prec->next = NULL;
        }else{
          /* Hapus jalur ditengah */
          prec->next = arc->next;
          arc->next = NULL;
        }
      }

      free(arc);
    }else{
      printf("empty\n");
    }
  }else{
    printf("empty\n");
  }
}

void delSimpul(char c, graph *G){
  // init
  simpul* elmt = (*G).first;


  if(elmt != NULL){
    simpul *prec = NULL; // prec

    int ketemu = 0;
    while((elmt != NULL) && (ketemu == 0)){
      if(elmt->info == c){
        ketemu = 1;
      }else{
        prec = elmt;
        elmt = elmt->next;
      }
    }

    if(ketemu == 1){
      //------------------------------------- Start here
      /* Hapus jalur yang mengarah ke simpul */
      simpul* hapus = (*G).first;
      while(hapus != NULL){
        if(hapus->info != elmt->info){
          /* skip jika simpul yang sama */
          jalur* hapus2 = hapus->arc;
          int stats = 0;
          while(hapus2 != NULL && stats == 0){
            /* Cari yang mengarah ke simpul deleted */
            if(hapus2->node->info == elmt->info){
              stats = 1;
              delJalur(elmt->info,hapus);
            }else{
              hapus2 = hapus2->next;
            }
          }
        }
        hapus=hapus->next;
      }
      /* Hapus semua jalur yang simpul miliki*/
      while(elmt->arc != NULL){
        delJalur(elmt->arc->node->info,elmt);
      }
      //----------------------------------------- End here
      if(prec == NULL){
        /* hapus simpul awal */
        (*G).first = elmt -> next;
      }else{
        if(elmt -> next == NULL){
          /* hapus simpul terakhir */
          prec->next = NULL;
        }else{
          /* hapus simpul di tengah */
          prec->next = elmt->next;
          elmt->next = NULL;
        }
      }
      free(elmt);
    }
    else{
      printf("empty\n");
    }
  }else{
    printf("empty\n");
  }
}

simpul *findSimpul(char c, graph G){
  simpul *hasil = NULL;
  simpul *node = G.first;

  int ketemu = 0; // boolean
  while((node != NULL) && (ketemu == 0)){
    if(node->info == c){ // if find
      hasil = node;
      ketemu = 1;
    }else{
      node = node->next; // iterate
    }
  }

  return hasil;
}

void printGraph(graph G){
  // init
  simpul *node = G.first;

  if(node != NULL){
    // loop node
    while(node != NULL){
      printf("Node %c\n",node->info);
      // loop arc
      jalur *arc = node->arc;

      while(arc != NULL){
        printf("Jalur %c ke %c\n", node->info, arc->node->info);
        arc=arc->next;
      }
      node = node->next;
    }
  }else{
    printf("graph kosong\n");
  }
}

int countGraph(graph G){ // just count graph
  int counter = 0;
  simpul *node = G.first;
  if(node != NULL){
    while(node != NULL){
      counter++;
      jalur *arc = node->arc;
      while(arc != NULL){
        counter++;
        arc=arc->next;
      }
      node = node->next;
    }
  }
  return counter;
}

/* MY FUNCTION AND PROC HERE !!! */
void addToGraph(char c1, char c2, graph *G) {
  // IF NOT IN GRAPH THEN ADD SIMPUL
  if (findSimpul(c1,*G) == NULL) {
    addSimpul(c1,G);
  }
  if (findSimpul(c2,*G) == NULL) {
    addSimpul(c2,G);
  }

  // Add jalur c1-c2
  addJalur(findSimpul(c2,*G),findSimpul(c1,*G));
}

int cekJalur(char find[], graph G) {
  int i;

  // just for init
  char c1 = '0';
  char c2 = '0';

  // init bol
  int bolLg = 0;
  int bolSm = 1; // init to 1 first

  i = 0;
  while (i < strlen(find) && bolLg == 0) { // loop
    if (find[i] != '-') {
      c2 = find[i]; // add to c2

      if (c1 != '0') { // if not empty (not the first checking)
        // init node
        simpul *node = findSimpul(c1, G);

        // find jalur from c1 to c2
        jalur *arc = node->arc;

        bolSm = 0; // to false
        while (node != NULL && arc != NULL && bolSm == 0) {
          if (arc->node->info == c2) {
            bolSm = 1; // true
          }
          arc = arc->next; // iterate
        }
      }

      // if the jalur not find
      if (bolSm == 0) {
        bolLg = 1; // break
      }

      c1 = c2; // slide the char
    }
    i++; // iterate
  }

  if (bolLg == 1) {
    return 0; // false
  } else {
    return 1; // true
  }
}