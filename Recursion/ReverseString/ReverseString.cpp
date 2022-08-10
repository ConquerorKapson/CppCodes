#include<iostream>
using namespace std;

void reverseStringHelper(string& str, int i, int j){
    if(i >= j){
        return;
    }

    swap(str[i], str[j]);

    reverseStringHelper(str, i+1, j-1);

    return;
}

void reverseString(string& str){
    int length_of_string = str.length();
    int i = 0;
    int j = length_of_string-1;
    if(str.length() == 0){
        return;
    }
    reverseStringHelper(str, i, j);
}

int main(){
    string str = "";
    
    cout<<"Enter String you want to reverse: ";
    cin>>str;
    
    reverseString(str);
    
    cout<<"Your reversed string is : "<<str;
    
    return 0;
}