#include <stdio.h>
#include <string.h>

#include "Def.h"
#include "Sort.h"

int main(int argc,char **argv){
	if(argc==1)
		return 0;

	int n;
	Arr A;
	Create(A,argc,argv);
	Print(A);

	if(strstr("Straight",argv[1])
		Straight_Insertion_Sort(A);
	else if(strstr("Half",argv[1])
		Half_Insertion_sort(A);
	else if(strstr("Shell",argv[1])
		Shell_Sort(A);
	else
		;

	Print(A);

	return 0;
}

	
	
