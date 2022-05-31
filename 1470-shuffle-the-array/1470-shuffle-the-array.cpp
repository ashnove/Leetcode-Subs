class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        for(int i = 0; i < n; i++){
            nums[i + n] <<= 10;
            nums[i + n] |= nums[i];
        }
        for(int i = 0, p = 0; i < 2*n; i+=2, p++){
            nums[i] = nums[p + n] & ( (1<<10) - 1);  // keep all 1 in the second half to extract number stored in the second half
            nums[i + 1] = nums[p + n] >> 10;         // get the first half
        }
        return nums;
    }
};