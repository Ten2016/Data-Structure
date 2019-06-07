#ifndef _DEF_H_
#define _DEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

typedef int Elem;
typedef struct SCLNode{
	Elem elem;
	SCLNode *next;
}SCLNode;
typedef struct SCLinkList{
	SCLNode *front;
	SCLNode *rear;
}SCLinkList;



void Init(SCLinkList &SCL);
void Create_Head(SCLinkList &SCL,int n);
void Create_Tail(SCLinkList &SCL,int n);
void Print(SCLinkList SCL,int n);
int Print_Head(SCLinkList SCL);
int Print_Tail(SCLinkList SCL);
void Insert_Index(SCLinkList &SCL,int index,int n);
void Find_Elem(SCLinkList SCL,Elem elem);
void Find_Index(SCLinkList SCL,int index);
void Delete_Elem(SCLinkList &SCL,int elem);
void Delete_Index(SCLinkList &SCL,int index);
void Destory(SCLinkList &SCL);


#endif

