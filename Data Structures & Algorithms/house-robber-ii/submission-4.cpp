class Solution {
public:

    int f(int idx,vector<int>&nums,vector<int>&dp){
        if(idx==0) return nums[0];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int unrobbed =f(idx-1,nums,dp);
        int  robbed = nums[idx]+f(idx-2,nums,dp);
        return dp[idx] = max(robbed,unrobbed);
    }
    int robby(int start,int end,vector<int>&nums){
        int len = end-start + 1;
        vector<int>temp(nums.begin()+start,nums.begin()+start+len);
        vector<int>dp(len,-1);
        return f(len-1,temp,dp);
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        int n = nums.size();
        return max(robby(0,n-2,nums),robby(1,n-1,nums));
    }
};
