#ifndef _DEF_H_
#define _DEF_H_

#include <stdio.h>

typedef int Elem;
typedef struct{
	Elem *elem;
	int top;
	int max;
}SqStack;

void Init(SqStack &S,int n);
int IsEmpty(SqStack S);
int IsFull(SqStack S);
int Push(SqStack &S,Elem x);
int Pop(SqStack &S,Elem &x);
int GetTop(SqStack S,Elem &x);
void Clear(SqStack &S);
void Destory(SqStack &S);




#endif