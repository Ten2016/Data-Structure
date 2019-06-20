#ifndef _DEF_H_
#define _DEF_H_

#include <stdio.h>

typedef int ElemType;
typedef struct BinTNode{
    ElemType elem;
    struct BinTNode *leftchild;
    struct BinTNode *rightchild;
}BinTNode, *BinTree;


void InitBinTree(BinTree &BT);      //构造空二叉树
void CreateBinTree(BinTree &BT, ElemType *A);   //构造二叉树
void ClearBinTree(BinTree &BT);     //清空
void DestoryBinTree(BinTree &BT);   //销毁
int  IsEmpty(BinTree BT);          //判断是否为空
int  Depth(BinTree BT);             //返回深度
BinTree Root(BinTree BT);           //返回树根
ElemType  Value(BinTree BT, BinTNode *e);   //返回结点e的值
//void Assign(BinTree BT,BinTNode & *e, ElemType v);   //修改结点e的值

void PreOrder(BinTree BT);  //先序遍历
void InOrder(BinTree BT);   //中序遍历
void PostOrder(BinTree BT); //后序遍历




#endif


