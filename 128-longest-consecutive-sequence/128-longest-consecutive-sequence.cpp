class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hash;
        int result = 0;
        for(int num : nums) hash[num]=1;
        for(int num : nums){
            if(!hash[num-1]){
                int size = 0;
                while(hash[num]){
                    num++;
                    size++;
                }
                result = max(result, size);
            }
        }
        return result;
    } 
};