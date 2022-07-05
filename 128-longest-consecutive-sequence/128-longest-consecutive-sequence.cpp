class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hash;
        int numCount = nums.size();
        int result = 0;
        for(int i = 0; i < numCount; i++) hash[nums[i]]=1;
        for(int i = 0; i < numCount; i++){
            if(!hash[nums[i]-1]){
                int end = nums[i];
                while(hash[end]){
                    end++;
                }
                result = max(result, end-nums[i]);
            }
        }
        return result;
    } 
};