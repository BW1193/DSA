/*
 GETTING TIME LIMIT EXCEEDED WITH THIS APPROACH
*/

#include<bits/stdc++.h>
using namespace std;

int arithmaticSubSequencecount=0;

void checkSubsequence(vector<int> &ss){
    if(ss.size()>1){
    int diff=ss[1]-ss[0];
    bool isArithmaticSubSequence=true;
    for(int i=0;i<ss.size()-1;i++){
        if(ss[i+1]-ss[i] != diff){
            isArithmaticSubSequence=false;
        }
    }
    if(isArithmaticSubSequence && ss.size() > arithmaticSubSequencecount)
        arithmaticSubSequencecount=ss.size();
    }
}

void generateSubsequence(int index,int array[],vector<int> &ss,int arrayLength){
    if(index == arrayLength){
        checkSubsequence(ss);
        return;
    }

    ss.push_back(array[index]);
    generateSubsequence(index+1,array,ss,arrayLength);
    ss.pop_back();

    generateSubsequence(index+1,array,ss,arrayLength);
}

int main(){
    int array[]={20,1,15,3,10,5,8};
    int arrayLength=sizeof(array)/sizeof(array[0]);
    vector<int> ss;
    generateSubsequence(0,array,ss,arrayLength);
    cout << arithmaticSubSequencecount << endl;
    return 0;
}





