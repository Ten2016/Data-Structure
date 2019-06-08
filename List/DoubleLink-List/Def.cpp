#include "Def.h"

void Init(DLinkList &DL){
	DL = new DLNode ;
	DL->prior=NULL;
	DL->next=NULL;
}
void Create_Head(DLinkList &DL,int n,int w){
	DLNode *p;
	srand((unsigned)time(NULL));
	while(n--){
		p = new DLNode;
		if(p==NULL){
			printf("memory error.");
			exit(1);
		}
		p->elem=rand()%w;
		p->prior=DL;
		p->next=DL->next;
		if(DL->next)
			DL->next->prior=p;
		DL->next=p;
	}
}
void Create_Tail(DLinkList &DL,int n,int w){
	DLNode *p,*s;
	srand((unsigned)time(NULL));
	s=DL;
	while(n--){
		p = new DLNode;
		if(p==NULL){
			printf("memory error.");
			exit(1);
		}
		p->elem=rand()%w;
		s->next=p;
		p->prior=s;
		s=p;
	}
	s->next=NULL;
}
void Print(DLinkList DL){
	DLNode *p;
	p=DL->next;
	while(p){
		printf("%d\t",p->elem);
		p=p->next;
	}
	printf("\n");
}
void Find_Elem(DLinkList DL,int elem,int &index){
	DLNode *p=DL->next;
	index=0;
	while(p){
		index++;
		if(p->elem==elem)
			return ;
		p=p->next;
	}
	index=-1;
}
void Find_Index(DLinkList DL,int index,int &num){
	DLNode *p=DL->next;
	num=0;
	while(p){
		num++;
		if(num==index){
			num=p->elem;
			return ;
		}
		p=p->next;
	}
	num=-1;
}
void Find_Prior(DLinkList DL,int elem,int &e){
	DLNode *p=DL->next;
	while(p){
		if(p->elem==elem){
			if(p->prior!=DL)
				e=p->prior->elem;
			else
				e=-1;
			return ;
		}
		p=p->next;
	}
	e=-1;
}
void Find_Next(DLinkList DL,int elem,int &e){
	DLNode *p=DL->next;
	while(p){
		if(p->elem==elem){
			if(p->next)
				e=p->next->elem;
			else
				e=-1;
			return ;
		}
		p=p->next;
	}
	e=-1;
}
void Insert_Index(DLinkList &DL,int index,int n){
	//virtual
}
void Delete_Elem(DLinkList &DL,int elem){
	//virtual
}
void Delete_Index(DLinkList &DL,int index){
	//virtual
}
void Destory(DLinkList &DL){
	DLNode *p;
	p=DL->next;
	while(p){
		delete DL;
		DL=p;
		p=p->next;
	}
	delete DL;
}
