#include "head.h"

int main(){
  graph G;
  createEmpty(&G);
  addSimpul('A',&G);
  addSimpul('B',&G);
  addSimpul('C',&G);
  addSimpul('D',&G);
  addSimpul('E',&G);
  addSimpul('F',&G);
  addJalur(findSimpul('B',G),findSimpul('A',G));
  addJalur(findSimpul('C',G),findSimpul('B',G));
  addJalur(findSimpul('E',G),findSimpul('B',G));
  addJalur(findSimpul('D',G),findSimpul('C',G));
  addJalur(findSimpul('F',G),findSimpul('D',G));
  char del;
  scanf(" %c",&del);
  printGraph(G);
  delSimpul(del,&G);
  printf("-----\n");
  printGraph(G);
  return 0;
}