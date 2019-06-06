#include "Def.h"

void Init(LinkQueue &LQ){
	LQ.front = new LQNode;
	LQ.rear=LQ.front;
	LQ.front->next=NULL;
}
int EnQueue(LinkQueue &LQ,Elem x){
	LQNode *p;
	p = new LQNode;
	p->e=x;
	p->next=NULL;
	LQ.rear->next=p;
	LQ.rear=p;
}
int DeQueue(LinkQueue &LQ,Elem &x){
	if(IsEmpty(LQ))
		return 0;
	LQNode *p=LQ.front->next;
	x=p->e;
	LQ.front->next=p->next;
	if(p==LQ.rear)
		LQ.rear=LQ.front;
	delete p;
	return 1;
}
int IsEmpty(LinkQueue LQ){
	if(LQ.front==LQ.rear)
		return 1;
	else
		return 0;
}
void Destory(LinkQueue &LQ){
	LQNode *q=LQ.front;
	while(q){
		LQ.front=q->next;
		delete q;
		q=LQ.front;
	}
	LQ.front=LQ.rear=NULL;
}

void Print(LinkQueue LQ){	//测试专用
	LQNode *p=LQ.front->next;
	while(p){
		printf("%d\t",p->e);
		p=p->next;
	}
	printf("\n");
}