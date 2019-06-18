#include <iostream>
using namespace std;

#define SIZE 10

int main(){
    int arr[SIZE] = {1,1,2,3,4,4,5,6,6,7};
    int i;
    for(i=0;i<SIZE;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    int x,low,high,mid;
    while(1){
        cin>>x;
        if(x<0)
            break;
        low=0;high=SIZE-1;
        while(low<=high){   //mush be <=
            mid=(low+high)/2;
            if(arr[mid]==x){
                cout<<x<<"  "<<mid<<"  Yes"<<endl;
                break;
            }
            else if(arr[mid]>x) high=mid-1;
            else    low=mid+1;
        }
        for(i=0;i<SIZE;i++){
            if(arr[i]==x){
            }
        }
        if(low>high)
            cout<<x<<"  No"<<endl;
    }
    return 0;
}
