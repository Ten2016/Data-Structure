#include <stdio.h>
#include <string.h>

#include "Def.h"
#include "Sort.h"

int main(int argc,char **argv){
	if(argc==1)
		return 0;

	int n;
	Arr A,B;
	Create(A,B,argc,argv);
	printf("原始数据:\n");
	Print(A);
	if(strstr("Straight",argv[1]))
		Straight_Insertion_Sort(A);
	else if(strstr("Half",argv[1]))
		Half_Insertion_Sort(A);
	else if(strstr("Shell",argv[1]))
		Shell_Sort(A);
	else if(strstr("Bubble",argv[1]))
		Bubble_Sort(A);
	else{
		printf("no %s\n",argv[1]);
		return 0;
	}
	
	printf("结果:\n");
	Print(A);
	Bubble_Sort(B);
	printf("Bubble:\n");
	Print(B);
	if(Compare(A,B))
		printf("sucessed.\n");
	else
		printf("defeat.\n");
	Destory(A);
	Destory(B);

	return 0;
}

	
	
