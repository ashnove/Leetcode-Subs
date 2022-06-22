class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpHold = 0;
        int len =  nums.size();
        for(int i = 0; i < len; i++){
            jumpHold--;
            jumpHold = max(jumpHold, nums[i]);
            if(i < len - 1 && jumpHold == 0) return 0;
            if(i == len - 1) return 1;
        }
        return 1;
    }
};