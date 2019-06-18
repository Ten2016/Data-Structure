#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

int main(){
    int arr[SIZE];
    int i;
    srand(10);
    for(i=0;i<SIZE;i++){
        arr[i]=rand()%97;
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    int x;
    while(1){
        cin>>x;
        if(x<0)
            break;
        for(i=0;i<SIZE;i++){
            if(arr[i]==x){
                cout<<x<<"  Yes"<<endl;
                break;
            }
        }
        if(i>=SIZE)
            cout<<x<<"  No"<<endl;
    }
    return 0;
}