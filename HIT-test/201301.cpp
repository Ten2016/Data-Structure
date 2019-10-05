/*
    给定已经排好序的数组和一个树X
    查找两个数,使得和为X

*/

#include <iostream>

int FindSum(int *Arr,int n,int x){
    int low=0,high=n-1;
    int sum;
    while(low<high){
        sum=Arr[low]+Arr[high];
        if(sum==x){
            cout<<Arr[low]<<"\t"<<Arr[high]<<endl;
            return 1;
        }
        else if(sum>x)
            --high;
        else
            ++low;
    }
    return 0;
}

int main(){
    //init
    int Arr[8]={1,2,4,7,8,11,12,14};
    
    //test
    cout<<FindSum(Arr,8,11)<<endl;
    cout<<FindSum(Arr,8,6)<<endl;
    cout<<FindSum(Arr,8,22)<<endl;
    cout<<FindSum(Arr,8,10)<<endl;

    return 0;
}