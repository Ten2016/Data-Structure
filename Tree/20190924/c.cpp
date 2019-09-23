#include <iostream>
using namespace std;

typedef struct Tree{
    int elem;
    struct Tree *lchild, *rchild;
}Tree, *pTree;

void visit(pTree Tree){
    cout<<Tree->elem<<endl;
}

void BianLi1(pTree Tree){
    if(Tree != NULL){
        visit(Tree);
        BianLi1(Tree->lchild);
        BianLi1(Tree->rchild);
    }
}

void BianLi2(pTree Tree){
    if(Tree != NULL){
        BianLi2(Tree->lchild);
        visit(Tree);
        BianLi2(Tree->rchild);
    }
}

void BianLi3(pTree Tree){
    if(Tree != NULL){
        BianLi3(Tree->lchild);
        BianLi3(Tree->rchild);
        visit(Tree);
    }
}

XianSuo(){


}

void PaiXu(pTree &Tree,int *arr,int n){
    
}

int main(){
    pTree T;
    int arr[10]=[3,4,2,5,6,7,8,-2,-4,0];
    PaiXu(T,arr,10);
    BianLi1(T);
    BianLi2(T);
    BianLi3(T);


    return 0;

}
