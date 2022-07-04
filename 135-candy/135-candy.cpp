class Solution {
public:

    int candy(vector<int>& ratings) {
        int total = 0;
        int candyCount = ratings.size();
        vector<int> candies(candyCount, 1);
        for(int i = 1; i < candyCount; i++){
            if(ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;

        }
        total = candies.back();
        for(int i = candyCount - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
            total += candies[i];
        }
        return total;
    }
};