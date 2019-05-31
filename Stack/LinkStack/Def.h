#ifndef _DEF_H_
#define _DEF_H_

#include <stdio.h>

typedef int Elem;
typedef struct LStackNode{
	Elem elem;
	LStackNode *next;
}LSNode,*LStack;

void Init(LStack &LS);
int IsEmpty(LStack LS);
void Push(LStack &LS,Elem x);
int Pop(LStack &LS,Elem &x);
int GetTop(LStack &LS,Elem &x);
void Clear(LStack &LS);

#endif