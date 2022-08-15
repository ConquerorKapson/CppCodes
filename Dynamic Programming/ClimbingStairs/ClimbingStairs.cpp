#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Number of stairs: ";
    cin>>n;

    int*dp = new int[n+1];

    dp[0] = 1;
    dp[1] = 1;

    if(n < 2){
        cout << dp[n];
        return 0;
    }

    for(int i = 2 ; i<=n ; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    cout<< dp[n];
    return 0;
}