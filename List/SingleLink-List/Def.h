#ifndef _DEF_H_
#define _DEF_H_

#include <stdio.h>
#include <time.h>

typedef struct SLNode{
	int elem;
	SLNode *next;
}SLNode,*SLinkList;

void Init(SLinkList &SL);
void Create_Head(SLinkList &SL,int n);
void Create_Tail(SLinkList &SL,int n);
void Print(SLinkList SL);
void Insert_Index(SLinkList &SL,int index);
void Find_Elem(SLinkList SL,int elem);
void Find_Index(SLinkList SL,int index);
void Destory(SLinkList &SL);



#endif
