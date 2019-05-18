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
			A.elem[j+1]=A.elem[0];
		}
	}
}

//希尔排序
void Shell_Sort(Arr &A){
	int i,j;
	for(int dk=A.len/2;dk>=1;dk/=2){
		for(i=1+dk;i<=A.len;i++){
			if(A.elem[i]<A.elem[i-dk]){
				A.elem[0]=A.elem[i];
				for(j=i-dk;j>0&&A.elem[0]<A.elem[j];j-=dk){
					A.elem[j+dk]=A.elem[j];
				}
				A.elem[j+dk]=A.elem[0];
			}
		}
	}
}

//冒泡排序
void Bubble_Sort(Arr &A){
	int flag;
	for(int i=1;i<A.len;i++){
		flag=0;
		for(int j=A.len;j>i;j--){
			if(A.elem[j]<A.elem[j-1]){
				int tmp=A.elem[j];
				A.elem[j]=A.elem[j-1];
				A.elem[j-1]=tmp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
}

//快速排序
void Quick_Sort(Arr &A){


}






