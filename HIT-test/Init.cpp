#include <iostream>
using namespace std;


typedef struct BinTree{
    int elem;
    struct BinTree *lchild, *rchild;
}BTreeNode, *pBTree;

int Insert_SortBTree(pBTree &BTree, int k){
    if(BTree==NULL){ //create
        BTree = new BTreeNode;
        BTree->elem=k;
        BTree->lchild=NULL;
        BTree->rchild=NULL;
        return 1;
    }
    else if(BTree->elem==k)
        return 0;
    else if(k<BTree->elem)
        return Insert_SortBTree(BTree->lchild,k);
    else
        return Insert_SortBTree(BTree->rchild,k);
}

void Create_SortBTree(pBTree &BTree,int *arr,int n){
    for(int i=0;i<n;i++) 
        Insert_SortBTree(BTree,arr[i]);
}

void Order1(pBTree BTree){
    if(BTree){
        cout<<BTree->elem<<"  ";
        Order1(BTree->lchild);
        Order1(BTree->rchild);
    }
}

void Order2(pBTree BTree){
    if(BTree){
        Order2(BTree->lchild);
        cout<<BTree->elem<<"  ";
        Order2(BTree->rchild);
    }
}

void Order3(pBTree BTree){
    if(BTree){
        Order3(BTree->lchild);
        Order3(BTree->rchild);
        cout<<BTree->elem<<"  ";
    }
}

void Order4(pBTree BTree){
    pBTree Queue[20],p;
    int front,rear;
    front=rear=0;
    if(BTree){
        Queue[front]=BTree;
        front=(front+1)%20;
    }
    else{
        /* code */
        return ;
    }
    while(front!=rear){
        p=Queue[rear];          //dequeue
        rear=(rear+1)%20;
        cout<<p->elem<<"  ";    //visit
        if(p->lchild){
            Queue[front]=p->lchild; //enqueue lchild
            front=(front+1)%20;
        }
        if(p->rchild){
            Queue[front]=p->rchild; //enqueue rchild
            front=(front+1)%20;
        }
    }
}


void Print(pBTree BTree){
    cout<<"Print1:"<<endl;
    Order1(BTree);
    cout<<endl;
    cout<<"Print2:"<<endl;
    Order2(BTree);
    cout<<endl;
    cout<<"Print3:"<<endl;
    Order3(BTree);
    cout<<endl;
    cout<<"Print4:"<<endl;
    Order4(BTree);
    cout<<endl<<endl;
}

void Init_BTree(pBTree &BTree){
    int Arr[10]={8,15,4,3,7,12,17,9,6,10};
    BTree=NULL;
    Create_SortBTree(BTree,Arr,10);
}
/*
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

