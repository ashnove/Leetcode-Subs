class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int numCount = nums.size();
        for(int idx = 0; idx < nums.size() - 1; idx++){
            if(nums[idx] == nums[idx + 1]){
                nums.erase(nums.begin() + idx);
                idx--;
            }
        }
        int ans = min(2, (int)nums.size());
        for(int idx = 1; idx < numCount - 1; idx++){
            ans += ( nums[idx] > nums[idx + 1] && nums[idx] > nums[idx - 1] ) || (nums[idx] < nums[idx+1] && nums[idx] < nums[idx - 1]);
        }
        return ans;
    }
};