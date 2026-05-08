/*
Given an array of integers, print the subsequence whose sum is equal to k

Example : 
arr = [1,2,1]
sum required (k) = 2
output ->
1,1
2
*/

#include<bits/stdc++.h>
using namespace std;


void subsequence(int* arr,int length,vector<int> &v,int index,int requiredSum,int currentSum){
    if(index == length){
        if(requiredSum == currentSum){
        for(auto it:v) cout << it << " ";
        cout << endl;
        }
        return;
    }

    v.push_back(arr[index]);
    subsequence(arr,length,v,index+1,requiredSum,currentSum+arr[index]);

    v.pop_back();
    subsequence(arr,length,v,index+1,requiredSum,currentSum);
}

void start(int* arr,int requiredSum,int length){
vector<int> v;
int index=0;
int currentSum = 0;
subsequence(arr,length,v,index,requiredSum,currentSum);
}

void setupInputOutput(char *argv[]){
string filepath = string(argv[0]);
int foundFileNameIndex = filepath.find_last_of("/\\");
string path=filepath.substr(0,foundFileNameIndex);
string fileName=filepath.substr(foundFileNameIndex+1);
int foundOutputFolderIndex = path.find_last_of("/\\");
path=filepath.substr(0,foundOutputFolderIndex);
string inputFilePath = path+"/"+fileName+"_i.txt";
bool inputFileExists = std::filesystem::exists(inputFilePath);
if(inputFileExists)
freopen(inputFilePath.data(),"r",stdin);
string outputFilePath = path+"/"+fileName+"_o.txt";
bool outputFileExists = std::filesystem::exists(outputFilePath);
if(outputFileExists)
freopen(outputFilePath.data(),"w",stdout);
}

int main(int argc, char *argv[]){
    setupInputOutput(argv);
    int arr[]={1,2,1};
    int length = sizeof(arr)/sizeof(arr[0]);
    int requiredSum=2;
    start(arr,requiredSum,length);
    return 0;
}