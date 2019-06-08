
/*----------问题描述----------\
	删除带头结点的单链表L中所有值为x的结点
	x值不唯一

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"


void Func(SLinkList &SL,int e){
	SLNode *p,*q;
	p=SL;
	q=p->next;
	while(q){
		if(q->elem==e){
			p->next=q->next;
			delete q;
			q=p->next;
		}
		else{
			p=q;
			q=q->next;
		}
	}
}

int main(){
	SLinkList SL;
	Init(SL);
	Create_Tail(SL,100);
	printf("Print\n");
	Print(SL);
	printf("\n删除:0\n");
	Func(SL,0);
	Print(SL);
	return 0;
}
