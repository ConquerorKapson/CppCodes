#include<iostream>
using namespace std;

long long calculatePower(long long a, long long b){
    if(b == 0){
        return 1;
    }
    
    long long ans = calculatePower(a, b/2);

    if(b%2 == 0){
        return ans*ans;
    }else{
        return a*ans*ans;
    }
}

int main(){
    long long a, b;
    cout<<"Enter your number: ";
    cin>>a;
    cout<<"Enter the power: ";
    cin>>b;
    cout<<"Result is : "<<calculatePower(a, b)<<endl;
    return 0;
}