class Solution {
public:
    bool equal(int a, int b, int c, int d){
        return (a==b && b==c && c==d && d==a);
    }
    int maxSideLength;
    bool calc(vector<int>& matchsticks, int n, int a, int b, int c, int d){
        if(a > maxSideLength || b > maxSideLength || c > maxSideLength || d > maxSideLength)
            return 0;
        if(n < 0 && (equal(a,b,c,d))){
            return 1;
        }
        if(n < 0) return 0;
        int match = matchsticks[n];
        return calc(matchsticks, n-1, a+match, b, c, d) || calc(matchsticks, n-1, a, b+match, c, d) || calc(matchsticks, n-1, a, b, c+match, d) || calc(matchsticks, n-1, a, b, c, d+match);
        
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = 0;
        for(int match : matchsticks) sum += match;
        maxSideLength = sum / 4;
        if(maxSideLength * 4 != sum) return 0;
        sort(matchsticks.begin(), matchsticks.end());
        return calc(matchsticks, n - 1, 0, 0, 0, 0);
    }
};