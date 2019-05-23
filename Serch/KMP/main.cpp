#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZES 50	//主串长度 
#define SIZET 4 	//模式串长度 
#define CHARS 2 	//所含不同字母数 


typedef struct{
	char *s;
	int len;
}Str;

int Create_Next(Str T,int *next);
int KMP(Str S,Str T,int *next);
int BF(Str S,Str T);
void PrintS(Str S);
void Print_Next(int *next);

int Create_Next(Str T,int *next){
	int i=1;
	int j=0;
	next[1]=0;
	while(i<=T.len){
		if(j==0||T.s[i]==T.s[j]){
			++i;
			++j;
			next[i]=j; 	//正常处理，生成常规next数组 
//			if(T.s[i]==T.s[j])
//				next[i]=j; 
//			else
//				next[i]=next[j];
//	修正算法  例如出现:S aaabaaaab  T aaab
		}
		else
			j=next[j];
	}
}

int KMP(Str S,Str T,int *next){
	int i=1,j=1;
	while(i<=S.len&&j<=T.len){
		if(j==0||S.s[i]==T.s[j]){
			//j==0说明Si与T的第一位不匹配，这时将i和j均加1
			//相当于进入下一轮，Si的下一位与T第一位开始匹配 
			++i;
			++j;
		}
		else
			j=next[j];	//此处只有next[1]=0，因此只有出现第一个就不匹配时
									//才会有j=0. 
	}
	if(j>T.len)
		return i-T.len;
	else
		return -1;
	
}

int BF(Str S,Str T){
	int i=1,j=1; 
	while(i<=S.len&&j<=T.len){
		if(S.s[i]==T.s[j]){
			i++;
			j++;
		}
		else{
			i=i-j+2;	//在第i个位置失配，则回退j-1个到达匹配的初始点
								//从下一个位置再次开始，因此再加1
			j=1; 
		}
	}
	if(j>T.len)
		return i-T.len;
	else
		return -1;
}

void PrintS(Str S){
	for(int i=1;i<=S.len;i++)
		printf("%c ",S.s[i]);
	printf("\n");
}
void Print_Next(int *next){
	for(int i=1;i<=SIZET;i++)
		printf("%d ",next[i]);
	printf("\n");
}


int main(void){
	Str S;
	Str T;
	S.len=SIZES;
	T.len=SIZET;
	S.s = new char[SIZES+1];
	T.s = new char[SIZET+1];
	int next[SIZET+1];
	srand((unsigned)time(NULL));
	char c;
	while(1){
		
		for(int i=1;i<=S.len;i++)
			S.s[i]=rand()%CHARS+97;
		for(int i=1;i<=T.len;i++)
			T.s[i]=rand()%CHARS+97;
		PrintS(S);
		printf("\n");
		PrintS(T);
		Create_Next(T,next);
		Print_Next(next);
		printf("\nBF: %d",BF(S,T));
		printf("\nKMP:%d\n",KMP(S,T,next));	
		
		scanf("%c",&c);
	}
	return 0;
}

/*
a b a b a a a a
0 1 1 2 3 4 2 2

a b a a a a a b
0 1 1 2 2 2 2 2

b b a b a b a b
0 1 2 1 2 1 2 1

*/



