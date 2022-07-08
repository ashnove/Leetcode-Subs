class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
       
        int dp[m + 1][target + 1][n + 1];
        for(int i = 1; i <= m; i++){
            for(int j = 0; j <= n; j++)
                dp[i][0][j] = INT_MAX;
        }
        for(int i = 1; i <= target; i++){
            for(int j = 0; j <= n; j++)
                dp[0][i][j] = INT_MAX;
        }
//         for(int k = 0; k <= m; k++) {
//             for(int i = 1; i <= target; i++){
//                 for(int j = 0; j <= n; j++)
//                     if(i > k)
//                         dp[k][i][j] = INT_MAX;
//             }
//         }
        

        // dp[i][j][k] = Min cost for coloring first i houses, making j neighborhood, by painting ith house with color k;
        
        for(int house = 1; house <= m; house++){
            for(int hood = 1; hood <= target; hood++){

                int colorPainted = houses[house - 1];
                for(int color = 1; color <= n; color++){

                    int colorCost = cost[house - 1][color - 1];
                    dp[house][hood][color] = INT_MAX;
                    if(hood > house) continue;
                    if(house == 1){
                        dp[house][hood][color] = (colorPainted == 0 ? colorCost : (color==colorPainted ? 0 : INT_MAX));
                        continue;
                    }
                    if(colorPainted && color != colorPainted){
                        dp[house][hood][color] = INT_MAX;
                        continue;
                    }
                    for(int prevColor = 1; prevColor <= n; prevColor++){
                        if(colorPainted){
                            if(color == prevColor)
                                dp[house][hood][color] = min(dp[house-1][hood][prevColor], dp[house][hood][color]);
                            else {
                                dp[house][hood][color] = min(dp[house-1][hood - 1][prevColor], dp[house][hood][color]);
                            }
                            continue;
                        }
                        if(color == prevColor ){
                            if(dp[house - 1][hood][color] < INT_MAX)
                                dp[house][hood][color] = min(dp[house][hood][color], dp[house - 1][hood][color] + colorCost);
                        }
                        else if( dp[house - 1][hood - 1][prevColor] < INT_MAX){
                            dp[house][hood][color] = min(dp[house][hood][color], dp[house - 1][hood - 1][prevColor] + colorCost);
                        }
                    }   
                }
            }
        }
        int res = INT_MAX;
        for(int i = 1; i <= n; i++){
            res = min(res, dp[m][target][i]);
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};