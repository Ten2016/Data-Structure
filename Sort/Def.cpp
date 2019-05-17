#include <stdio.h>
#include <string.h>
#include <time.h>


//argc:控制台参数个数
//argv 0:程序名
//		 1:排序方法
//		 2:数据个数
//		 3:数据范围
void Create(Arr &A,int argc,char **argv){
  int m,n,flag;
	if(argc<4){
		m=20;	//数据范围
		if(argc<3)
			n=10;	//数据个数
		else
			n=atoi(argv[2]);
	}
	else{
		n=atoi(argv[2]);
		m=atoi(argv[3]);
	}
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

void Print(Arr &A){
  for(int i=1;i<=A.len,i++){
    printf("%d\t",A.elem[i]);
  }
  printf("\n");
}
