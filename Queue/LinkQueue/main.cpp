#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Def.cpp"

int main(){
	LinkQueue LQ;
	Init(LQ);
	printf("输入操作指令[#退出]:\n");
	char c;int x,y;
	while(1){
		scanf("%c",&c);
		switch(c){
			case 'e':
			case 'E':scanf("%d",&x);EnQueue(LQ,x);
						Print(LQ);break;
			case 'i':
			case 'I':printf("IsE:%d\n",IsEmpty(LQ));break;
			case 'd':
			case 'D':y=DeQueue(LQ,x);
						printf("Elem:%d\n",y==1?x:-1);
						Print(LQ);break;
			case 'q':Destory(LQ);
						printf("Destory sucessed.\n");return 0;
			default:break;
		}
	}
	return 0;
}

