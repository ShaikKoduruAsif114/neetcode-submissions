class Solution {
public:

    int f(int idx,vector<int>&nums,vector<int>&dp){
        if(idx==0) return nums[0];
        if(dp[idx]!=-1) return dp[idx];
        int rob = nums[idx];
        if(idx>1) rob = nums[idx] + f(idx-2,nums,dp);
        int unrob = INT_MIN;
        if(idx>0) unrob = f(idx-1,nums,dp);
        return dp[idx] = max(rob,unrob);
    }


    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return f(nums.size()-1,nums,dp);
    }
};
