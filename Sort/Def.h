#ifndef _DEF_H_
#define _DEF_H_


typedef struct{
  int *elem;
  int len;
}Arr;

void Create(Arr &A,int argc,char **argv);
void Print(Arr &A);

#endif

