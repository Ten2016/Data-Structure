/*
    1.判断二叉树是否为完全二叉树
    2.输出从右到左第K个结点

*/

#include "Init_tree.cpp"

//use level order
int Is_FullBinTree(pBTree BT){
    pBTree Queue[20],p;
    int front,rear;
    front=rear=0;
    if(BT){
        Queue[front]=BT;
        front=(front+1)%20;
    }
    while(front!=rear){
        p=Queue[rear];
        rear=(rear+1)%20;
        if(p==NULL)
            break;
        Queue[front]=p->lchild;
        front=(front+1)%20;
        Queue[front]=p->rchild;
        front=(front+1)%20;
    }
    while(rear!=front){
        p=Queue[rear];
        rear=(rear+1)%20;
        if(p)
            return 0;
    }
    return 1;
}

int main(){
    //init
    pBTree BT;
    Init_BTree(BT);
    Print(BT);
    //test
    cout<<"Is:\t"<<Is_FullBinTree(BT)<<endl<<endl;

    //init
    pBTree FBT=NULL;
    int Arr[12]={9,15,5,3,7,12,8,17,10,6,2,4};
    Create_SortBTree(FBT,Arr,12);
    Print(FBT);
    //test
    cout<<"Is:\t"<<Is_FullBinTree(FBT)<<endl;

    return 0;
}

/*BT
  1                 8
                  /   \
                /       \      
  2            4         15
             /   \     /    \
  3         3     7   12     17
                /    /
  4            6     9
                       \
  5                     10

*/


/*FBT
  1                 9
                  /    \
                /        \      
  2           5           15
            /   \        /  \
  3        3     7      12   17
          / \   / \    /
  4      2   4 6   8  10

*/