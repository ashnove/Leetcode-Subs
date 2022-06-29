class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        vector<int> dp(n + 1);
        for(int i = 0; i <= n; i++){
            dp[i] = dp[i / 2] + i % 2;
            res.push_back(dp[i]);
        }
        return res;
    }
};