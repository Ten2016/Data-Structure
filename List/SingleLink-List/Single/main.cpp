#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Def.cpp"

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
	printf("输入操作指令[#退出]:\n");
	char c;int index,num,res;
	while(1){
		scanf("%c",&c);
		switch(c){
			case 'i':
			case 'I':scanf("%d%d",&index,&num);
						Insert_Index(SL,index,num);
						Print(SL);break;
			case 'l':printf("Len:%d\n",Length(SL));break;
			case 'f':scanf("%d",&num);
						res=Find_Elem(SL,num);
						printf("%d\n",res);break;
			case 'F':scanf("%d",&index);
						res=Find_Index(SL,index);
						printf("%d\n",res);break;
			case 'd':scanf("%d",&num);
						res=Delete_Elem(SL,num);
						printf("%d\n",res);
						Print(SL);break;
			case 'D':scanf("%d",&index);
						res=Delete_Index(SL,index);
						printf("%d\n",res);
						Print(SL);break;
			case 'q':Destory(SL);
						printf("Destory sucessed.\n");return 0;
			default:break;
		}
	}
	return 0;
}
		
	
