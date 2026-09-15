class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for(auto it:prices){
            buy = min(buy,it);
            profit = max(profit,it-buy);
        }
        return profit;
    }
};
