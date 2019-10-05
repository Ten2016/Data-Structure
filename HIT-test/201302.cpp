/*
    给定一个二叉树
    该二叉树有森林转化而来
    求该森林的叶子结点数 LeavesCounter(...)

*/

#include "Init_tree.cpp"

//idea 1
int LeavesCounter(pBTree BT){
    int tmp=0;
    if(BT){
        if(BT->lchild==NULL)
            tmp=1;
        tmp += (LeavesCounter(BT->lchild)+LeavesCounter(BT->rchild));
        //root + lchild + rchild
    }
    return tmp;
}

//idea2
static int cnt=0;
void LeavesCounter1(pBTree BT){
    if(BT){
        if(BT->lchild==NULL) 
            cnt++;
        LeavesCounter1(BT->lchild);
        LeavesCounter1(BT->rchild);
    }
}


int main(){
    //init
    pBTree BT1=NULL,BT2=NULL,BT3=NULL;
    Init_BTree(BT1);
    Print(BT1);
    //test
    cout<<"LeavesCounter:\t"<<LeavesCounter(BT1)<<endl;
    LeavesCounter1(BT1);
    cout<<"LeavesCounter1:\t"<<cnt<<endl<<endl;

    //init
    int Arr[11]={9,15,5,3,7,12,8,17,10,2,4};
    Create_SortBTree(BT2,Arr,11);
    Print(BT2);
    cnt=0;
    //test
    cout<<"LeavesCounter:\t"<<LeavesCounter(BT2)<<endl;
    LeavesCounter1(BT2);
    cout<<"LeavesCounter1:\t"<<cnt<<endl<<endl;

    //init
    int Arr2[8]={9,15,5,7,12,8,17,10};
    Create_SortBTree(BT3,Arr2,8);
    Print(BT3);
    cnt=0;
    //test
    cout<<"LeavesCounter:\t"<<LeavesCounter(BT3)<<endl;
    LeavesCounter1(BT3);
    cout<<"LeavesCounter1:\t"<<cnt<<endl<<endl;

    return 0;
}

/*BT1
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


/*BT2
  1                 9
                  /    \
                /        \      
  2           5           15
            /   \        /  \
  3        3     7      12   17
          / \     \    /
  4      2   4     8  10

*/

/*BT3
  1                 9
                  /    \
                /        \      
  2           5           15
                \        /  \
  3              7      12   17
                  \    /
  4                8  10

*/
