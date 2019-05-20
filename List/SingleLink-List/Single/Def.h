#ifndef _DEF_H_
#define _DEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct SLNode{
	int elem;
	SLNode *next;
}SLNode,*SLinkList;

void Init(SLinkList &SL);
void Create_Head(SLinkList &SL,int n);
void Create_Tail(SLinkList &SL,int n);
void Print(SLinkList SL);
int Insert_Index(SLinkList &SL,int index,int elem);
int Find_Elem(SLinkList SL,int elem);
int Find_Index(SLinkList SL,int index);
int Delete_Index(SLinkList &SL,int index);
int Delete_Elem(SLinkList &SL,int elem);
void Destory(SLinkList &SL);



#endif
