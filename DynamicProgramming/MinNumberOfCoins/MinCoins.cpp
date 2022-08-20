#include<iostream>
#include<vector>
using namespace std;

int calculate(vector<int> coins, int amount){
    vector<int>dp(amount+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1 ; i <=amount ; i++){
        for(int j = 0 ; j < coins.size() ; j++){
            if((i-coins[j]) >= 0 && dp[i- coins[j]] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }
    }

    int ans = INT_MAX;
    if(dp[amount] == INT_MAX)
        ans = -1;
    else
        ans = dp[amount];
    
    return ans;
}

int main(){
    int n;
    cout<<"Enter your number of coins :  ";
    cin>>n;

    cout<<"Enter your coins denomination : ";
    vector<int> coins;

    for(int i = 0 ; i < n ; i++){
        int coin;
        cin>>coin;

        coins.push_back(coin);
    }

    int amount;
    cout<<"Enter the amount : ";
    cin>>amount;
    cout<<calculate(coins, amount);

    return 0;
}