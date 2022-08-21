#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>elements{9, 9, 8, 2};
    vector<int>dp(elements.size(), -1);

    if(elements.size() == 1){
        return elements.at(0);
    }
    if(elements.size() == 2){
        return max(elements.at(0), elements.at(1));
    }
    dp[0] = elements[0];
    dp[1] = max(elements[0], elements[1]);

    for(int i = 2 ; i < elements.size() ; i++){
        dp[i] = max((elements[i] + elements[i-2]), dp[i-1]);
    }

    cout<<"Max robbery amount : "<<dp[elements.size()-1];
    return 0;
}