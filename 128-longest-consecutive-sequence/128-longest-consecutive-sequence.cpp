class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(),nums.end());;
        int numCount = nums.size();
        int result = 0;
        for(int i = 0; i < numCount; i++){
            if(hash.find(nums[i]-1)==hash.end()){
                int end = nums[i];
                while(hash.find(end)!=hash.end()){
                    end++;
                }
                result = max(result, end-nums[i]);
            }
        }
        return result;
    } 
};