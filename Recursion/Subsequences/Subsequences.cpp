#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

void makeSubsequences(string str, vector<string>& result, string smollStr, int index, int lastIndex){
    if(index > lastIndex){
        result.push_back(smollStr);
        return;
    }

    //exclude
    makeSubsequences(str, result, smollStr, index+1, lastIndex);

    //include
    smollStr.push_back(str[index]);
    makeSubsequences(str, result, smollStr, index+1, lastIndex);
}

void subsequences(string str, vector<string>& result ){
    int index = 0;
    int lastIndex = str.length()-1;
    string smollStr="";
    makeSubsequences(str, result, smollStr, index, lastIndex);
    return;
}

int main(){
    string str = "ahbgdc";
    vector<string>result;
    subsequences(str, result);

    for(string str: result){
        cout<<"["<<str<<"]"<<endl;
    }
}
