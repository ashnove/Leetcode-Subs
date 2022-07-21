class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        bool dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int j = 1; j <= m; j++){
            if(p[j - 1] == '*' && dp[0][j - 1]){
                dp[0][j] = 1; 
            }
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};