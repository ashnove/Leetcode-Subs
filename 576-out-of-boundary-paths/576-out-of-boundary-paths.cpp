class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove<= 0) return 0;
        
        int MOD = 1000000007;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;
        int result = 0;
        
        int dirs[5] = {1,0,-1,0,1};
        
        for (int step = 0; step < maxMove; step++) {
            vector<vector<int>> temp(m, vector<int>(n, 0));
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    for (int i = 0; i < 4; i++) {
                        int nr = r + dirs[i];
                        int nc = c + dirs[i + 1];
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                            result = (result + dp[r][c]) % MOD;
                        }
                        else {
                            temp[nr][nc] = (temp[nr][nc] + dp[r][c]) % MOD;
                        }
                    }
                }
            }
            dp = temp;
        }
        
        return result;
    }
};