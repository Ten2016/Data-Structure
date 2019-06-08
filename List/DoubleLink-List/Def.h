#ifndef _DEF_H_
#define _DEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct DLNode{
	int elem;
	DLNode *prior;
	DLNode *next;
}DLNode,*DLinkList;

void Init(DLinkList &DL);
void Create_Head(DLinkList &DL,int n,int w);
void Create_Tail(DLinkList &DL,int n,int w);
void Print(DLinkList DL);
void Insert_Index(DLinkList &DL,int index,int);
void Find_Elem(DLinkList DL,int elem,int &index);
void Find_Index(DLinkList DL,int index,int &num);
void Find_Prior(DLinkList DL,int elem,int &e);
void Find_Next(DLinkList DL,int elem,int &e);
void Delete_Elem(DLinkList &DL,int elem);
void Delete_Index(DLinkList &DL,int index);
void Destory(DLinkList &DL);


#endif
