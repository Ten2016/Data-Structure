
/*----------问题描述----------\
	[有序表]中删除所有值重复的元素
	使所有值均不重复

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"

int Func(SqList &L){
	if(L.length==0){
		printf("L.length==0\n");
		return -1;
	}
	int i=1;
	for(int j=1;j<L.length;j++){
		if(L.elem[j]!=L.elem[j-1]){	//与前一个不同
			L.elem[i]=L.elem[j];
			i++;
		}
	}
	L.length=i;
}



int main(){
	SqList L;
	Init(L,100);
	Create_p(L,20,11);
	printf("打印:\n");
	Print(L);
	Sort(L,0,L.length-1);
	printf("Sort打印:\n");
	Print(L);
	Func(L);
	printf("删除重复值后打印:\n");
	Print(L);

	return 0;
}