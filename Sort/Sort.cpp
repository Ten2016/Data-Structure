#include "Sort.h"
//直接插入排序
void Straight_Insertion_Sort(Arr &A){
  int i,j;
  for(i=2;i<=A.len;i++){
    if(A.elem[i]<A.elem[i-1]){
      A.elem[0]=A.elem[i];
      for(j=i-1;A.elem[0]<A.elem[j];j--)
        A.elem[j+1]=A.elem[j];
      A.elem[j+1]=A.elem[0];
    }
  }
}

//折半插入排序
void Half_Insertion_Sort(Arr &A){
	int i,j;
	int low,mid,high;
	for(i=2;i<=A.len;i++){
		if(A.elem[i]<A.elem[i-1]){
			A.elem[0]=A.elem[i];
			low=1;high=i-1;
			while(low<=high){
				mid=(low+high)/2;
				if(A.elem[mid]>A.elem[0])
					high=mid-1;
				else
					low=mid+1;
			}
			for(j=i-1;j>high;j--){
				A.elem[j+1]=A.elem[j];
			}
			A.elem[j+1]=A.elem[j];
		}
	}
}

//希尔排序
void Shell_Sort(Arr &A){



}
