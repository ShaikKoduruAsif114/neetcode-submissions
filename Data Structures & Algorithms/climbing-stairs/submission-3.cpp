class Solution {
public:
    int f(int n,vector<int>&dp){
        if(n==1) return dp[1]=1;
        if(n==2) return dp[2]=2;
        if(dp[n]!=-1) return dp[n];
        int left = 0;
        if(n>1){
            left = f(n-1,dp);
        }
        int right = 0;
        if(n>2){
            right = f(n-2,dp);
        }
        return dp[n]=left+right;
    }


    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};
