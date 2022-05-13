class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int max_product = nums[0];
        int imax = max_product, imin = max_product;
        for(int i = 1; i < n; i++){
            int num = nums[i];
            int cur_imax, cur_imin;
            cur_imax = max({num, num*imax, num*imin});
            cur_imin = min({num, num*imax, num*imin});
            imax = cur_imax;
            imin = cur_imin;
            max_product = max(max_product, imax);
        }
        return max_product;
    }
};