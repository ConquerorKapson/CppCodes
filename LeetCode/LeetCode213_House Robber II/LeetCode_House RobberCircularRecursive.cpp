class Solution {
private:
    int robHelper(vector<int>& nums, int index, int lastIndex, vector<int> dp){
        if(index > lastIndex){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        
        int include = nums[index] + robHelper(nums, index+2, lastIndex, dp);
        int exclude = robHelper(nums, index+1, lastIndex, dp);
        
        dp[index] = max(include, exclude);
        return max(include, exclude);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int lastIndex = n-1;
        vector<int>dp(n, -1);
        int ans1 = nums[0] + robHelper(nums, index+2, lastIndex-1, dp);
        int ans2 = robHelper(nums, index+1, lastIndex, dp);
        
        return max(ans1, ans2);
    }
};