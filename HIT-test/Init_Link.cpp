#include <iostream>
using namespace std;

typedef struct SingleLink{
    int elem;
    struct SingleLink *next;
}LinkNode, *pLink;


void Create_Link(pLink &L,int *arr,int n){
    L= new LinkNode;
    L->next=NULL;
    pLink s,p=L;
    for(int i=0;i<n;i++){
        //create linknode s;
        s=new LinkNode;
        s->elem=arr[i];
        s->next=NULL;
        //insert to rear
        p->next=s;
        p=s;
    }
}

void Print(pLink L){
    pLink p=L->next;
    while(p){
        cout<<p->elem<<"  ";
        p=p->next;
    }
    cout<<endl<<endl;
}