class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int numCount = nums.size();
        vector<vector<int>> dp(numCount, vector<int>(2, 1));
        int ans = 0;
        for(int idx = 0; idx < numCount; idx++){
            for(int prev = 0; prev < idx; prev++){
                if(nums[prev] < nums[idx])
                    dp[idx][0] = max(dp[idx][0], 1 + dp[prev][1]);
                if(nums[prev] > nums[idx])
                    dp[idx][1] = max(dp[idx][1], 1 + dp[prev][0]);
            }            
            ans = max({dp[idx][0], dp[idx][1], ans});
        }
        return ans;
    }
};