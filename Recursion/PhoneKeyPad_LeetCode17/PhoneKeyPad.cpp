#include<iostream>
#include<vector>
using namespace std;

void phoneKeypadHelper(string digits, vector<string>& result, string output, vector<string> map, int index, int lastIndex){
    if(index > lastIndex){
        result.push_back(output);
        return;
    }

    int digit = digits[index] -'0';
    string str = map[digit];
    for(char ch : str){
        output.push_back(ch);
        phoneKeypadHelper(digits, result, output, map, index+1, lastIndex);
        output.pop_back();
    }
}

void phoneKeypad(string digits, vector<string>& result){
    if(digits == "" || digits == " "){
        return;
    }
    int index = 0;
    int lastIndex = digits.length()-1;
    string output = "";

    vector<string>map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    phoneKeypadHelper(digits, result, output, map, index, lastIndex);
    return;
}

int main(){
    string digits;
    cout<<"Enter your digit : ";
    cin>>digits;
    vector<string>result;
    
    phoneKeypad(digits, result);
    
    for(string str: result){
        cout<<"["<<str<<"]"<<endl;
    }
}