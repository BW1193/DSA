#include<bits/stdc++.h>
using namespace std;

void subsequence(int index, vector<int> &ds,int arr[], int n){
    if(index == n){
        for(auto it:ds){
            cout << it << " ";
        }
        cout << endl;
        return;
    }

    // take or pick the particular index for the subsequence
    ds.push_back(arr[index]);
    subsequence(index+1,ds,arr,n);
    ds.pop_back();

    // not pick condition, which means, this element is not added to subsequence
    subsequence(index+1,ds,arr,n);
}

int main(){
    int arr[]={3,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> ds;
    subsequence(0,ds,arr,n);
    return 0;
}
