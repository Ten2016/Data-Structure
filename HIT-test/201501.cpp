/*
    给定两个单链表,判断是否有交叉
    Judge(...)

*/


#include "Init_Link.cpp"


void Init(pLink &L1,pLink &L2,pLink &tmp){
    int Arr1[6]={3,6,1,5,7,9};
    int Arr2[3]={4,2,5};
    int Common[4]={66,66,66,66};
    Create_Link(L1,Arr1,6);
    Create_Link(L2,Arr2,3);
    Create_Link(tmp,Common,4);
    cout<<"L1:  ";
    Print(L1);
    cout<<"L2:  ";
    Print(L2);
    cout<<"Common:  ";
    Print(tmp);
}
void Union_Link(pLink &L1,pLink &L2,pLink &tmp){
    pLink pL1,pL2;
    pL1=L1,pL2=L2;
    while(pL1 && pL1->next)
        pL1=pL1->next;
    pL1->next=tmp->next;;
    while(pL2 && pL2->next)
        pL2=pL2->next;
    pL2->next=tmp->next;
    delete tmp;
    tmp=NULL;
}


int Judge(pLink L1,pLink L2){
    pLink p1=L1,p2=L2;
    while(p1 && p1->next)
        p1=p1->next;
    while(p2 && p2->next)
        p2=p2->next;
    return p1==p2;
}


int main(){
    //init
    pLink SL1,SL2,Common;
    Init(SL1,SL2,Common);
    //test
    cout<<"is Judge:  "<<Judge(SL1,SL2)<<endl<<endl;

    Union_Link(SL1,SL2,Common);
    cout<<"after common:"<<endl;
    cout<<"L1:  ";
    Print(SL1);
    cout<<"L2  ";
    Print(SL2);
    //test
    cout<<"is Judge:  "<<Judge(SL1,SL2)<<endl;

    return 0;
}
