class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int cap = 10000;
        vector<int> hash(2*cap + 1);
        for(int i = 0; i < nums.size(); i++){
            hash[nums[i] + cap]+=1;
        }
        int ans = -1;
        for(int i = 2*cap; i >= 0 && k > 0; i--){
            k-=hash[i];
            ans = i - cap;
        }
        return ans;
    }
};

