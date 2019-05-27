
/*----------问题描述----------\
	[顺序表]
	给定下标x
	交换x前与x后的数据

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"

void func(SqList &L,int x,int y){
	int tmp;
	while(x<y){
		tmp=L.elem[x];
		L.elem[x]=L.elem[y];
		L.elem[y]=tmp;
		x++;
		y--;
	}	
}
int Func(SqList &L,int x){
	if(x<1||x>L.length)
		return -1;
	func(L,0,x-1);
	func(L,x,L.length-1);
	func(L,0,L.length-1);
}



int main(){
	SqList L;
	Init(L,100);
	Create(L,10);
	printf("打印L:\n");
	Print(L);
	int x;
	while(1){
		scanf("%d",&x);
		Func(L,x);
		Print(L);
	}
	return 0;
}