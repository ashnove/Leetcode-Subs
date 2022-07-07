
//------------------BOTTOM-UP------------------\\

// class Solution {
// public:
//     int dp[200][200];
//     bool calc(string &s1, string &s2, string &s3, int n, int i, int j){
//         if(i == 0 && j == 0 && n == 0){
//             return 1;
//         }
//         else if(n == 0){
//             return 0;
//         }
//         if(dp[i][j] != -1) return dp[i][j];
//         int x = 0;
//         if(i - 1 >= 0 && s3[n - 1]==s1[i - 1]) x = calc(s1, s2, s3, n - 1, i - 1, j);
//         if(j - 1 >= 0 && s3[n - 1]==s2[j - 1]) x |= calc(s1, s2, s3, n - 1, i, j - 1);
//         if(x == 1) return dp[i][j] = 1;
//         return dp[i][j] = 0;
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//         memset(dp, -1, sizeof dp);    
//         return calc(s1, s2, s3, s3.size(), s1.size(), s2.size());
//     }
// };

//------------------TOP-BOTTOM------------------\\

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.size();
        int m = s2.size();
        int c = s3.size();
        if(n + m != c) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                };
                int len = i + j;
                if(i == 0){
                    if(s2[j - 1] == s3[len - 1])
                        dp[i][j] = dp[i][j - 1];
                }
                else if(j == 0){
                    if(s1[i - 1] == s3[len - 1])    
                        dp[i][j] = dp[i - 1][j];
                }
                else {
                    int x = 0;
                    if(i > 0 && s3[len - 1] == s1[i - 1]){
                        x |= dp[i - 1][j];
                    }
                    if(j > 0 && s3[len - 1] == s2[j - 1]){
                        x |= dp[i][j - 1];
                    }
                    dp[i][j] = x;
                }
            }
        }
        return dp[n][m];
        
    }
};