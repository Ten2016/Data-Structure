#include "Def.h"

void Create(SqList &L,int n){
	L.elem = new int[n];
	if(L.elem==NULL)
		printf("error");
	L.length=n;
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++){
		L.elem[i]=rand()%SIZE;
	}
}

void Print(SqList L){
	for(int i=0;i<L.length;i++){
		printf("%d\t",L.elem[i]);
	}
	printf("\n");
}

int Find_Elem(SqList L,int elem){
	for(int i=0;i<L.length;i++){
		if(L.elem[i]==elem)
			return i+1;
	}
	return -1;
}

int Find_Index(SqList L,int &index){
	if(index<1||index>L.length)
		return -1;
	index=L.elem[index-1];
	return 1;
}

int Insert(SqList &L,int elem,int index){
;
}

int Delete_Elem(SqList &L,int elem){
;
}


int Delete_Index(SqList &L,int &index){
;
}

void Destory(SqList &L){
	delete [] L.elem;
	L.length=0;
}
