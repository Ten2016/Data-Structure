#ifndef _DEF_H_
#define _DEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct DLNode{
	int elem;
	DLNode *prior;
	DLNode *rear;
}DLNode,*DLinkList;

void Init(DLinkList &DL);
void Create_Head(DLinkList &DL,int n);
void Create_Tail(DLinkList &DL,int n);
void Print(DLinkList DL);
void Insert_Index(DLinkList &DL,int index);
void Find_Elem(DLinkList DL,int elem);
void Find_Index(DLinkList DL,int index);
void Destory(DLinkList &DL);



#endif
