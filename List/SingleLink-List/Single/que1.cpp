
/*----------问题描述----------\
	删除不带头结点的单链表L中所有值为x的结点
	采用递归算法

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"

void InitFunc(SLinkList &SL){
	srand((unsigned)time(NULL));
	SLNode *p;
	SLinkList s=SL;
	for(int i=0;i<10;i++){
		p=new SLNode;
		p->elem=rand()%3;
		if(i==0)
			s=SL=p;
		else{
			s->next=p;
			s=s->next;
		}
	}
	s->next=NULL;
}
void PrintFunc(SLinkList SL){
	SLNode *p=SL;
	while(p){
		printf("%d\t",p->elem);
		p=p->next;
	}
}
void Func(SLinkList &SL,int e){
	if(SL==NULL)
		return ;
	SLNode *p;
	if(SL->elem==e){
		p=SL;
		SL=SL->next;	
		//此处相当于SL->next->...->next=SL->next->...->next->next
		//这里SL为递归最开始的头结点
		//因此直接将删除的前后结点连接在了一起
		delete p;
		Func(SL,e);
	}
	else{
		Func(SL->next,e);	//传进SL->next
	}	

}

int main(){
	SLinkList SL;
	InitFunc(SL);
	printf("Print\n");
	PrintFunc(SL);
	Func(SL,0);
	printf("\n删除:0\n");
	PrintFunc(SL);	
	return 0;
}
