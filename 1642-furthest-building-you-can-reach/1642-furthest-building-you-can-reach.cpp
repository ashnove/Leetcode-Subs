class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> use;
        for(int i = 0; i < heights.size() - 1; i++){
            int bricksNeeded = heights[i + 1] - heights[i];
            if(bricksNeeded > 0)
                use.push(-bricksNeeded);
            if(use.size() > ladders){
                bricks += use.top();
                use.pop();
            }
            if(bricks < 0) return i;
        }
        return heights.size() - 1;
    }
};

/*
    For every i, we maintain a minHeap and see if size > ladders, if yes, we will have only 1 extra height every time and
    climb that height using bricks and update the bricks we have.
    
    We can only get something smaller later which we will cover with bricks and even we have to cover both of them with           bricks.
*/
