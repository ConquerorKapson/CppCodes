#include<bits/stdc++.h>
using namespace std;

int solveKnapsackRecursive(vector<int> weight, vector<int> value, int n, int maxWeight, int index){
    if(index > n-1){
        return 0;
    }
    if(weight[index] <= maxWeight && index ==n-1){
        return value[index];
    }
    
    int include = 0;
    if(weight[index] <= maxWeight){
        include = value[index] + solveKnapsackRecursive(weight, value, n, maxWeight-weight[index], index + 1);
    }
    int exclude = solveKnapsackRecursive(weight, value, n, maxWeight, index + 1);
    return max(include, exclude);
}


int solveKnapsackMem(vector<int> weight, vector<int> value, int n, int maxWeight, int index, vector<vector<int>>& dp){
    if(index > n-1){
        return 0;
    }
    if(weight[index] <= maxWeight && index ==n-1){
        return value[index];
    }
        
    if(dp[index][maxWeight] != -1){
        return dp[index][maxWeight];
    }
    
    int include = 0;
    if(weight[index] <= maxWeight){
        include = value[index] + solveKnapsackMem(weight, value, n, maxWeight-weight[index], index + 1, dp);
    }
    int exclude = solveKnapsackMem(weight, value, n, maxWeight, index + 1, dp);
    
    dp[index][maxWeight] = max(include, exclude); 
    return dp[index][maxWeight]; 
}

int main(){
    
    vector<int>weights{3, 4, 32, 33, 23, 21, 11, 25, 39, 37, 17, 19, 40, 11, 32, 31, 1, 25, 34, 20, 15, 42, 48, 15, 35, 42, 34, 38, 26, 4, 37, 47, 11, 29, 35, 22, 31, 31};
    vector<int>values{66, 73, 96, 51, 21, 76, 69, 93, 25, 34, 53, 39, 59, 92, 31, 61, 89, 65, 17, 34, 77, 89, 9, 29, 46, 43, 6, 41, 72, 53, 11, 49, 13, 95, 49, 23, 28, 51};
    int n = weights.size();
    int index = 0;
    int maxWeight = 100;
    
    vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1));
    cout<<"Using Memoization : "<<solveKnapsackMem(weights, values, n, maxWeight, 0, dp)<<endl;
    cout<<"Using recursion : "<<solveKnapsackRecursive(weights, values, n, maxWeight, 0)<<endl;

    return 0;
    
}
//TestCase1
//weights: 3, 9, 3, 8, 8, 7, 9, 5, 10
//values : 5, 1, 6, 10, 1, 6, 3, 7, 5
//maxWeight: 83

//TestCase2
//weights: 3, 4, 32, 33, 23, 21, 11, 25, 39, 37, 17, 19, 40, 11, 32, 31, 1, 25, 34, 20, 15, 42, 48, 15, 35, 42, 34, 38, 26, 4, 37, 47, 11, 29, 35, 22, 31, 31
//values: 66, 73, 96, 51, 21, 76, 69, 93, 25, 34, 53, 39, 59, 92, 31, 61, 89, 65, 17, 34, 77, 89, 9, 29, 46, 43, 6, 41, 72, 53, 11, 49, 13, 95, 49, 23, 28, 51
//maxWeight: 781 or 83
