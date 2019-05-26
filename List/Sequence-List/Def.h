#ifndef _DEF_H_
#define _DEF_H_


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct{
	int *elem;
	int length;
}SqList;

void Create(SqList &L,int n);
void Print(SqList L);
int Insert(SqList &L,int elem,int index);
int Find_Elem(SqList L,int elem);
int Find_Index(SqList L,int &index);
int Delete_Elem(SqList &L,int elem);
int Delete_Index(SqList &L,int &index);
void Destory(SqList &L);

#endif
