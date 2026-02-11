#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {
    bool result=false;
    int subIndex=0;
    for(int i=0;i<t.length();i++){
        if(s[subIndex] == t[i]){
            subIndex+=1;
        }
    }
    if(subIndex==s.length())
    result=true;
    return result;
}

int main(){
    int x;
    string s = "abc";
    string t = "ahbgdc";
    bool res=isSubsequence(s,t);
    cout << res << endl;
}

// note : to run this file, press : ctrl+shift+b