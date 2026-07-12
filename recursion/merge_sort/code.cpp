#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low, int mid, int high){
    vector<int> temp;
    int left=low; // first array start from low and goes to mid index
    int right=mid+1; // second array starts from mid+1 and goes to high index
    
    // compare the elements of the left and right arrays (one by one) and 
    // put them in sorted array (i.e. temp variable) until either of the left or right or both
    // array elements are not finished
    while(left <= mid && right <= high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if there are still elements left on the left array put them in the sorted array
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    // if there are still elements left on the right array put them in the sorted array
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    // put the sorted elements from temp vector back into the original array
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }

}

void mS(vector<int> &arr,int low, int high){
    if(low == high)
    return;

    int mid = (low+high)/2;
    mS(arr,low,mid);
    mS(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void mergeSort(vector<int> &arr,int n){
    mS(arr,0,n-1);
}

int main(){
    vector<int> v={6,4,8,2,5,1,0};
    int n=v.size();
    mergeSort(v,n);
    cout<<"Sorted : "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}