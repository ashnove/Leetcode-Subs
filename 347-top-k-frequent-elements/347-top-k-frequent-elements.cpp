class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        map<int,int> hash;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
            hash[nums[i]]++;
        for(auto elem : hash)
            maxHeap.push({elem.second, elem.first});
        while(k--){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};