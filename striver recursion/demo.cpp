#include<bits/stdc++.h>
using namespace std;

void printAllSubsequence(int input[],int length) {
    bool dataPrinted=false;
    // this loop tells what should be the length of the subsequence
    for(int i=1;i<=length;i++){
        // this loop tells from which position the subsequence will start
        for(int j=0;j<length;j++){
            // this loop prints the elements from the selected position 
            for(int k=j;k<j+i && (j+i <= length);k++){
                cout<<input[k]<<" ";
                dataPrinted=true;
            }
            if(dataPrinted){
            cout<<endl;
            dataPrinted=false;
            }
        }
    }
}

int main(){
    int input[]={3,1,2,5,6};
    int length = sizeof(input) / sizeof(input[0]);
    printAllSubsequence(input,length);
}

// note : to run this file, press : ctrl+shift+b