#ifndef _DEF_H_
#define _DEF_H_

typedef int Elem;
typedef struct LQNode{
	Elem e;
	LQNode *next;
}LQNode;
typedef struct LinkQueue{
	LQNode *front,*rear;
}LinkQueue;

void Init(LinkQueue &LQ);	//带头节点
int EnQueue(LinkQueue &LQ,Elem x);
int DeQueue(LinkQueue &LQ,Elem &x);
int IsEmpty(LinkQueue LQ);
void Destory(LinkQueue &LQ);
void Print(LinkQueue LQ);	//测试专用


#endif