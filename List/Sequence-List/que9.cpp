
/*----------问题描述----------\
	[顺序有序表]
	查找数值为x的元素
	若找到,与后继元素交换
	若找不到,插入表中,使其仍然有序

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"

int Func(SqList &L,int x){
	int low=0,high=L.length-1;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(L.elem[mid]==x)
			break;
		else if(L.elem[mid]<x)
			low=mid+1;
		else
			high=mid-1;
	}
	if(L.elem[mid]==x && mid<L.length-1){		//找到并且不是最后一个元素
		int tmp=L.elem[mid];
		L.elem[mid]=L.elem[mid+1];
		L.elem[mid+1]=tmp;
	}
	else{
		for(int i=L.length-1;i>high;i--)
			L.elem[i+1]=L.elem[i];
		L.elem[high+1]=x;
		L.length++;
	}
}



int main(){
	SqList L;
	Init(L,100);
	Create(L,10);
	printf("打印L:\n");
	Print(L);
	Sort(L,0,L.length-1);
	printf("Sort打印:\n");
	Print(L);
	int x;
	while(1){
		scanf("%d",&x);
		Func(L,x);
		Print(L);
	}
	return 0;
}