#define MOD 1000000007
#include<bits/stdc++.h>
using namespace std;

long long int countDerangementsMem(int n, vector<long long int>& dp){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] =  (((n-1)%MOD) * (((countDerangementsMem(n-1, dp))%MOD) + ((countDerangementsMem(n-2, dp))%MOD)))%MOD;
    return dp[n];
}

long long int countDerangementsTab(int n){
    vector<long long int>dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i < dp.size() ; i++){
        dp[i] = ((i-1)%MOD) * (((dp[i-1]%MOD) + (dp[i-2]%MOD)))%MOD;
    }

    return dp[n];
}

int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    vector<long long int>dp(n+1, -1);
    long long int ans = countDerangementsMem(n, dp);
    long long int ans2 = countDerangementsTab(n);

    cout<<"No of Derangements using memoization : "<<ans<<endl;
    cout<<"No of Derangements using tabulation  : "<<ans2<<endl;
    
    return 0;
}