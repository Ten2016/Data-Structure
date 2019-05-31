#include <stdio.h>
#include "Def.cpp"

int main(){
	LStack S;
	Init(S);
	int p,q;
	p=IsEmpty(S);
	q=3;
	printf("E:%d\n",p);
	Push(S,p);
	Push(S,q);
	p=IsEmpty(S);
	printf("E:%d\n",p);
	GetTop(S,p);
	printf("Top:%d\n",p);
	Pop(S,p);
	GetTop(S,p);
	printf("Top:%d\n",p);
	p=IsEmpty(S);
	printf("E:%d\n",p);
	Clear(S);
	p=IsEmpty(S);
	printf("E:%d\n",p);

	return 0;
}