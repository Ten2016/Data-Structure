
/*----------问题描述----------\
	带头结点的单链表L
    递增排序
    PS:可以将数据存在数组,采用任意排序方法
       这里采用直接操作链表元素进行排序

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"


//采用直接插入排序
void Func(SLinkList &SL){
    if(SL->next==NULL)
        return ;
    SLNode *p,*q,*s;
    p=SL->next->next;
    SL->next->next=NULL;    //此时链表只有一个元素
    while(p){   //开始插入
        s=SL;
        while(s->next && s->next->elem<p->elem)
            s=s->next;
        q=p->next;
        p->next=s->next;
        s->next=p;
        p=q;
    }
}

int main(){
	SLinkList SL;
	Init(SL);
	Create_Tail(SL,10);
	printf("Print\n");
	Print(SL);
    Func(SL);
	printf("\n递增排序\n");
    Print(SL);
	return 0;
}
