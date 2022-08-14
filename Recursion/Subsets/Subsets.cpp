#include<iostream>
#include<vector>

using namespace std;

void subsetHelper(vector<vector<int>>& result, vector<int>& nums, int index, int lastIndex, vector<int>subset){
    if(index > lastIndex){
        result.push_back(subset);
        return;
    }
    // exclude
    subsetHelper(result, nums, index+1, lastIndex, subset);
    
    // include
    subset.push_back(nums[index]);
    subsetHelper(result, nums, index+1, lastIndex, subset);
}   

vector<vector<int>> subsets(vector<int>& nums) {
    int index = 0;
    int lastIndex = nums.size()-1;
    vector<int>subset;
    vector<vector<int>> result;
    subsetHelper(result, nums, index, lastIndex, subset);
    return result;
}

int main(){
    vector<int>nums{2, 8, 6, 10, 20};
    vector<vector<int>>ans = subsets(nums);

    //dummy commit
    for(vector<int> i : ans){
        cout<<"{";
        for(int x: i){
            cout<<x<<", ";
        }
        cout<<"}";
        cout<<endl;
    }
}
