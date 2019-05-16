
#include <stdio.h>
#include <string.h>
#include <time.h>



void Create(Arr &A,char **cmd){
  int n;
  stoi(cmd,n);
  A.elem = new int[n];


}


void Print(Arr &A){
  for(int i=1;i<=A.len,i++){
    printf("%d\t",A.elem[i]);
  }
  printf("\n");
}
