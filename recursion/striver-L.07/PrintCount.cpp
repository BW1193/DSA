#include<bits/stdc++.h>
using namespace std;

int subsequence(int* arr,int length,int index,int requiredSum,int currentSum){
    if(index == length){
        if(requiredSum == currentSum){
        return 1;
        }
        return 0;
    }

    int l_count=subsequence(arr,length,index+1,requiredSum,currentSum+arr[index]);

    int r_count=subsequence(arr,length,index+1,requiredSum,currentSum);

    return l_count+r_count;
}

void start(int* arr,int requiredSum,int length){
int index=0;
int currentSum = 0;
int count = subsequence(arr,length,index,requiredSum,currentSum);
cout<<"Total count : "<<count<<endl;
}

int main(int argc, char *argv[]){
    int arr[]={1,2,1};
    int length = sizeof(arr)/sizeof(arr[0]);
    int requiredSum=2;
    start(arr,requiredSum,length);
    return 0;
}
