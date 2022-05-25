class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> hash;
        for(int i = 0; i < (int)nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                hash[nums[i][j]]++;
            }
        }
        vector<int> ans;
        for(auto e : hash){
            if(e.second == nums.size() ){
                ans.push_back(e.first);
            }
        }
        return ans;
    }
};