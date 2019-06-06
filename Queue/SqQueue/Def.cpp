#include "Def.h"

void Init(SqCirQueue &SCQ,int max){
	SCQ.elem = new Elem[max];
	SCQ.max=max;
	SCQ.front=0;
	SCQ.rear=0;
}
int EnQueue(SqCirQueue &SCQ,Elem x){
	if(SCQ.front==(SCQ.rear+1)%SCQ.max)
		return 0;
	SCQ.elem[SCQ.rear]=x;
	SCQ.rear=(SCQ.rear+1)%SCQ.max;
	return 1;
}
int DeQueue(SqCirQueue &SCQ,Elem &x){
	if(SCQ.front==SCQ.rear)
		return 0;
	x=SCQ.elem[SCQ.front];
	SCQ.front=(SCQ.front+1)%SCQ.max;
	return 1;
}
int IsEmpty(SqCirQueue SCQ){
	if(SCQ.front==SCQ.rear)
		return 1;
	else
		return 0;
}
int IsFull(SqCirQueue SCQ){
	if(SCQ.front==(SCQ.rear+1)%SCQ.max)
		return 1;
	else
		return 0;
}
void Destory(SqCirQueue &SCQ){
	delete [] SCQ.elem;
	SCQ.max=0;
}

void Print(SqCirQueue SCQ){	//测试专用
	int len=(SCQ.rear-SCQ.front+SCQ.max)%SCQ.max;
	int start=SCQ.front;
	printf("Elem:\t");
	for(int i=0;i<len;i++){
		printf("%d\t",SCQ.elem[start]);
		start=(start+1)%SCQ.max;
	}
	printf("\n");
}