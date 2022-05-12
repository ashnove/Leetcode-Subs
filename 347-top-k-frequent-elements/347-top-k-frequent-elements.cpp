class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> buckets[nums.size() + 1];
        unordered_map<int,int> hash;
        for(int elems : nums){
            hash[elems]++;
        }
        for(auto elems : hash){
            buckets[elems.second].push_back(elems.first);
        }
        vector<int> ans;
        for(int freq = nums.size(); freq > 0 && ans.size() < k; freq--){
                ans.insert(ans.end(), buckets[freq].begin(), buckets[freq].end());
        }
        ans.resize(k);
        return ans;
    }
};

//using bucket sort