#include "Def.h"

void Init(SqList &L,int n){
	L.elem = new int[n];
	if(L.elem==NULL){
		printf("memory error.\n");
		return ;
	}
	L.length=0;
	L.tlen=n;
}

void Create(SqList &L,int n){
	if(n>L.tlen){
		printf("too big.\n");
		return ;
	}
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++){
		L.elem[i]=rand()%SIZE;
	}
	L.length=n;
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
	if(index<1||index>L.length+1)
		return -1;
	//future;
	if(L.length>=L.tlen)
		return -1;
	for(int i=L.length;i>=index;i--)
		L.elem[i]=L.elem[i-1];
	L.elem[index-1]=elem;
	L.length++;
}

int Delete_Elem(SqList &L,int elem){
	//future	19.05.27
	int i;
	for(i=0;i<L.length;i++){
		if(L.elem[i]==elem)
			break;
	}
	if(i>=L.length)
		return -1;
	int j=i+1;
	Delete_Index(L,j);
	return i+1;
}

//success 	1
//fail		-1
//index返回删除元素
int Delete_Index(SqList &L,int &index){
	//future	19.05.27
	if(index<1||index>L.length)
		return -1;
	int e=L.elem[index-1];
	for(int i=index;i<L.length;i++)
		L.elem[i-1]=L.elem[i];
	L.length--;
	index=e;
}

void Destory(SqList &L){
	delete [] L.elem;
	L.length=0;
}
