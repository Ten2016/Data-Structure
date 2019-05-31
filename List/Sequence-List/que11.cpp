
/*----------问题描述----------\
	[顺序有序表]
	给定两个有序表,每个有n个数据
	计算合起来的中位数
	中位数定义为[n/2],向上取整
	数据下标从1开

\---------------------------*/

#include <stdio.h>
#include "Def.cpp"

//常规解法:O(n/2)
//按照合并有序表的思想,找出中间那个数
int Func1(SqList L1,SqList L2){
	int n=L1.length-1;
	int i=0,j=0;
	int res;
	while(i<L1.length && j<L2.length){
		if(L1.elem[i]<=L2.elem[j]){
			res=L1.elem[i];
			if(i+j==n)
				return res;
			i++;
		}
		else{
			res=L2.elem[j];
			if(i+j==n)
				return res;
			j++;
		}
	}
	while(i<L1.length){
		if(i+j==n)
			return res;
		res=L1.elem[i];
		i++;
	}
	while(j<L2.length){
		if(i+j==n)
			return res;
		res=L2.elem[j];
		j++;
	}
}

//优化:O(logN)
//找到两个序列的中位数a,b
//根据a,b的关系折半,继续查找
int Func2(SqList L1,SqList L2){
	int s1,m1,e1;
	int s2,m2,e2;
	s1=s2=0;
	e1=L1.length-1;
	e2=L2.length-1;
	while(s1!=e1 || s2!=e2){	//两个序列均为一个元素时退出
		m1=(s1+e1)/2;	//确定L1的中位数位置
		m2=(s2+e2)/2;	//确定L2的中位数位置
		if(L1.elem[m1]==L2.elem[m2])
			return L1.elem[m1];
		else if(L1.elem[m1]<L2.elem[m2]){
			//舍弃L1的左半部分和L2的右半部分
			//[保证两端舍弃的个数相同]	否则最终位置不是中间点
			if((s1+e1)%2)//偶数
				s1=m1+1;
			else
				s1=m1;
			e2=m2;
		}
		else{
			//舍弃L1的右半部分和L2的左半部分
			//[保证两端舍弃的个数相同]	否则最终位置不是中间点
			if((s1+e1)%2)//偶数
				s2=m2+1;
			else
				s2=m2;
			e1=m1;
		}
	}
	int max=L1.elem[s1]<L2.elem[s2]?L1.elem[s1]:L2.elem[s2];
	return max;
}



int main(){
	SqList L1,L2;
	Init(L1,100);
	Init(L2,100);
	Create(L1,10);
	Create_p(L2,10,47);
	Sort(L1,0,L1.length-1);
	Sort(L2,0,L2.length-1);
	printf("打印L1:\n");
	Print(L1);
	printf("打印L2:\n");
	Print(L2);
	printf("F1:%d\nF2:%d\n",Func1(L1,L2),Func2(L1,L2));
	return 0;
}