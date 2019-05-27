#ifndef _DEF_H_
#define _DEF_H_


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct{
	int *elem;	//元素
	int length;	//当前长度
	int tlen;	//总长度
}SqList;

void Init(SqList &L,int n);
void Create(SqList &L,int n);
void Create_p(SqList &L,int n,int m);
void Print(SqList L);
int Insert(SqList &L,int elem,int index);
int Find_Elem(SqList L,int elem);
int Find_Index(SqList L,int &index);
int Delete_Elem(SqList &L,int elem);
int Delete_Index(SqList &L,int &index);
void Destory(SqList &L);

void Sort(SqList &L,int low,int high);

#endif
