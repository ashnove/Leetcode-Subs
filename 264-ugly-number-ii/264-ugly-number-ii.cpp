class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int two = 1, three = 1, five = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = min({dp[two] * 2, dp[three] * 3,  dp[five] * 5});
            if(dp[i] == dp[two] * 2) two++;
            if(dp[i] == dp[three] * 3) three++;
            if(dp[i] == dp[five] * 5) five++;
        }
        return dp[n];
    }
};

/*
    We maintain three seuences for 2, 3, and 5.
    We set pointers to the first number initially for all three sequence.
    Then we choose the smallest of the three and increase the pointer for the chosen one.
    This also works for the case when two sequence has same number as we bump to each other at the same time
    and increase the pointer for both of them. Note the 'if's, do not use 'else if's there ;)
    
*/