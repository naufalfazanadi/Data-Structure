#include "head.h"

/* --- LIST DINAMIS !!! --- */
void createList (list *L) {
  (*L).first = NULL;
}

int countElement (list L) {
  int hasil = 0;
  if (L.first != NULL) {
    /*list tidak kosong*/
    elemen *elmt;
    /*inisialisasi*/
    elmt = L.first;

    while (elmt != NULL) {
      /*proses*/
      hasil++;
      /*iterasi*/
      elmt = elmt->next;
    }
  }
  return hasil;
}

void addFirst (object fx, list *L) {
  elemen *baru;
  baru = (elemen *) malloc (sizeof (elemen)); // malloc = locate memory

  baru->elmt = fx; // pemindahan

  if ((*L).first == NULL) {
    baru->next = NULL;
  } else {
    baru->next = (*L).first;
  }

  (*L).first = baru;
  baru = NULL;
}

void addAfter (elemen *prev, object fx, list *L) {
  elemen *baru;
  baru = (elemen *) malloc (sizeof (elemen)); // locate the memory

  baru->elmt = fx; // pemindahan

  if (prev->next == NULL) {
    baru->next = NULL;
  } else {
    baru->next = prev->next;
  }

  prev->next = baru;
  baru = NULL;
}

void addLast (object fx, list *L) {
  if ((*L).first == NULL) {
    /*jika list adalah list kosong*/
    addFirst(fx, L);
  } else {
    /*jika list tidak kosong
    /*mencari elemen terakhir list*/
    elemen *prev = (*L).first;

    while (prev->next != NULL) {
      /*iterasi*/
      prev = prev->next;
    }

    addAfter(prev, fx, L);
  }
}

void delFirst (list *L) {
  if ((*L).first != NULL) {
    /*jika list bukan list kosong*/
    elemen *hapus = (*L).first;

    if (countElement(*L) == 1) {
      (*L).first = NULL;
    } else {
      (*L).first = (*L).first->next;
      hapus->next = NULL;
    }

    free(hapus); // clean mem
  }
}

void delAfter (elemen *prev, list *L) {
  elemen *hapus = prev->next;

  if (hapus != NULL) {
    if (hapus->next == NULL) {
      prev->next = NULL;
    } else {
      prev->next = hapus->next;
      hapus->next = NULL;
    }

    free(hapus); // clean mem
  }
}

void delLast (list *L) {
  if ((*L).first != NULL) {
    /*jika list tidak kosong*/
    if (countElement(*L) == 1) {
      /*list terdiri dari satu elemen*/
      delFirst(L);
    } else {
      /*mencari elemen terakhir list*/
      elemen *last = (*L).first;
      elemen *prev;

      while (last->next != NULL) {
        /*iterasi*/
        prev = last;
        last = last->next;
      }

      delAfter(prev, L);
    }
  }
}

void delAll (list *L) {
  if (countElement(*L) != 0) {
    int i;
    for (i = countElement(*L); i >= 1; i--) {
      /*proses menghapus elemen list*/
      delLast(L);
    }
  }
}

void printElement (int menu, list L) {
  if (L.first != NULL) {
    /*jika list tidak kosong*/
    /*inisialisasi*/
    elemen *var = L.first;

    while (var != NULL) {
      /*proses*/
      if (menu == 1) { // print the signal
        printf("%s\n", var->elmt.signal);
      } else if (menu == 2) { // print the real code
        printf("%s\n", var->elmt.realCode);
      } else if (menu == 3) { // JUST for check the validation!!!
        printf("%d\n", var->elmt.validation);
      }

      /*iterasi*/
      var = var->next;
    }
  } else {
    // output jika list kosong
    if (menu == 1) {
      printf("No signal received.\n");
    } else if (menu == 2) {
      printf("Return to base immediately.\n");
    }
  }
}

object checkCode (object fx) { // MY OWN FUNCTION
  int bolStrip = 0, bolDot = 0, bolChar = 0, bolNum = 1; // the boolean . . .

  int i;
  for (i = 0; i < strlen(fx.signal); i++) {
    if (fx.signal[i] == '-') {
      bolStrip = 1; // true
    } else if (fx.signal[i] == '.') {
      bolDot = 1; // true
    } else if ((fx.signal[i] >= 'a' && fx.signal[i] <= 'z') ||
               (fx.signal[i] >= 'A' && fx.signal[i] <= 'Z')) {
      bolChar++; // true
    } else if (fx.signal[i] >= '0' && fx.signal[i] <= '9') {
      bolNum = 0; // to false
    }
  }

  int count = 0;

  if ((bolStrip == 1 || bolDot == 1) &&
      (bolChar >= 1 && bolChar <= 5) && bolNum == 1) {
    fx.validation = 1; // true and make the realcode
    for (i = 0; i < strlen(fx.signal); i++) {
      if (fx.signal[i] != '-' && fx.signal[i] != '.') {
        /* --- MOVE TO realCode --- */
        fx.realCode[count] = fx.signal[i];
        count++;
      }
    }
    fx.realCode[count] = '\0';
  } else {
    fx.validation = 0;
    // fx.realCode[0] = '\0';
  }

  return fx; // return typedef
}

int filter (list *L) {
  int filtered = 0; // counter

  if ((*L).first != NULL) {
    /*list tidak kosong*/
    elemen *var;
    elemen *prev;
    /*inisialisasi*/
    var = (*L).first;

    while (var != NULL) {
      /*proses*/
      var->elmt = checkCode(var->elmt); // Check valid sama kode asli nya

      // If the code invalid
      if (var->elmt.validation == 0) {
        if (var == (*L).first) { // del First
          delFirst(L);
          var = (*L).first; // back 1 position
          /* ENGGA ITERASI ! KARENA TETAP SI CURRENT NYA DI FIRST*/
        } else {
          delAfter(prev, L);
          var = prev; // back 1 position

          /* ITERASI */
          prev = var;
          var = var->next;
        }
        filtered++; // counter filtered
      } else {
        /* iterasi */
        prev = var;
        var = var->next;
      }
    }
  }

  return filtered;
}
/*// hold screen, template dari bu Rosa
void wait(float x) {
  //prosedur wait
  time_t start;
  time_t current;
  time(&start);
  do
    time(&current);
  while(difftime(current,start) < x);
}*/

void sorting (list *L) { // bubble sort
  if ((*L).first != NULL) {

    int flip;
    int bol;
    int iterate; // penanda untuk loop ke satu atau bukan

    elemen *counter;
    elemen *tempPrev /* pointer yang prev */, *tempNext /* pointer yang next */;

    elemen *prev; // counter previous

    do { // loop hingga tidak ada penukaran
      flip = 0;
      counter = (*L).first; // init

      prev = (*L).first; // init prev

      iterate = 0;
      while (counter->next != NULL) { // loop sebelum null

        bol = 0; // boolean untuk ke switch atau tidak
        if (strcmp(counter->elmt.realCode, counter->next->elmt.realCode) > 0 &&
            (counter->next != NULL)) { // jika counter > dari next nya
          bol = 1; // true

          /* --- SWITCHING !!! --- */

          // TEMPORARY VAR
          tempNext = counter->next->next;

          if (iterate == 0) { // Ubah next dari prev
            // TEMPORARY VAR
            tempPrev = (*L).first;
            (*L).first = counter->next;
          } else {
            // TEMPORARY VAR
            tempPrev = prev->next;
            prev->next = counter->next;
          }

          counter->next->next = tempPrev;
          counter->next = tempNext;

          flip = 1;
        }
        if (bol == 0) { /* kalau tdk ada yang ditukar maka iterasi normal */
          prev = counter;
          counter = counter->next; // iterasi
        } else { /* kalau ada yang ditukar maka iterasi dari prev */
          counter = prev->next; // iterasi
        }
      }
      iterate = 1; // kalau 1 maka bukan loop pertama
    } while(flip == 1);
  }
}

// SELECTION (FAIL!)
// void selection_sort (list *L) { // dont forget about change data type to pack
//   elemen *i, *j, *el;

//   el = (*L).first;
//   i = el;

//   elemen *min;
//   elemen *tempPrev, *tempNext;

//   elemen *prev;
//   // prev = i;
//   // prev = prev->next;
//   // printf("%s\n", prev->elmt.signal);

//   int bol, count = 0;
//   while (i != NULL) {
//     min = i; // indeks yg dalamnya angka minimal

//     // printf("%s %s\n", i->elmt.realCode, j->elmt.realCode);
//     bol = 0;
//     j = i->next; // init
//     while (j != NULL) {
//       if(strcmp(min->elmt.realCode, j->elmt.realCode) < 0 &&
//         (min->elmt.validation == 1 && j->elmt.validation == 1)) {
//         bol = 1;
//         min = j; // ganti kalau ada indeks yg lebih kecil
//       }
//       j = j->next; /* ITERASI */
//     }

//     if (bol == 1) {
//       tempPrev = prev->next;
//       tempNext = min->next;

//       if (count == 0) {
//         (*L).first = min;
//       } else {
//         prev->next = min;
//       }

//       //menukar posisi pointer
//       min->next = tempPrev;
//       i->next = tempNext;

//       prev = prev->next;

//       printElement(2, *L);
//     } else {
//       prev = i;
//     }

//     i = i->next; /* ITERASI */
//     count++;
//   }
// }