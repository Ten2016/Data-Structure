/*
    给定一颗二叉树
    1.查找值为X的结点,返回结点,Search(...)
    2.返回X所在的层数,Level(...)

*/

#include "Init.cpp"

pBTree Search(pBTree BT,int k){
    pBTree tmp=NULL;
    if(BT){
        if(BT->elem==k)
            tmp=BT;
        if(tmp==NULL)     //left
            tmp=Search(BT->lchild,k);
        if(tmp==NULL)     //left no
            tmp=Search(BT->rchild,k);
    }
    return tmp;
} 

int Level_core(pBTree BT,int num,int k){
    int tmp=-1;
    if(BT){
        if(BT->elem==num)
            tmp=k;
        if(tmp==-1)
            tmp=Level_core(BT->lchild,num,k+1);
        if(tmp==-1)
            tmp=Level_core(BT->rchild,num,k+1);
    }
    return tmp;
}
int Level(pBTree BT,int num){
    return Level_core(BT,num,1);//root level is 1
}


int main(){
    //init
    pBTree BT,p;
    Init_BTree(BT);
    Print(BT);

    //test
    p=Search(BT,4);
    cout<<p->elem<<"  "<<Level(BT,4)<<endl;
    p=Search(BT,8);
    cout<<p->elem<<"  "<<Level(BT,8)<<endl;
    p=Search(BT,12);
    cout<<p->elem<<"  "<<Level(BT,12)<<endl;
    p=Search(BT,10);
    cout<<p->elem<<"  "<<Level(BT,10)<<endl;



    return 0;
}

