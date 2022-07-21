class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        bool dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int j = 2; j <= m; j+=2){
            if(p[j - 1] == '*' && dp[0][j - 2]){
                dp[0][j] = 1; 
            }
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*'){
                    if(p[j - 2] != s[i - 1] && p[j - 2] != '.'){
                        dp[i][j] = dp[i][j - 2];
                    }
                    else {
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 2] || dp[i][j - 2];
                    }
                }
            }
        }
        return dp[n][m];
    }
};