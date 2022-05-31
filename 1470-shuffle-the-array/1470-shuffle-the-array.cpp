class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        for(int i = 0; i < n; i++){
            nums[i + n] <<= 10;
            nums[i + n] |= nums[i];
        }
        int p = 0;
        for(int i = 0; i < 2*n; i+=2, p++){
            int second = nums[p + n] >> 10;
            second <<= 10;
            int first = nums[p + n] ^ second;
            second >>= 10;
            nums[i] = first;
            nums[i + 1] = second;
        }
        return nums;
    }
};