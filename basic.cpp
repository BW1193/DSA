#include<bits/stdc++.h>
using namespace std;

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
    return 1;
}