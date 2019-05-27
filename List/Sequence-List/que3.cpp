
/*----------问题描述----------\
	删除线性表中所有值为x的元素
	空间复杂度要求O(1)
	时间复杂度要求O(n)

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"

int Func(SqList &L,int elem){
	if(L.length==0){
		printf("L.length==0\n");
		return -1;
	}
	int i=0;
	for(int j=0;j<L.length;j++){
		if(L.elem[j]!=elem){
			L.elem[i]=L.elem[j];
			i++;
		}
	}
	L.length=i;
}



int main(){
	SqList L;
	Init(L,100);
	Create_p(L,50,3);
	printf("打印:\n");
	Print(L);
	Func(L,1);
	printf("删除1后打印:\n");
	Print(L);

	return 0;
}