#include "Def.h"

void InitBinTree(BinTree &BT){
    BT = NULL;
}
void CreateBinTree(BinTree &BT,ElemType *A){
    BinTNode *p;
    p = new BinTNode;
    p->elem=A[0];
    p->leftchild=NULL;
    p->rightchild=NULL;
    BT=p;     //第一个结点

    BinTNode *queue[20];     //Queue
    int f=0,r=0,flag=1;
    queue[r]=BT;r=(r+1)%20;   //根节点入队列
    for(int i=1;A[i]!='\0';i++){
        if(A[i]=='-'){
            if(flag==-1)
                f=(f+1)%20;           
            flag=-flag;
            continue;
        }
        p = new BinTNode;
        p->elem=A[i];
        p->leftchild=NULL;
        p->rightchild=NULL;
        queue[r]=p;r=(r+1)%20;  //新创的结点入队
        if(flag==1){
            flag=-flag;
            queue[f]->leftchild=p;
        }
        else{
            flag=-flag;
            queue[f]->rightchild=p;
            f=(f+1)%20;
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
        printf("%c\t",BT->elem);
        PreOrder(BT->leftchild);
        PreOrder(BT->rightchild);
    }
}  //先序遍历
void InOrder(BinTree BT){
    if(BT!=NULL){
        PreOrder(BT->leftchild);
        printf("%c\t",BT->elem);
        PreOrder(BT->rightchild);
    }
}   //中序遍历
void PostOrder(BinTree BT){
    if(BT!=NULL){
        PreOrder(BT->leftchild);
        PreOrder(BT->rightchild);
        printf("%c\t",BT->elem);
    }
} //后序遍历
void LevelOrder(BinTree BT){
    BinTNode *p;
    BinTNode *queue[20];     //Queue
    int f=0,r=0;
    queue[r]=BT;r=(r+1)%20;   //根节点入队列
    while(r!=f){    //队列非空
        p=queue[f];
        f=(f+1)%20; //出队
        printf("%c\t",p->elem);
        if(p->leftchild){
            queue[r]=p->leftchild; 
            r=(r+1)%20;
        }
        if(p->rightchild){
            queue[r]=p->rightchild;
            r=(r+1)%20;
        }     
    }
}//层序遍历