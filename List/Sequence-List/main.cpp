#include <stdio.h>
#include "Def.cpp"


int main(){
	SqList L;
	int num=20;
	int p,q=3;
	Init(L,100);
	Create(L,num);
	Print(L);
	printf("\n");
	p=L.elem[4];
	printf("查询数据:%d\t下标:%d\n",p,Find_Elem(L,p));
	printf("查询下标:%d\t",q);
	Find_Index(L,q);
	printf("数据:%d\n",q);
	printf("打印:\n");
	Print(L);
	Insert(L,222,1);
	Insert(L,111,12);
	Insert(L,333,20);
	Insert(L,444,24);
	printf("打印:\n");
	Print(L);
	p=1;
	Delete_Index(L,p);
	p=23;
	Delete_Index(L,p);
	p=20;
	Delete_Index(L,p);
	printf("打印:\n");
	Print(L);	
	p=13;
	Find_Index(L,p);
	printf("删除元素：%d\n",p);
	p=Delete_Elem(L,p);
	printf("已删除,位置:%d\n",p);
	printf("打印:\n");
	Print(L);	
	Destory(L);
	return 0;
} 
