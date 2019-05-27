
/*----------问题描述----------\
	顺序表中删除其值在s和t(包含s和t,s<t)之间的所有元素
	s或t不合理,输出错误信息
	顺序表为空,输出错误信息

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"

int Func(SqList &L,int s,int t){
	if(L.length==0){
		printf("L.length==0\n");
		return -1;
	}
	if(s>=t){
		printf("s and t error.\n");
		return -1;
	}
	int i=0;
	for(int j=0;j<L.length;j++){
		if(L.elem[j]<s||L.elem[j]>t){
			L.elem[i]=L.elem[j];
			i++;
		}
	}
	L.length=i;
}



int main(){
	SqList L;
	Init(L,100);
	Create(L,20);
	printf("打印:\n");
	Print(L);
	Func(L,30,80);
	printf("删除30<=e=<80后打印:\n");
	Print(L);

	return 0;
}