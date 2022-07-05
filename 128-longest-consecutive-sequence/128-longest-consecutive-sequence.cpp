class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet;
        int result = 0;
        for(int num : nums) numSet.insert(num);
        for(int num : nums){
            if(numSet.find(num - 1)==numSet.end()){
                int size = 0;
                while(numSet.find(num)!=numSet.end()){
                    num++;
                    size++;
                }
                result = max(result, size);
            }
        }
        return result;
    } 
};