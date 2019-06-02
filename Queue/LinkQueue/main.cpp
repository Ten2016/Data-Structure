#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Def.cpp"

int main(){
	LQueue LQ;
	Init(SCQ,100);
	printf("输入操作指令[#退出]:\n");
	char c;int x,y;
	while(1){
		scanf("%c",&c);
		switch(c){
			case 'e':
			case 'E':scanf("%d",&x);EnQueue(SCQ,x);
						Print(SCQ);break;
			case 'i':printf("IsE:%d\n",IsEmpty(SCQ));break;
			case 'I':printf("IsF:%d\n",IsFull(SCQ));break;
			case 'd':
			case 'D':y=DeQueue(SCQ,x);
						printf("Elem:%d\n",y==1?x:-1);
						Print(SCQ);break;
			case 'q':Destory(SCQ);
						printf("Destory sucessed.\n");return 0;
			default:break;
		}
	}
	return 0;
}

