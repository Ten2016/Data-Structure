#include <iostream>
using namespace std;

#define SIZE 10
#define PRIM 97

//采用将字母扩展为32进制形式
//eg: "abcde"='a'*32^4+'b'*32^3+'c'*32^2+'d'*32+'e'
//然后再取模
int Hash(char *s){
    unsigned long long h=0;
    char *p=s;
    while(*p!='\0'){
        h = (h<<5)+ *p;
        p++;
    }
    return h%PRIM;
}

int main(){
    char arr[SIZE+1][10] = {" ","apple","banana","catch","clock",
            "zip","follow","study","teng","jia","lu"};
    int arri[PRIM]={0};
    int i,v;
    for(i=1;i<=SIZE;i++){
        cout<<arr[i]<<' ';  
    }
    cout<<endl;
    for(int i=1;i<=SIZE;i++){
        v=Hash(arr[i]);
        arri[v]=i;
        cout<<arr[i]<<"  "<<v<<endl;
    }
    char x[SIZE];
    while(1){
        cin>>x;
        if(x[0]=='1')
            break;
        v=Hash(x);
        if(arri[v])
            cout<<x<<"  "<<v<<"  Yes"<<endl;
        else
            cout<<x<<"  "<<v<<"  No"<<endl;
    }
    return 0;
}
