#ifndef _SORT_H_
#define _SORT_H_

#include "Def.h"



/* PS:
 Arr 为数据结构体
 typedef struct{
		int *elem;	//存储方式为elem[1:len];
		int len;
 }
*/

/******插入排序******\
1.直接插入排序
2.折半插入排序
3.希尔排序

\*******************/
//直接插入排序
void Straight_Insertion_Sort(Arr &A);
//折半插入排序
void Half_Insertion_Sort(Arr &A);
//希尔排序
void Shell_Sort(Arr &A);


/******交换排序******\
1.冒泡排序
2.快速排序

\*******************/
//冒泡排序
void Bubble_Sort(Arr &A);
//快速排序
int Partition(Arr &A,int low,int high);
void Quick(Arr &A,int low,int high);
void Quick_Sort(Arr &A);



/******选择排序******\
1.冒泡排序
2.快速排序

\*******************/
//简单选择排序
void Select_Sort(Arr &A);
//堆排序







#endif


