
/*----------问题描述----------\
	从顺序表中删除具有最小值的元素(唯一)
	并由函数返回被删除的值
	空出的位置由最后一个元素填补
	若为空表则显示出错并退出

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"

int Func(SqList &L){
	if(L.length==0){
		printf("L.length==0\n");
		return -1;
	}
	int mini=0,min=L.elem[0];
	int i=1;
	while(i<L.length){
		if(L.elem[i]<min){
			min=L.elem[i];
			mini=i;
		}
		i++;
	}
	L.elem[mini]=L.elem[L.length-1];
	L.length--;
	return min;
}



int main(){
	SqList L;
	Init(L,100);
	Create(L,8);
	printf("打印:\n");
	Print(L);
	int m,n=10;
	char c;
	while(n--){
		m=Func(L);
		printf("删除:%d\n",m);
		printf("打印:\n");
		Print(L);
		scanf("%c",&c);		
	}
	return 0;
}