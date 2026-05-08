#include<bits/stdc++.h>
using namespace std;


bool subsequence(int *arr,vector<int> &v,int reqSum, int currentSum, int index,int length){
// cout<<to_string(index)+" "+to_string(currentSum)<<endl;
if(index == length){
if(reqSum == currentSum){
    for(auto it:v)
    cout<<it<<" ";
    cout<<endl;

    return true;
}
return false;
}
else if(currentSum > reqSum){
    return false;
}
else{
    v.push_back(arr[index]);
    currentSum+=arr[index];
    bool result=subsequence(arr,v,reqSum,currentSum,index+1,length);
    if(result == true){ // that means we have got our first subsequence and we dont need to go further
        return true;
    }

    v.pop_back();
    currentSum-=arr[index];
    result=subsequence(arr,v,reqSum,currentSum,index+1,length);
    if(result == true){ // that means we have got our first subsequence and we dont need to go further
        return true;
    }
    return false;
}
}

void start(int *arr,int reqsum,int length){
    vector<int> v;
    bool found = subsequence(arr,v,reqsum,0,0,length);
    if(!found){
        cout<<"No subsequence found"<<endl;
    }
}

int main(){
    int arr[] = {1,3,1};
    int reqSum = 2;
    int length = sizeof(arr)/sizeof(arr[0]);
    start(arr,reqSum,length);
    return 1;
}
