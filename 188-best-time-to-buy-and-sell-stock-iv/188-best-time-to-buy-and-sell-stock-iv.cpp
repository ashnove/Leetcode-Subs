class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> dp(k + 1, 0);
        vector<int> _min(k + 1, INT_MAX);
        for(int i = 0; i < prices.size(); i++){
            for(int kk = 1; kk <= k; kk++){
                _min[kk] = min(_min[kk], prices[i] - dp[kk - 1]);
                dp[kk] = max(dp[kk], prices[i] - _min[kk]);
            }
        }
        return dp[k];
    }
};