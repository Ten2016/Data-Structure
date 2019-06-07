#include "Def.h"

void Init(SCLinkList &SCL){
	SCL.front = new SCLNode ;	//申请附加节点
	SCL.rear=SCL.front;
	SCL.front->next=SCL.front;
}
void Create_Head(SCLinkList &SCL,int n){
	SCLNode *p;
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++){
		p = new SCLNode;
		if(p==NULL){
			printf("memory error.");
			exit(1);
		}
		p->elem=rand()%SIZE;
		p->next=SCL.front->next;
		SCL.front->next=p;
		if(i==0){
			SCL.rear=p;
			SCL.rear->next=SCL.front;
		}
	}
}
void Create_Tail(SCLinkList &SCL,int n){
	SCLNode *p;
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++){
		p = new SCLNode;
		if(p==NULL){
			printf("memory error.");
			exit(1);
		}
		p->elem=rand()%SIZE+17;
		p->next=SCL.rear->next;
		SCL.rear->next=p;
		SCL.rear=p;
	}
}
int IsEmpty(SCLinkList SCL){
	if(SCL.front==SCL.rear)
		return 1;
	else
		return 0;
}
void Print(SCLinkList SCL,int n){
	SCLNode *p;
	if(IsEmpty(SCL))
		return ;
	p=SCL.front->next;
	while(n--){
		printf("%d\t",p->elem);
		if(p==SCL.rear){
			printf("\n");
			p=p->next;
		}
		p=p->next;
	}
	printf("\n");
}
int Print_Head(SCLinkList SCL){
	if(IsEmpty(SCL))
		return 0;
	else
		printf("Head:%d\n",SCL.front->next->elem);
	return 1;
}
int Print_Tail(SCLinkList SCL){
	if(IsEmpty(SCL))
		return 0;
	else
		printf("Tail:%d\n",SCL.rear->elem);
}
void Insert_Index(SCLinkList &SCL,int index,int n){

}
void Find_Elem(SCLinkList SCL,int elem){

}
void Find_Index(SCLinkList SCL,int index){

}
void Delete_Elem(SCLinkList &SCL,int elem){

}
void Delete_Index(SCLinkList &SCL,int index){

}
void Destory(SCLinkList &SCL){
	//none
}
