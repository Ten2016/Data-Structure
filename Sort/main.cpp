#include <stdio.h>
#include <string.h>

#include "Def.h"
#include "Sort.h"

int main(int argc,char **argv){
	if(argc==1)
		return 0;

	int n;
	Arr A,B;
	Create(A,argc,argv);
	Copy(A,B);
	printf("原始数据:\n");
	Print(A);
	if(strstr("Straight",argv[1])){			//1
		printf("\nStraight-Insertion:  \n");		
		Straight_Insertion_Sort(A);
	}
	else if(strstr("Half",argv[1])){		//2
		printf("\nHalf-Insertion:  \n");
		Half_Insertion_Sort(A);
	}
	else if(strstr("Shell",argv[1])){		//3
		printf("\nShell:  \n");
		Shell_Sort(A);
	}
	else if(strstr("Bubble",argv[1])){		//4
		printf("\nBubble:  \n");
		Bubble_Sort(A);
	}
	else if(strstr("Quick",argv[1])){		//5
		printf("\nQuick:  \n");
		Quick_Sort(A);
	}
	else if(strstr("Select",argv[1])){		//6
		printf("\nSelect:  \n");
		Select_Sort(A);
	}
	else{
		printf("no %s\n",argv[1]);
		return 0;
	}

	Print(A);
	Bubble_Sort(B);
	printf("\nBubble:\n");
	Print(B);
	if(Compare(A,B))
		printf("sucessed.\n");
	else
		printf("defeat.\n");
	Destory(A);
	Destory(B);

	return 0;
}

	
	
