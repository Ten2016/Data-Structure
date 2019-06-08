
/*----------问题描述----------\
	反向输出带头结点的单链表L

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"


//采用递归方式
void func(SLinkList SL){
    SLNode *p=SL;
    if(SL->next)
        func(SL->next);
    printf("%d\t",SL->elem);
}
void Func1(SLinkList SL){
    func(SL->next);
    printf("\n");
}

//采用栈
void Func2(SLinkList SL){
    SLNode *p=SL->next;
    int cnt=0;
    while(p){   //确定长度
        p=p->next;
        cnt++;
    }
    int Stack[cnt],i=0;
    p=SL->next;
    while(p){
        Stack[i]=p->elem;
        i++;
        p=p->next;
    }
    for(i--;i>=0;i--)
        printf("%d\t",Stack[i]);
    printf("\n");
}

int main(){
	SLinkList SL;
	Init(SL);
	Create_Tail(SL,10);
	printf("Print\n");
	Print(SL);
	printf("\n反向输出[递归]\n");
	Func1(SL);
	printf("反向输出[栈]\n");
	Func2(SL);
	return 0;
}
