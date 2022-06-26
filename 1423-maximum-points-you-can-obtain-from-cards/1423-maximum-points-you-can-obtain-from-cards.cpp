class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int N = cardPoints.size();
        cardPoints.insert(cardPoints.begin(), 0);
        for(int i = 1; i <= N; i++){
            cardPoints[i] += cardPoints[i - 1];
        }
        int ans = 0;
        for(int i = 0; i < k + 1; i++){
            int R = k - i;
            ans = max(ans, cardPoints[i] + cardPoints[N] - cardPoints[N - R]);
        }
        return ans;
    }
};