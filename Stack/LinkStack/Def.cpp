#include "Def.h"

void Init(LStack &LS){
	LS=NULL;
}
int IsEmpty(LStack LS){
	if(LS==NULL)
		return 1;
	else
		return 0;
}
void Push(LStack &LS,Elem x){
	LSNode *p;
	p = new LSNode;
	p->elem=x;
	p->next=LS;
	LS=p;

}
int Pop(LStack &LS,Elem &x){
	if(LS==NULL)
		return 0;
	x=LS->elem;
	LSNode *p=LS;
	LS=LS->next;
	delete p;
	return 1;
}
int GetTop(LStack &LS,Elem &x){
	if(LS==NULL)
		return 0;
	x=LS->elem;
	return 1;
}
void Clear(LStack &LS){
	LSNode *p;
	p=LS;
	while(LS){
		LS=LS->next;
		delete p;
		p=LS;
	}
}