#include <iostream>
#include "Def.cpp"

using namespace std;

int main(){
    BinTree BT;
    char A[]="ABCDFGI--E--H";
    InitBinTree(BT);
    CreateBinTree(BT,A);
    PreOrder(BT);
    cout<<endl;
    InOrder(BT);
    cout<<endl;
    PostOrder(BT);
    cout<<endl; 
    LevelOrder(BT);
    cout<<endl;



    DestoryBinTree(BT);
    return 0;
}

/*
         A
       /   \
      B     C
     /  \  /  \
    D   F  G   I
       /    \
      E      H
 */
