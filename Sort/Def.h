#ifndef _DEF_H_
#define _DEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct{
  int *elem;
  int len;
}Arr;

void Create(Arr &A,int argc,char **argv);
void Copy(Arr A,Arr &B);
void Print(Arr A);
int Compare(Arr A,Arr B);
void Destory(Arr &A);

#endif

