#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Def.h"

int main(int argc,char **argv){
	int dmount;	//创建时默认数据个数
	char mode[10];	//创建方式
	if(argc==1){
		strcpy(mode,"head");
		dmount=10;
	}
	else if(argc==2){
		strcpy(mode,argv[1]);
		dmount=10;
	}
	else{
		strcpy(mode,argv[1]);
		dmount=atoi(argv[2]);
	}

	SLinkList SL;
	Init(SL);
	Create_Head(SL,dmount);
	Print(SL);
	if(strcmp("tail",mode)==0){
		Destory(SL);
		Create_Tail(SL,dmount);
	}
	printf("单链表初始状态：\n");
	Print(SL);
	char c;int num;
	printf("输入操作指令[#退出]:\n");
	while(1){
		scanf("%c",&c);
		switch(c){
			case '#':return 0;
			case 'i':
			case 'I':scanf("%d",&num);Insert_Index(SL,num);Print(SL);break;
			case 'f':scanf("%d",&num);Find_Elem(SL,num);Print(SL);break;
			case 'F':scanf("%d",&num);Find_Index(SL,num);Print(SL);break;
			case 'd':
			case 'D':Destory(SL);printf("Destory sucessed.\n");break;
			default:break;
		}
	}
	return 0;
}
		
	
