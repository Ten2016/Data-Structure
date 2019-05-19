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
int Partition(Arr &A,int low,int high){
	int p=A.elem[low];	//选择第一个作为划分点
	while(low<high){
		while(low<high && A.elem[high]>=p)	high--;
		A.elem[low]=A.elem[high];
		while(low<high && A.elem[low]<=p)	low++;
		A.elem[high]=A.elem[low];
	}
	A.elem[low]=p;
	return low;
}
void Quick(Arr &A,int low,int high){
	if(low<high){
		int n=Partition(A,low,high);
		Quick(A,low,n-1);	//对左半边排序
		Quick(A,n+1,high);	//对右半边排序
	}
}
void Quick_Sort(Arr &A){
	Quick(A,1,A.len);
}


//简单选择排序
void Select_Sort(Arr &A){
	int i,k,tmp;
	for(i=1;i<A.len;i++){
		k=i;
		for(int j=i+1;j<=A.len;j++)
			if(A.elem[k]>A.elem[j])
				k=j;
		if(k!=i){
			tmp=A.elem[i];
			A.elem[i]=A.elem[k];
			A.elem[k]=tmp;
		}
	}
}





