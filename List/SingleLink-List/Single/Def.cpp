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


int Length(SLinkList SL){
	SLinkList p;
	int n=0;
	p=SL->next;
	while(p){
		n++;
		p=p->next;
	}
	return n;
}
	

int Insert_Index(SLinkList &SL,int index,int elem){
	if(index<1||index>(Length(SL)+1))
		return -1;
	SLinkList p;
	SLNode *s;
	p=SL;
	index--;
	while(index--)	p=p->next;
	s = new SLNode;
	s->elem=elem;
	s->next=p->next;
	p->next=s;
}

int Find_Elem(SLinkList SL,int elem){
	SLinkList p;
	int index=0;
	p=SL->next;
	while(p){
		index++;
		if(p->elem==elem)
			return index;
		p=p->next;
	}
	return -1;
}

int Find_Index(SLinkList SL,int index){
	if(index<1||index>Length(SL))
		return -1;
	SLinkList p;
	p=SL;
	while(index--)	p=p->next;
	return p->elem;
}
int Delete_Index(SLinkList &SL,int index){


}

int Delete_Elem(SLinkList &SL,int elem){
	


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
