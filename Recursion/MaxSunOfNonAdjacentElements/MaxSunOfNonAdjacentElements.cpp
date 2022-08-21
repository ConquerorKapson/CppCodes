#include<iostream>
#include<vector>
using namespace std;

int calculateMaxSumNonAdjacent(vector<int>&elements, int index, int lastIndex, vector<int>&dp){
    if(index > lastIndex){
        return 0;
    }

    if(dp[index]!= -1){
        return dp[index];
    }

    //exclude
    int excludedSum = calculateMaxSumNonAdjacent(elements, index+1, lastIndex, dp);
    //include
    int includedSum =  elements[index] + calculateMaxSumNonAdjacent(elements, index+2, lastIndex, dp);

    cout<<"Exc : "<<excludedSum<<" ";
    cout<<"Inc : "<<includedSum<<" ";
    cout<<endl;
    dp[index] = max(excludedSum, includedSum);
    return max(excludedSum, includedSum);
}

int main(){
    vector<int>elements{9, 9, 8, 2};
    vector<int>dp(elements.size(), -1);

    int index = 0;
    int lastIndex = elements.size()-1;
    int ans =  calculateMaxSumNonAdjacent(elements, index, lastIndex, dp);
    cout<<"Max sum is : "<<ans<<endl;

    return 0;
}