class Solution {
public:
    int jump(vector<int>& nums) {
        int curEnd = 0, jump = 0, maxReach = 0;
        if(nums.size() == 1) return 0;
        for(int i = 0; i < nums.size() - 1; i++){
            maxReach = max(maxReach, i + nums[i]);
            
            if(i == curEnd){
                // cout << i << endl;
                jump++;
                curEnd = maxReach;
            }

        }
        return jump;
    }
};