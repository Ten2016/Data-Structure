#include <iostream>
#include "Def.cpp"

using namespace std;

int main(){
    BinTree BT;
    int A[]={7,1,2,-3,5,-6,4,5};
    InitBinTree(BT);
    CreateBinTree(BT,A);
    PreOrder(BT);
    cout<<endl;
    InOrder(BT);
    cout<<endl;
    PostOrder(BT);
    cout<<endl; 




    DestoryBinTree(BT);
    return 0;
}

/*
       1
      /
     2
      \
       -3
       /
      5
       \
        -7
        /
       4
5
 */
