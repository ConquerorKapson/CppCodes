class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        int lastIndex = nums.size()-1;
        vector<int>dp1(nums.size(), -1);
        vector<int>dp2(nums.size(), -1);
        
        //starting from 1st house
        dp1[0] = nums[0];
        dp1[1] = nums[0];
        for(int i = 2 ; i < lastIndex ; i++){
            dp1[i] = max(nums[i]+dp1[i-2], dp1[i-1]);
        }
        
        //starting from 2nd house
        dp2[0] = 0;
        dp2[1] = nums[1];
        for(int i = 2 ; i <= lastIndex ; i++){
            dp2[i] = max(nums[i]+dp2[i-2], dp2[i-1]);
        }
        
        for(int x : dp1){
            cout<<x<<" ";
        }
        cout<<endl;
        for(int x : dp2){
            cout<<x<<" ";
        }
        return max(dp1[lastIndex-1], dp2[lastIndex]);
    }
};