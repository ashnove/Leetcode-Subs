class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> hash;
        for(int i : nums) {
            if(hash[i]) return 1;
            hash[i]++;
        }
        return 0;
    }
};