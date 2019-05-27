
/*----------问题描述----------\
	逆置顺序表元素
	空间复杂度要求O(1)

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"

int Func(SqList &L){
	if(L.length==0){
		printf("L.length==0\n");
		return -1;
	}
	int i=0,j=L.length-1;
	int tmp;
	while(i<j){
		tmp=L.elem[i];
		L.elem[i]=L.elem[j];
		L.elem[j]=tmp;
		i++;
		j--;
	}
}



int main(){
	SqList L;
	Init(L,20);
	Create(L,10);
	printf("打印:\n");
	Print(L);
	Func(L);
	printf("逆置打印:\n");
	Print(L);

	return 0;
}