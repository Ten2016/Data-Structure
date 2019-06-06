#ifndef _DEF_H_
#define _DEF_H_

typedef int Elem;
typedef struct{
	Elem *elem;
	int front,rear;
	int max;
}SqCirQueue;

void Init(SqCirQueue &SCQ,int max);
int EnQueue(SqCirQueue &SCQ,Elem x);
int DeQueue(SqCirQueue &SCQ,Elem &x);
int IsEmpty(SqCirQueue SCQ);
int IsFull(SqCirQueue SCQ);
void Destory(SqCirQueue &SCQ);
void Print(SqCirQueue SCQ);

#endif