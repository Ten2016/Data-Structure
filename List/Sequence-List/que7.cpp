
/*----------问题描述----------\
	[顺序有序表]
	将两个有序表合并成一个有序表
	并返回结果顺序表

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"

int Func(SqList A,SqList B,SqList &C){
	Init(C,A.length+B.length);		//创建C
	int i=0,j=0,k=0;
	while(i<A.length && j<B.length){
		if(A.elem[i]<=B.elem[j])
			C.elem[k++]=A.elem[i++];
		else
			C.elem[k++]=B.elem[j++];
	}
	while(i<A.length)
		C.elem[k++]=A.elem[i++];
	while(j<B.length)
		C.elem[k++]=B.elem[j++];
	C.length=C.tlen;
}



int main(){
	SqList L1,L2,L3;
	Init(L1,100);
	Init(L2,100);
	Create(L1,20);
	Create(L2,10);
	printf("打印L1:\n");
	Print(L1);
	printf("打印L2:\n");
	Print(L2);
	Sort(L1,0,L1.length-1);
	Sort(L2,0,L2.length-1);
	printf("Sort打印L1:\n");
	Print(L1);
	printf("Sort打印L2:\n");
	Print(L2);
	Func(L1,L2,L3);
	printf("L3 %d:\n",L3.length);
	Print(L3);

	return 0;
}