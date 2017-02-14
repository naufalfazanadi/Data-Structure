#include "head.h"

int main(){
  tree T;
  makeTree('A', &T);
  addChild('B', T.parent);
  addChild('C', T.parent);
  addChild('D', T.parent);

  node *var = findNode('B', T.parent);
  if(var != NULL){
    addChild('E', var);
    addChild('F', var);
  }

  var = findNode('C', T.parent);
  if(var != NULL){
    addChild('G', var);
  }

  var = findNode('D',T.parent);
  if(var != NULL){
    addChild('H', var);
    addChild('I', var);
    addChild('J', var);
  }

  var = findNode('J',T.parent);
  if(var != NULL){
    addChild('K', var);
    addChild('L', var);
    addChild('M', var);
  }
  printf("====================\n");
  printf("PreOrder\n");
  printTreePreOrder(T.parent);
  printf("\n====================\n");
  printf("PostOrder\n");
  printTreePostOrder(T.parent);
  printf("\n====================\n");

  tree T2;
  copyTree(T.parent, &T2.parent);
  if(isEqual(T.parent, T2.parent)==1){
    printf("pohon sama\n");
  }else{
    printf("pohon tidak sama\n");
  }
  printf("TREE 1\n");
  printTreePreOrder(T.parent);
  printf("\nTREE 2\n");
  printTreePreOrder(T2.parent);

  var = findNode('J', T.parent);
  if(var != NULL){
    delChild('K',var);
    delChild('L',var);
    delChild('M',var);
  }
  printf("====================\n");
  printf("PreOrder setelah dihapus\n");
  printTreePreOrder(T.parent);
  printf("\n====================\n");

  return 0;
}