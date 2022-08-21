#include<iostream>
#include<vector>

using namespace std;

int calculateMinCost(vector<int>days, vector<int>costs, int index, int lastIndex, vector<int>& dp){
    if(index > lastIndex){
        return 0;
    }
    
    if(dp[index] != -1){
        return dp[index];
    }
    
    int oneDayPassIndex = index+1;
    int oneDayPass = costs[0] + calculateMinCost(days, costs, oneDayPassIndex, lastIndex, dp);
    
    int sdi;
    for(int i = index ; i < days.size() ; i++){
        if(days[i]>=days[index]+7){
            sdi = i;
            break;
        }
    }
    int sevenDayPass = costs[1] + calculateMinCost(days, costs, sdi, lastIndex, dp);
    
    int tdi;
    for(int i = index ; i < days.size() ; i++){
        if(days[i]>=days[index]+30){
            tdi = i;
            break;
        }
    }
    int thirtyDayPass = costs[2] + calculateMinCost(days, costs, tdi, lastIndex, dp);
    dp[index] = min(min(oneDayPass, sevenDayPass), thirtyDayPass);
    return min(oneDayPass, min(sevenDayPass, thirtyDayPass));
}

int calculateMinCost(vector<int>& days, vector<int>& costs){
    int index = 0;
    int lastIndex = days.size()-1;
    vector<int>dp(days.size(), -1);
    return calculateMinCost(days, costs, index, lastIndex, dp);
}

int main(){
    vector<int> days{1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs{2,7,15};

    int minCost = calculateMinCost(days, costs);
    cout<<"Min cost for your travel will be : "<<minCost;
    return 0;
}