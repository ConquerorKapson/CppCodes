#include<iostream>
using namespace std;

void sayDigitHelper(int n, string words[]){
    if(n < 0){
        return;
    }
    int to_say = n%10;
    sayDigitHelper(n/10, words); 
    cout<<words[to_say]<<" ";
}

void sayDigit(int n){
    string words[] = {"zero","one","two", "three", "four", "five", "six", "seven", "eight", "nine"};
    sayDigitHelper(n, words);
    return;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    sayDigit(n);

    return 0;
}