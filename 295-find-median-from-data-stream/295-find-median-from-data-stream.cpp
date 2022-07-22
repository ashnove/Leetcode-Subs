class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        if(minHeap.size() < maxHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
    }
    
    double findMedian() {
        int maxHeapSize = maxHeap.size();
        int minHeapSize = minHeap.size();
        if(maxHeapSize == minHeapSize){
            return (double)(maxHeap.top() + minHeap.top()) / 2.0;
        }
        else {
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */