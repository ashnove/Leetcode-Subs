class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, ans = 0;
        for(int i = 0, j = 0; i < n; i++){
            while(j < n && zero <= 1){
                if(nums[j] == 0) zero++;
                j++;
            }       
            ans = max(ans, j - i - zero - (zero == 0));
            if(nums[i] == 0) zero--;
        }
        return ans;
    }
};