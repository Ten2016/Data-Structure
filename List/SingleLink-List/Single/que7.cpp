
/*----------问题描述----------\
	带头结点的单链表L
    删除给定范围内的所有数

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"


void Func(SLinkList &SL,int min,int max){
    SLNode *p,*q;
    p=SL;q=p->next;
    while(q){
        if(q->elem>=min && q->elem<=max){
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
	Create_Tail(SL,10);
	printf("Print\n");
	Print(SL);
    Func(SL,30,50);
	printf("\n删除[30-50]:\n");
    Print(SL);
	return 0;
}
