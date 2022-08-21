class Solution {
private:
    long long helper(vector<vector<int>>& questions, int index, int lastIndex, vector<long long>& dp){
        if(index > lastIndex){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        long long include = questions[index][0] + helper(questions, index + questions[index][1]+1, lastIndex, dp);
        long long exclude = helper(questions, index + 1, lastIndex, dp);
        
        dp[index] = max(include, exclude);
        return max(include, exclude);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int index = 0;
        int lastIndex = questions.size()-1;
        vector<long long>dp(questions.size(), -1);
        return helper(questions, index, lastIndex, dp);
    }
};