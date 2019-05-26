#include <stdio.h>
#include "Def.cpp"


int main(){
	SqList L;
	int num=20;
	int p,q=3;
	Create(L,num);
	Print(L);
	p=L.elem[4];
	printf("%d\n",Find_Elem(L,p));
	Find_Index(L,q);
	printf("%d\n",q);
	Destory(L);
	return 0;
} 
