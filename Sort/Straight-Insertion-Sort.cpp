
#include <stdio.h>

int main(int argc,char **argv){

  Arr A;
  Create(A);
  Print(A);

  for(int i=2;i<=A.len;i++){
    if(A.elem[i]<A.elem[i-1]){
      A.elem[0]=A.elem[i];
      int j;
      for(j=i-1;A.elem[0]<A.elem[j];j--)
        A.elem[j+1]=A.elem[j];
      A.elem[j+1]=A.elem[0];
    }
  }
  
  Print(A);

  return 0;
}



