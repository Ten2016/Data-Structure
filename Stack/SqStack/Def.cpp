#include "Def.h"

void Init(SqStack &S,int n){
	S.elem = new Elem[n];
	S.top=-1;
	S.max=n-1;
}

int IsEmpty(SqStack S){
	if(S.top==-1)
		return 1;
	else
		return 0;

}

int IsFull(SqStack S){
	if(S.top==S.max)
		return 1;
	else
		return 0;

}

int Push(SqStack &S,Elem x){
	if(IsFull(S))
		return 0;
	S.top++;
	S.elem[S.top]=x;
	return 1;
}

int Pop(SqStack &S,Elem &x){
	if(IsEmpty(S))
		return 0;
	x=S.elem[S.top];
	S.top--;
	return 1;
}

int GetTop(SqStack S,Elem &x){
	if(IsEmpty(S))
		return 0;
	else{
		x=S.elem[S.top];
		return 1;
	}
}

void Clear(SqStack &S){
	S.top=-1;
}
void Destory(SqStack &S){
	delete [] S.elem;
}