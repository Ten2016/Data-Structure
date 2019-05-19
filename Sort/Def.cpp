#include "Def.h"


//argc:控制台参数个数
//argv 0:程序名
//		 1:排序方法
//		 2:数据个数
//		 3:数据范围
void Create(Arr &A,int argc,char **argv){
	int m,n,flag;	
	if(argc<4){
		m=100;	//数据范围
		if(argc<3)	n=20;	//数据个数
		else		n=atoi(argv[2]);
	}
	else{
		n=atoi(argv[2]);
		m=atoi(argv[3]);
	}
	printf("排序方式:%s\n数据个数:%d\n数据范围:+-%d\n\n",argv[1],n,m);
	A.elem = new int[n+1];
	A.len=n;
	if(A.elem==NULL)
		exit(1);
	srand((unsigned)time(NULL));
	for(int i=1;i<=A.len;i++){
		n=rand();
		flag=(n%2)?1:-1;
		A.elem[i]=flag*n%m;
	}
}

void Copy(Arr A,Arr &B){
	B.elem = new int[A.len+1];
	B.len=A.len;
	for (int i=1;i<=A.len;i++)
		B.elem[i]=A.elem[i];
}

void Print(Arr A){
	for(int i=1;i<=A.len;i++){
		printf("%d\t",A.elem[i]);
	}
	printf("\n");
}

int Compare(Arr A,Arr B){
	for(int i=1;i<=A.len;i++){
		if(A.elem[i]!=B.elem[i])
			return 0;
	}
	return 1;
}

void Destory(Arr &A){
	delete [] A.elem;
}
