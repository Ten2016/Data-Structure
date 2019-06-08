#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Def.cpp"

int main(){
	DLinkList DL;
	Init(DL);
	Create_Tail(DL,6,50);
	Print(DL);
	Create_Head(DL,4,80);
	Print(DL);	
	char c;
	int elem,e,index;
	printf("输入操作指令[#退出]:\n");
	while(1){
		scanf("%c",&c);
		switch(c){
			case '#':return 0;
			case 'i':
			case 'I':scanf("%d%d",&index,&elem);Insert_Index(DL,index,elem);
						Print(DL);break;
			case 'f':scanf("%d",&elem);Find_Elem(DL,elem,index);
						printf("index:%d\n",index);break;
			case 'F':scanf("%d",&index);Find_Index(DL,index,elem);
						printf("elem:%d\n",elem);break;
			case 'm':scanf("%d",&elem);Find_Prior(DL,elem,e);
						printf("elem:%d\tprior:%d\n",elem,e);break;
			case 'n':scanf("%d",&elem);Find_Next(DL,elem,e);
						printf("elem:%d\tnext:%d\n",elem,e);break;
			case 'd':scanf("%d",&elem);Delete_Index(DL,elem);Print(DL);break;
			case 'D':scanf("%d",&index);Delete_Index(DL,index);Print(DL);break;
			case 'q':Destory(DL);printf("Destory sucessed.\n");return 0;
			default:break;
		}
	}
	return 0;
}
		
	

