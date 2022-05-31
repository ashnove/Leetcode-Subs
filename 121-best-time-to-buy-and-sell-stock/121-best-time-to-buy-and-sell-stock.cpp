class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, profit = 0;
        for(int i = 1; i < prices.size(); i++){
            profit += prices[i] - prices[i - 1];
            if(profit < 0) profit = 0;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};

/*
 *
 *  Buy a stock, when profit goes negative reset the profit, take max of all the profits along the way.
 *
 *
*/