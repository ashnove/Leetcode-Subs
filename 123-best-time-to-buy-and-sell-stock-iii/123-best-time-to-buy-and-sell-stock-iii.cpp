class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int> dp(3, 0);
        vector<int> _min(3, INT_MAX);
        for(int i = 0; i < prices.size(); i++){
            for(int k = 1; k <= 2; k++){
                _min[k] = min(_min[k], prices[i] - dp[k - 1]);
                dp[k] = max(dp[k], prices[i] - _min[k]);
            }
        }
        return dp[2];
    }
};