class Solution {
public:
    int f(int idx, vector<int>& cost,vector<int>&dp) {
        if (idx == 0) return cost[0];
        if (idx == 1) return cost[1];
        if (dp[idx] != -1) return dp[idx];
        if (idx == cost.size()) {
            return dp[idx] = min(f(idx - 1, cost,dp), f(idx - 2, cost,dp));
        }

        return dp[idx] = cost[idx] + min(f(idx - 1, cost,dp), f(idx - 2, cost,dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(f(cost.size() - 1, cost,dp), f(cost.size(), cost,dp));
    }
};