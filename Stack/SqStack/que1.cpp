
/*------问题描述--------\
	实现一个顺序存储的共享栈
	即：两端为两个栈底,栈顶同时向中间靠拢

\---------------------*/

#include <stdio.h>

typedef int Elem;
typedef struct{
	Elem *elem;
	int top1,top2;
	int max;
}ShareStack;

void Init(ShareStack &SS,int n){
	SS.elem = new Elem[n];
	SS.top1=-1;
	SS.top2=n;
	SS.max=n;
}

int IsEmpty(ShareStack SS,int index){
	if(index==1&&SS.top1==-1)
		return 1;
	if(index==2&&SS.top2==SS.max)
		return 1;
	return 0;
}

int IsFull(ShareStack SS){
	if(SS.top2-SS.top1==1)
		return 1;
	else
		return 0;
}

int Push(ShareStack &SS,int index,int x){
	if(IsFull(SS))
		return 1;
	if(index==1){
		SS.top1++;
		SS.elem[SS.top1]=x;
	}
	else if(index==2){
		SS.top2--;
		SS.elem[SS.top2]=x;
	}
}

int Pop(ShareStack &SS,int index,int &x){
	if(index==1){
		if(IsEmpty(SS,1))
			return 0;
		x=SS.elem[SS.top1];
		SS.top1--;
	}
	else if(index==2){
		if(IsEmpty(SS,2))
			return 0;
		x=SS.elem[SS.top2];
		SS.top2++;
	}
	return 1;
}

void Clear(ShareStack &SS){
	SS.top1=-1;
	SS.top2=SS.max;
}

void Destory(ShareStack &SS){
	delete [] SS.elem;
}

int main(){
	ShareStack SS;
	Init(SS,100);
	int p;
	printf("E1:%d\tE2:%d\n",IsEmpty(SS,1),IsEmpty(SS,2));
	printf("F:%d\n",IsFull(SS));
	Push(SS,1,1);
	Push(SS,2,2);
	Push(SS,2,3);
	Pop(SS,2,p);
	printf("P2:%d\n",p);
	Destory(SS);
	printf("finished in 19.05.30\n");
	return 0;
}