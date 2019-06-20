#include "Def.h"

void InitBinTree(BinTree &BT){
    BT = NULL;
}
void CreateBinTree(BinTree &BT,ElemType *A){
    BinTree t;
    BinTNode *p;
    int i;
    if(IsEmpty(BT)){
        p = new BinTNode;
        p->elem=A[1];
        p->leftchild=NULL;
        p->rightchild=NULL;
        BT=t=p;
        i=2;
    }
    else
        i=1;
    for(;i<=A[0];i++){
        p = new BinTNode;
        p->elem=A[i];
        p->leftchild=NULL;
        p->rightchild=NULL;
        if(A[i]>0){
            t->leftchild=p;
            t->rightchild=NULL;
            t=t->leftchild;
        }
        else{
            t->leftchild=NULL;
            t->rightchild=p;
            t=t->rightchild;
        }
    }
}
void ClearBinTree(BinTree &BT){
    ;
}
void DestoryBinTree(BinTree &BT){
    ;
}
int  IsEmpty(BinTree BT){
    if(BT==NULL)
        return 1;
    else
        return 0;
}
int  Depth(BinTree BT){}             //返回深度
BinTree Root(BinTree BT){}           //返回树根
ElemType  Value(BinTree BT, BinTNode *e){}   //返回结点e的值
//void Assign(BinTree BT,BinTNode &*e, ElemType v){}   //修改结点e的值

void PreOrder(BinTree BT){
    if(BT!=NULL){
        printf("%d\t",BT->elem);
        PreOrder(BT->leftchild);
        PreOrder(BT->rightchild);
    }
}  //先序遍历
void InOrder(BinTree BT){
    if(BT!=NULL){
        PreOrder(BT->leftchild);
        printf("%d\t",BT->elem);
        PreOrder(BT->rightchild);
    }
}   //中序遍历
void PostOrder(BinTree BT){
    if(BT!=NULL){
        PreOrder(BT->leftchild);
        PreOrder(BT->rightchild);
        printf("%d\t",BT->elem);
    }
} //后序遍历