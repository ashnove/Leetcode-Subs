class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleElem = 0;
        for(int num : nums){
            singleElem ^= num;
        }
        return singleElem;
    }
};