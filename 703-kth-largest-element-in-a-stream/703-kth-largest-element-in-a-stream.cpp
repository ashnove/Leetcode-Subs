class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int num : nums){
            minHeap.push(num);
        }
        while(minHeap.size() > k){
            minHeap.pop();
        }
        _k = k;
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > _k) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */