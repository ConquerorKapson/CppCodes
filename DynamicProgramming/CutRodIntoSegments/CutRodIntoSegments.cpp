#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
#include<limits.h>
int helper(int n, int x, int y, int z){
    if(n < 0){
        return INT_MIN;
    }
    
    if(n == 0){
        return 0;
    }
    
    int a = 1+helper(n-x, x, y, z);
    int b = 1+helper(n-y, x, y, z);
    int c = 1+helper(n-z, x, y, z);
    
    return max(max(a, b), c);
}

int cutSegmentsMem(int n, int x, int y, int z, vector<int>& dp){
    if(n < 0){
        return INT_MIN;
    }
    
    if(n == 0){
        return 0;
    }
    
    if(dp[n] != -1){
        return dp[n];
    }
    
    int a = 1+cutSegmentsMem(n-x, x, y, z, dp);
    int b = 1+cutSegmentsMem(n-y, x, y, z, dp);
    int c = 1+cutSegmentsMem(n-z, x, y, z, dp);
    
    dp[n] = max(max(a,b), c);
    return dp[n];
}

int cutSegmentsDp(int n, int x, int y, int z){
    vector<int>dp(n+1, INT_MIN);
    dp[0] = 0;
    for(int i = 1 ; i < dp.size() ; i++){
        if(i-x >= 0){
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
        
        if(i-y >= 0){
            dp[i] = max(dp[i], dp[i-y] + 1);
        }
        
        if(i-z >= 0){
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }
    
    if(dp[n] < 0){
        return 0;
    }
    return dp[n];    
}
int cutSegments(int n, int x, int y, int z) {
// 	int ans = helper(n, x, y, x);
//     if(ans < 0){
//         return 0;
//     }else{
//         return ans;
//     }
    
    
//     vector<int>dp(n+1, -1);
//     int ans = cutSegmentsMem(n, x, y, z, dp);
//     if(ans < 0){
//         return 0;
//     }else{
//         return ans;
//     }
    return cutSegmentsDp(n, x, y, z);
}

int main(){
    int n, x, y, z;
    vector<int>dp(n+1, -1);
    cin>> n >> x >> y >> z;
    
    int ans1 = cutSegmentsMem(n, x, y, z, dp); 
    if(ans1 < 0){
        cout<<0;
    }else{
        cout<<ans1;
    }

    return 0;
}