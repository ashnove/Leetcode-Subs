class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> nextMax;
        int numLen = nums.size();
        int cur = 0;
        for(int idx = numLen - 1; idx >= 0; idx--){
            cur = (nextMax.empty() ? 0 : nums[nextMax.front()]) + nums[idx];
            while(nextMax.empty() == 0 && cur > nums[nextMax.back()])
                nextMax.pop_back();
            nextMax.push_back(idx);
            while(nextMax.front() >= idx + k){
                nextMax.pop_front();
            }
            nums[idx] = cur;
        }
        return nums[0];
    }
};