#include <stdio.h>
#include "Def.cpp"

int main(){
	SqStack S;
	Init(S,2);
	int p,q;
	p=IsEmpty(S);
	q=IsFull(S);
	printf("E:%d\nF:%d\n",p,q);
	Push(S,p);
	Push(S,q);
	p=IsEmpty(S);
	q=IsFull(S);
	printf("E:%d\nF:%d\n",p,q);
	GetTop(S,p);
	printf("Top:%d\n",p);
	Pop(S,p);
	GetTop(S,p);
	printf("Top:%d\n",p);
	p=IsEmpty(S);
	q=IsFull(S);
	printf("E:%d\nF:%d\n",p,q);
	Destory(S);

	return 0;
}