
/*----------问题描述----------\
	带头结点的单链表L
    删除最小值结点[唯一]
    高效O(n)

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"


int Func(SLinkList SL){
    SLNode *pre,*p,*s;
    pre=SL;p=pre->next;
    s=pre;
    while(s->next){
        if(s->next->elem<p->elem){  //发现更小的值
            pre=s;
            p=pre->next;
        }
        s=s->next;
    }
    pre->next=p->next;
    int min=p->elem;
    delete p;
    return min;
}

int main(){
	SLinkList SL;
	Init(SL);
	Create_Tail(SL,10);
	printf("Print\n");
	Print(SL);
    int min=Func(SL);
	printf("\n删除最小值:%d\n",min);
    Print(SL);
	return 0;
}
