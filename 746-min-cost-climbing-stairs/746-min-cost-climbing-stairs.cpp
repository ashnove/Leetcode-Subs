class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int res = 0;
        cost.push_back(0);
        for(int i = 2; i < cost.size(); i++){
            cost[i] = min(cost[i - 1], cost[i - 2]) + cost[i];
        }
        return cost.back();
    }
};