#include "Def.h"

void Init(SLinkList &SL){
	SL = new SLNode ;
	SL->next=NULL;
}

void Create_Head(SLinkList &SL,int n){
	SLNode *p;
	srand((unsigned)time(NULL));
	while(n--){
		p = new SLNode;
		if(p==NULL){
			printf("memory error.");
			exit(1);
		}
		p->elem=rand()%SIZE;
		p->next=SL->next;
		SL->next=p;
	}
}

void Create_Tail(SLinkList &SL,int n){
	SLNode *p,*s;
	srand((unsigned)time(NULL));
	while(n--){
		p = new SLNode;
		if(p==NULL){
			printf("memory error.");
			exit(1);
		}
		p->elem=rand()%SIZE;
		s=SL;
		while(s->next)
			s=s->next;
		s->next=p;
		p->next=NULL;
	}
}


void Print(SLinkList SL){
	SLNode *p;
	p=SL->next;
	while(p){
		printf("%d\t",p->elem);
		p=p->next;
	}
	printf("\n");
}

void Insert_Index(SLinkList &SL,int index){


}

void Find_Elem(SLinkList SL,int elem){


}

void Find_Index(SLinkList SL,int index){


}

void Destory(SLinkList &SL){
	SLNode *p;
	p=SL->next;
	while(p){
		delete SL;
		SL=p;
		p=p->next;
	}
}
