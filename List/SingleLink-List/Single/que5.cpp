
/*----------问题描述----------\
	带头结点的单链表L
    原地逆置
    空间复杂度O(1)

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"

//法1
void Func1(SLinkList &SL){
    if(SL->next==NULL)
        return ;
    SLNode *p,*q,*s;
    p=SL->next;
    q=p->next;
    p->next=NULL;
    while(q){
        s=q->next;
        q->next=p;
        p=q;
        q=s;
    }
    SL->next=p;
}

//法2
void Func2(SLinkList &SL){
    SLNode *p,*q;
    p=SL->next;
    SL->next=NULL;
    while(p){   //采用头插法
        q=p->next;
        p->next=SL->next;
        SL->next=p;
        p=q;
    }
}

int main(){
	SLinkList SL;
	Init(SL);
	Create_Tail(SL,10);
	printf("Print\n");
	Print(SL);
    Func1(SL);
	printf("\n逆置[法1]:\n");
    Print(SL);
    Func2(SL);
	printf("\n逆置[法2]:\n");
    Print(SL);
	return 0;
}
