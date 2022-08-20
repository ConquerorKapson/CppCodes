#include<iostream>
#include<vector>
using namespace std;



int minCostClimbingStairs(vector<int>& cost){
    int n = cost.size();
    vector<int>dp(n, -1);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2 ; i < n ; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    for(int i = 0 ; i < n ; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    int ans = min(dp[n-1], dp[n -2]);
    return ans;
}


int main(){
    vector<int>costs{1, 20, 15, 14, 2, 9, 63, 22};
    int minCost = minCostClimbingStairs(costs);
    cout<<"Min cost to reach is : "<<minCost<<endl;
    return 0;
}