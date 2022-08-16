#include<iostream>
#include<vector>
using namespace std;


void solve(vector<int>& arr, int index, int lastIndex, bool& flag, vector<bool>& isVisited){
    if(index < 0 || index > lastIndex){
        return;
    }

    if(arr[index] == 0){
        flag = true;
        return;
    }
    
    if(index + arr[index] <= lastIndex && !isVisited[index]){
        isVisited[index] = true;
        solve(arr, index+arr[index], lastIndex, flag, isVisited);
        isVisited[index] = false;
    }
    if(index - arr[index] >= 0 && !isVisited[index]){
        isVisited[index] = true;
        solve(arr, index-arr[index], lastIndex, flag, isVisited);
        isVisited[index] = false;
    }
    
}

bool canReach(vector<int>& arr, int start, vector<bool>& isVisited) {
    bool flag = false;
    solve(arr, start, arr.size()-1, flag, isVisited);
    return flag;
}

int main(){
    vector<int>arr{4,2,3,0,3,1,2};
    int start = 5;
    vector<bool> isVisited(arr.size(), false);
    bool ans = canReach(arr, start, isVisited);
    cout<<ans;
}