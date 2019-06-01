
/*----------问题描述----------\
	[顺序表]
	找出序列中的主元素
	主元素定义为某个数x的个数超过n/2

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"

//先扫描一遍,确定候选结果
//再扫描一遍,验证
int Func(SqList L){
	int x,cnt;
	x=L.elem[0];cnt=1;
	for(int i=1;i<L.length;i++){//第一遍
		if(L.elem[i]==x)
			cnt++;
		else{
			if(cnt>0)
				cnt--;
			else{
				x=L.elem[i];
				cnt=1;
			}
		}
	}
	if(cnt>0){
		cnt=0;
		for(int i=0;i<L.length;i++){
			if(L.elem[i]==x)
				cnt++;
			if(cnt>(L.length/2))
				return x;
		}
		return -1;
	}
	else
		return -1;
}


//另一种,分治
//如果这个数是主元素
//那么必是左右子序列某个的主元素
int Funcc(SqList L){
	//future
	return 0;
}

void Check(SqList L,int &a,int &b,int &c){
	a=b=c=0;
	for(int i=0;i<L.length;i++){
		if(L.elem[i]==0)
			a++;
		else if(L.elem[i]==1)
			b++;
		else
			c++;
	}
}


int main(){
	SqList L;
	Init(L,100);
	Create_p(L,20,3);
	printf("打印L:\n");
	Print(L);
	printf("Is:%d\n",Func(L));

	int a,b,c;
	Check(L,a,b,c);
	printf("\n0:%d\n1:%d\n2:%d\n",a,b,c);
	return 0;
}