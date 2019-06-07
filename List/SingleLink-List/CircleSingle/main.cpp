#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Def.cpp"

int main() {

    SCLinkList SCL;
    Init(SCL);
    Create_Head(SCL,10);
    Create_Tail(SCL,10);
    printf("Print:\n");
    Print(SCL,24);
	printf("输入操作指令[#退出]:\n");
    int num,index;
    char c;
	while(1) {
		scanf("%c",&c);
		switch(c) {
			case 'i':
			case 'I':
				scanf("%d",&num);Insert_Index(SCL,index,num);
				Print(SCL,50);break;
			case 'f':
				scanf("%d",&num);Find_Elem(SCL,num);
				Print(SCL,50);break;
			case 'F':
				scanf("%d",&index);Find_Index(SCL,index);
				Print(SCL,50);break;
			case 'd':
				scanf("%d",&num);Delete_Elem(SCL,num);
				Print(SCL,50);break;
			case 'D':
				scanf("%d",&index);Delete_Index(SCL,index);
				Print(SCL,50);break;
			case 'p':
				Print_Head(SCL);break;
			case 'P':
				Print_Tail(SCL);break;
			case 'q':
				Destory(SCL);printf("Destory sucessed.\n");
				return 0;
			default:
				break;
		}
	}
	return 0;
}


